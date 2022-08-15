#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
// #include<atcoder/all>
// using namespace atcoder;
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
const long double pi = 3.14159265358979323846;
const long double eps = 1e-12;

template <typename T>
int comp(T a){
    if (abs(a) < eps) return 0;
    return a > 0 ? 1 : -1;
}

template <typename T>
int comp(T a, T b){
    // a > b -> 1, a < b -> -1
    return comp(a - b);
}

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

template< typename T>
struct UnionFind{
    using F = function<T(T, T)>;

   private:
    vector<int> par;
    vector<int> rank;
    vector<int> sz;
    vector<T> val;
    F f;
    T M0;
    int n;

   public:
    //n要素で親を初期化、par[x]はxの親を表す
    UnionFind(int n, F f = [](T a, T b) { return (T)0; }, T M0 = 0)
        : n(n), f(f), M0(M0) {
        par.resize(n,0);
        rank.resize(n,0);
        sz.resize(n,1);
        for(int i = 0; i < n; i++){
            par[i] = i;
        }
        val.resize(n, M0);
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
        sz[x] += sz[y];
        val[x] = f(val[x], val[y]);
        if (rank[x] == rank[y]) rank[x]++;
    }

    //xとyが同じ集合に属するか否か
    bool issame(int x, int y){
        return root(x) == root(y);
    }

    //xが属する集合のサイズを返す
    int size(int x){
        return sz[root(x)];
    }

    // 集合の数を返す
    int num_of_s(){
        vector<int> cnt(n);
        int ans = 0;
        for(int i = 0; i < n;i++){
            if(!cnt[root(i)])ans++, cnt[root(i)] = 1;
        }
        return ans;
    }

    T get(int x){
        return val[root(x)];
    }
};

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll h,w; cin >> h >> w;
    vector<string> s(h);
    rep(i, 0, h) cin >> s[i];
    UnionFind<ll> row(h), col(w);
    row.unite(0, h - 1);
    col.unite(0, w - 1);
    rep(i,0,h){
        vector<ll> v;
        if (i == 0 || i == h - 1) v.emplace_back(0);
        rep(j, 0, w) {
            if (s[i][j] == '#') v.emplace_back(j);
        }
        ll m = v.size();
        rep(j, 1, m){
            col.unite(v[j - 1], v[j]);
        }
    }

    rep(j,0,w){
        vector<ll> v;
        if (j == 0 || j == w - 1) v.emplace_back(0);
        rep(i, 0, h) {
            if (s[i][j] == '#') v.emplace_back(i);
        }

        ll m = v.size();
        rep(i, 1, m){
            row.unite(v[i - 1], v[i]);
        }
    }

    ll ans = INF;
    {
        ll tmp = 0;
        rep(i, 0, h) {
            if (row.issame(0, i)) continue;
            tmp++;
            row.unite(0, i);
        }
        chmin(ans, tmp);
    }
    {
        ll tmp = 0;
        rep(j, 0, w) {
            if (col.issame(0, j)) continue;
            tmp++;
            col.unite(0, j);
        }
        chmin(ans, tmp);
    }
    cout << ans << endl;
}