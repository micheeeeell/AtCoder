#define LOCAL
#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include<bits/stdc++.h>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define rrep(i,x) for(ll i = (ll)(x)-1;0 <= i; i--)
#define reps(i,x) for(ll i = 1; i < (ll)(x)+1; i++)
#define rreps(i,x) for(ll i = (ll)(x); 1 <= i; i--)
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
string to_string(const char c) {return to_string((string) &c);}
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


struct UnionFind{
private:
    vector<int> par;
    vector<int> rank;
    vector<int> xsz, ysz;

public:
    //n要素で親を初期化、par[x]はxの親を表す
    UnionFind(int n, ll base){
        par.resize(n,0);
        rank.resize(n,0);
        xsz.resize(n,0);
        ysz.resize(n,1);
        fill(xsz.begin(), xsz.begin() + base, 1);
        fill(ysz.begin(), ysz.begin() + base, 0);
        rep(i,n){
            par[i] = i;
        }
    }

    //木の根を求める
    int root(int x){
        if(par[x] == x) return x;
        else return par[x] = root(par[x]);
    }

    //xとyの属する集合を併合
    void unite(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y) return;
        
        if(rank[x] < rank[y]){
            swap(x,y);
        }
        
        par[y] = x;
        xsz[x] += xsz[y];
        ysz[x] += ysz[y];
        if(rank[x] == rank[y]) rank[x]++; 
    }

    //xとyが同じ集合に属するか否か
    bool same(int x, int y){
        return root(x) == root(y);
    }

    //xが属する集合のサイズを返す
    pair<int, int> size(int x){
        return {xsz[root(x)], ysz[root(x)]};
    }

    // 集合の数を返す
    int num_of_s(){
        set<int> st;
        rep(i,par.size()) st.insert(root(i));
        return st.size();
    }
};


signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    ll base = 1e5 + 1;
    UnionFind uf(n_max, base);
    rep(i,n){
        ll x,y; cin >> x >> y;
        uf.unite(x, y + base);
    }
    ll sum = 0;
    rep(i,n_max){
        if(uf.root(i) == i){
            auto p = uf.size(i);
            sum += p.first * p.second;
        }
    }

    cout << sum - n << endl;
}