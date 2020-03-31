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

struct SplayNode {
    SplayNode *parent, *right, *left;
    ll size, value, minimum;

    SplayNode(){
        parent = nullptr;
        right = nullptr;
        left = nullptr;
        size = 1;
    }

    void print(){
        cout << "parent :" <<(parent ? parent->value : -1) << endl;
        cout << "right  :" <<(right ? right->value : -1) << endl;
        cout << "left   :" << (left ? left->value : -1) << endl;
        cout << "size   :" << size << endl;
        cout << "value  :" << value << endl;
        cout << endl;
    }

    void rotate(){
        SplayNode *pp, *p, *c;
        p = this->parent;
        pp = p->parent;

        if(pp && pp->left == p)pp->left = this;
        if(pp && pp->right == p) pp->right = this;
        this->parent = pp;

        if(p->left == this) {
            c = this->right;
            this->right = p;
            p->left = c;
        }
        else {
            c = this->left;
            this->left = p;
            p->right = c;
        }
        
        p->parent = this;
        if(c) c->parent = p;

        p->update();
        this->update();
    };

    int state(){
        if(!this->parent)return 0;
        if(this->parent->left == this)return 1;
        if(this->parent->right == this)return 2;
        return 0;
    }
    void splay(){
        while(this->state()){
            if(this->parent->state() == 0){
                this->rotate();
            }
            else if(this->state() == this->parent->state()){
                this->parent->rotate();
                this->rotate();
            }
            else{
                this->rotate();
                this->rotate();
            }
        }
    };
    void update(){
        this->size = 1;
        this->minimum = this->value;
        if(this->left){
            this->size += this->left->size;
            this->minimum = min(this->minimum, this->left->minimum);
        }
        if(this->right){
            this->size += this->right->size;
            this->minimum = min(this->minimum, this->right->minimum);
        }
    };
    
    
};

using SN = SplayNode;

SplayNode* get(int ind, SplayNode *root){
    SplayNode *now = root;
    while(true){
        int lsize = now->left ? now->left->size : 0;
        if(ind < lsize){
            now = now->left;
        }
        if(ind == lsize){
            now->splay();
            return now;
        }
        if(ind > lsize){
            now = now->right;
            ind -= lsize + 1;
        }
    }
};

pair<SN*, SN*> split(int left_cnt, SN *root){
    if(left_cnt == 0)return {nullptr, root};
    if(left_cnt == root->size)return {root, nullptr};
    root = get(left_cnt, root);
    SN *lroot, *rroot;
    lroot = root->left;
    rroot = root;

    lroot->parent = nullptr;
    rroot->left = nullptr;
    rroot->update();

    return {lroot, rroot};
};

SN* merge(SN *lroot, SN *rroot){
    if(!rroot)return lroot;
    if(!lroot)return rroot;

    rroot = get(0,rroot);
    rroot->left = lroot;
    lroot->parent = rroot;
    rroot->update();
    return rroot;
};

SN* insert(int ind, SN *node, SN* root){
    auto p = split(ind, root);
    SN *lroot = p.first;
    SN *rroot = p.second;
    return merge(merge(lroot, node), rroot);
};

pair<SN*, SN*> remove(int ind, SN *root){
    root = get(ind, root);
    SN *lroot = root->left;
    SN *rroot = root->right;
    if(lroot){
        lroot->parent = nullptr;
        root->left = nullptr;
    }
    if(rroot){
        rroot->parent = nullptr;
        root->right = nullptr;
    }
    root->update();
    return {merge(lroot, rroot), root};
};

pair<SN*, int> search(ll x, SN* root){
    ll ok = -1, ng = root->size;
    // debug("search");
    // root->print();
    while(abs(ok - ng) > 1){
        ll id = (ok + ng) / 2;
        root = get(id, root);
        if(root->value <= x)ok = id;
        else ng = id;
    }
    return {root, ok + 1};
};

SN* val_insert(ll x, SN* root){
    SN* ins = new SN;
    ins->value = x;
    if(!root)return ins;
    auto p = search(x, root);
    root = p.first;
    ll id = p.second;
    // debug(id);
    // root->print();
    
    return insert(id, ins, root);
};

SN* vinsert(ll x, SN* root){
    SN* ins = new SN;
    ins->value = x;
    if(!root)return ins;
    SN *cur = nullptr, *nxt = root; 
    while(nxt){
        cur = nxt;
        if(cur->value > x) nxt = cur->left;
        else nxt = cur->right;
    }
    if(cur->value > x) cur->left = ins, ins->parent = cur;
    else cur->right = ins, ins->parent = cur;
    cur->update();
    ins->splay();
    return ins;
}

int main(){
    ll q; cin >> q;
    SN* root = nullptr;
    // debug(root->value);debug(root->size);
    rep(i,q){
        ll t,x; cin >> t >> x;
        if(t == 1){
            root = val_insert(x, root);
        }
        else{
            root = get(x - 1, root);
            cout << root->value << "\n";
            auto trees = remove(x-1, root);
            root = trees.first;
        }
        // debug(root->size);
        // ll n = root->size;
        // rep(j,n){
        //     root = get(j,root);
        //     root->print();
        // }
    }  
}