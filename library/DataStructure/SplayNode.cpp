#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define rrep(i,x) for(ll i = (ll)(x)-1;0 <= i; i--)
#define reps(i,x) for(ll i = 1; i < (ll)(x)+1; i++)
#define rreps(i,x) for(ll i = (ll)(x); 1 <= i; i--)
#define debug(x) cerr << #x << ": " << (x) << "\n";
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
const ll INF = numeric_limits<ll>::max()/4;
const int n_max = 1e5+10;

// verification: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508
random_device rnd;
mt19937 mt(rnd());
template< typename Monoid, Monoid (*f)(Monoid, Monoid), Monoid (*e)() > 
struct SplayNode {
    using SN = SplayNode<Monoid, f, e>;
    SplayNode *parent, *right, *left;
    int size;
    Monoid value, mono;


    SplayNode() {
        parent = nullptr;
        right = nullptr;
        left = nullptr;
        size = 1;
        value = e();
    }

    void rotate() {
        SplayNode *pp, *p, *c;
        p = this->parent;
        pp = p->parent;

        if(pp && pp->left == p) pp->left = this;
        if(pp && pp->right == p) pp->right = this;
        this->parent = pp;

        if(p->left == this) {
            c = this->right;
            this->right = p;
            p->left = c;
        } else {
            c = this->left;
            this->left = p;
            p->right = c;
        }

        p->parent = this;
        if(c) c->parent = p;

        p->update();
        this->update();
    };

    int state() {
        if(!this->parent) return 0;
        if(this->parent->left == this) return 1;
        if(this->parent->right == this) return 2;
        return 0;
    }
    void splay() {
        while(this->state()) {
            if(this->parent->state() == 0) {
                this->rotate();
            } else if(this->state() == this->parent->state()) {
                this->parent->rotate();
                this->rotate();
            } else {
                this->rotate();
                this->rotate();
            }
        }
    };
    void update() {
        this->size = 1;
        this->mono = this->value;
        if(this->left) {
            this->size += this->left->size;
            this->mono = f(this->mono, this->left->mono);
        }
        if(this->right) {
            this->size += this->right->size;
            this->mono = f(this->mono, this->right->mono);
        }
    };

    friend SN *get(int ind, SN *root) {
        SN *now = root;
        while(true) {
            int lsize = now->left ? now->left->size : 0;
            if(ind < lsize) {
                now = now->left;
            }
            if(ind == lsize) {
                now->splay();
                return now;
            }
            if(ind > lsize) {
                now = now->right;
                ind -= lsize + 1;
            }
        }
    };

    friend pair<SN *, SN *> split(int left_cnt, SN *root) {
        if(left_cnt == 0) return {nullptr, root};
        if(left_cnt == root->size) return {root, nullptr};
        root = get(left_cnt, root);
        SN *lroot, *rroot;
        lroot = root->left;
        rroot = root;

        lroot->parent = nullptr;
        rroot->left = nullptr;
        rroot->update();

        return {lroot, rroot};
    };

    friend SN *merge(SN *lroot, SN *rroot) {
        if(!rroot) return lroot;
        if(!lroot) return rroot;

        rroot = get(0, rroot);
        rroot->left = lroot;
        lroot->parent = rroot;
        rroot->update();
        return rroot;
    };

    friend SN *insert(int ind, SN *node, SN *root) {
        auto p = split(ind, root);
        SN *lroot = p.first;
        SN *rroot = p.second;
        return merge(merge(lroot, node), rroot);
    };

    friend pair<SN *, SN *> remove(int ind, SN *root) {
        root = get(ind, root);
        SN *lroot = root->left;
        SN *rroot = root->right;
        if(lroot) {
            lroot->parent = nullptr;
            root->left = nullptr;
        }
        if(rroot) {
            rroot->parent = nullptr;
            root->right = nullptr;
        }
        root->update();
        return {merge(lroot, rroot), root};
    };

    friend int index_(SN *root) {
        return root->left ? root->left->size : 0;
    }
    friend int size_(SN *root) {
        return root ? root->size : 0;
    }

    // boolはx以上のノードがあるかどうか、ないときはfalse
    // ないときでもresがnullにならないことがあるらしいけどよくわからない
    friend pair<SN *, bool> lower_bound(ll x, SN *root) {
        if(!root) return {root, false};
        SN *cur = nullptr, *nxt = root, *res = nullptr;

        while(nxt) {
            cur = nxt;
            if(cur->value >= x) {
                nxt = cur->left;
                if(!res || cur->value <= res->value) res = cur;
            } else
                nxt = cur->right;
        }
        if(res) res->splay();
        return res ? make_pair(res, true) : make_pair(root, false);
    }

    // boolはxより大きいノードがあるかどうか、ないときはfalse
    friend pair<SN *, bool> upper_bound(ll x, SN *root) {
        if(!root) return {root, false};
        SN *cur = nullptr, *nxt = root, *res = nullptr;
        while(nxt) {
            cur = nxt;
            if(cur->value > x) {
                nxt = cur->left;
                if(!res || cur->value <= res->value) res = cur;
            } else
                nxt = cur->right;
        }
        if(res) res->splay();
        return res ? make_pair(res, true) : make_pair(root, false);
    }

    // 小さい順に並ぶようにinsertする
    // ランダムなポジションにgetすることで平衡に保つ
    friend SN *val_insert(ll x, SN *root) {
        SN *ins = new SN;
        ins->value = x;
        if(!root) return ins;
        ll ind = root->size;
        auto [r, b] = lower_bound(x, root);
        if(b) {
            root = r;
            ind = index_(root);
        }
        root = insert(ind, ins, root);
        return get(mt() % root->size, root);
    }

    // vectorをSplay木に乗せて操作するときのinit
    // vector<SN>のサイズは n+1 以上必要
    friend SN* vector_init(vector<SN> &s, vector<Monoid> &v){
        int n = v.size();
        assert(s.size() > v.size());
        if(n == 0)return nullptr;
        for(int i = 0; i < n; i++){
            s[i].value = v[i];
        }

        SN* root = &s[0];
        for(int i = 0; i < n; i++){
            s[i+1].left = root;
            root->parent = &s[i+1];
            root = &s[i+1];
            root->update();
            root = get(mt() % (i + 1), root);
        }

        return root;
    }
};

template <typename Monoid, Monoid (*f)(Monoid, Monoid), Monoid (*e)()>
using SN = SplayNode<Monoid, f, e>;

ll f(ll a, ll b){
    return min(a, b);
}
ll e(){return INF;}

int main(){
    ll n,q; cin >> n >> q;
    vector<SN<ll, f, e>> vec(n + 1);
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    SplayNode<ll, f, e> *root = vector_init(vec, a);
    rep(i,q){
        ll ord; cin >> ord;
        if(ord == 0){
            ll l,r; cin >> l >> r;
            auto trees = remove(r, root);
            root = insert(l, trees.second, trees.first);
        }
        if(ord == 1){ 
            ll l,r; cin >> l >> r;
            auto trees = split(r+1, root);
            SN<ll, f, e>* rroot = trees.second;
            trees = split(l, trees.first);
            cout << trees.second->mono << "\n";
            root = merge(merge(trees.first, trees.second), rroot);
        }
        if(ord == 2){
            ll pos,val; cin >> pos >> val;
            root = get(pos, root);
            root->value = val;
            root->update();
        }
    }
}