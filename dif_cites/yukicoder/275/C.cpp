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
const long double pi = 3.14159265358979323846;
const long double eps = 1e-12;

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

template <typename T>
struct UnionFind {
   private:
    vector<T> par;
    vector<T> rank;
    vector<T> sz;
    int n;

   public:
    // n要素で親を初期化、par[x]はxの親を表す
    UnionFind(int n) : n(n) {
        par.resize(n, 0);
        rank.resize(n, 0);
        sz.resize(n, 1);
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }

    //木の根を求める
    int root(int x) {
        if (par[x] == x)
            return x;
        else
            return par[x] = root(par[x]);
    }

    // xとyの属する集合を併合
    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;

        if (rank[x] < rank[y]) {
            swap(x, y);
        }

        par[y] = x;
        sz[x] += sz[y];
        if (rank[x] == rank[y]) rank[x]++;
    }

    // xとyが同じ集合に属するか否か
    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    // xが属する集合のサイズを返す
    int size(int x) {
        return sz[root(x)];
    }

    // 集合の数を返す
    int num_of_s() {
        vector<int> cnt(n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!cnt[root(i)]) ans++, cnt[root(i)] = 1;
        }
        return ans;
    }

    vector<int> get_sz(){
        return sz;
    }
};

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    UnionFind<ll> D(n), W(n);
    ll d,w; cin >> d >> w;
    rep(i,0,d){
        ll u,v; cin >> u >> v;
        u--;
        v--;
        D.unite(u, v);
    }
    rep(i,0,w){
        ll u,v; cin >> u >> v;
        u--;
        v--;
        W.unite(u, v);
    }
    vector<set<ll>> S(n);
    rep(i,0,n){
        S[D.root(i)].insert(W.root(i));
    }

    vector<ll> cnt(n);
    rep(i,0,n){
        for(auto &j : S[i]){
            cnt[i] += W.size(j);
        }
    }

    ll ans = 0;
    rep(i, 0, n) ans += cnt[D.root(i)];
    ans -= n;
    cout << ans << endl;
}