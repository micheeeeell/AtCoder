#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, t) for(ll i = (ll)(s); i < (ll)(t); i++)
#define rrep(i, s, t) for(ll i = (ll)(s - 1); (ll)(t) <= i; i--)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> Pll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
constexpr ll INF = numeric_limits<ll>::max() / 4;
constexpr ll n_max = 2e5 + 10;
#define int ll

template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string &s) {
    return '"' + s + '"';
}
string to_string(const char *c) {
    return to_string((string)c);
}
string to_string(bool b) {
    return (b ? "true" : "false");
}
template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for(size_t i = 0; i < N; i++) res += static_cast<char>('0' + v[i]);
    return res;
}
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for(const auto &x : v) {
        if(!first) res += ", ";
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

void debug_out() {
    cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

template <class T>
bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

random_device rnd;
mt19937 mt(rnd());
template <typename Monoid, Monoid (*f)(Monoid, Monoid), Monoid (*e)()>
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
};

template <typename Monoid, Monoid (*f)(Monoid, Monoid), Monoid (*e)()>
using SN = SplayNode<Monoid, f, e>;

ll f(ll a, ll b){return a;}
ll e(){return 0;}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n, t;
    cin >> n >> t;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<ll> sum(n + 1);
    rep(i, 0, n) sum[i + 1] = sum[i] + a[i];
    ll ans = 0;
    SplayNode<ll, f, e> *root = nullptr;
    // debug(sum);
    rep(i, 0, n + 1) {
        auto [r, ok] = upper_bound(sum[i] - t, root);
        // debug(sum[i] - t, ok);
        if(ok){
            root = r;
            ans += i - index_(root);
        }

        root = val_insert(sum[i], root);
    }

    cout << ans << endl;
}