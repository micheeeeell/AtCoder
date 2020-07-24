#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include<bits/stdc++.h>
using namespace std;
#define rep(i,s,t) for(ll i = (ll)(s); i < (ll)(t); i++)
#define rrep(i,s,t) for(ll i = (ll)(s-1);(ll)(t) <= i; i--)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> Pll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
constexpr ll INF = numeric_limits<ll>::max()/4;
constexpr ll n_max = 2e5+10;
#define int ll

template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string &s) {return '"' + s + '"';}
string to_string(const char *c) {return to_string((string) c);}
string to_string(bool b) {return (b ? "true" : "false");}
template <size_t N>
string to_string(bitset<N> v){
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
string to_string(pair<A, B> p){return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}

void debug_out() {cerr << endl;}
template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}


struct SplayNode {
    SplayNode *parent, *right, *left;
    ll size, value, minimum;

    SplayNode(){
        parent = nullptr;
        right = nullptr;
        left = nullptr;
        size = 1;
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

void print() {
    cout << endl;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
    cout << head;
    if (sizeof...(tail) != 0) cout << " ";
    print(forward<Tail>(tail)...);
}

template <class T>
void print(vector<T> &vec) {
    for (auto& a : vec) {
        cout << a;
        if (&a != &vec.back()) cout << "\n";
    }
    cout << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
    for (auto& vec : df) {
        print(vec);
    }
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,k; cin >> n >> k;
    ll p, r = 1;
    vector<ll> ans;
    vector<SplayNode> vec(n);
    rep(i,0,n-1){
        vec[i+1].left = &vec[i];
        vec[i].parent = &vec[i+1];
        vec[i+1].update();
    }

    rep(i,0,n){
        vec[i].value = i+1;
        vec[i].update();
    }

    SN* root = &vec[n-1];

    while(n){
        p = (n * r - 1) / k;
        r = r * n - p * k;
        root = get(p, root);
        ans.emplace_back(root->value);
        auto tree = remove(p, root);
        root = tree.first;
        n--;
    }

    print(ans);
}