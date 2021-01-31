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

template <typename T>
struct UnionFind {
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
    // n要素で親を初期化、par[x]はxの親を表す
    UnionFind(
        int n, F f = [](T a, T b) { return (T)0; }, T M0 = 0)
        : n(n), f(f), M0(M0) {
        par.resize(n, 0);
        rank.resize(n, 0);
        sz.resize(n, 1);
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
        val.resize(n, M0);
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
        val[x] = f(val[x], val[y]);
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

    T get(int x) {
        return val[root(x)];
    }
};

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,m; cin >> n >> m;
    vector<Pll> v(m);
    rep(i,0,m){
        ll a,b; cin >> a >> b;
        a--;
        b--;
        v[i] = {a, b};
    }

    ll q; cin >> q;
    vector<tuple<ll, ll, ll> > que(q);
    for(auto &&[x, y, z] : que){
        cin >> x >> y >> z;
        x--;
        y--;
    }

    vector<ll> ans(q);
    vector memo(m + 1, vector<tuple<ll, ll, ll>>());
    {
        ll x = m / 2;
        rep(i, 0, q) {
            memo[x].emplace_back(make_tuple(-1, m + 1, i));
        }
    }
    while(1){
        bool flag = true;
        UnionFind<ll> uf(n);
        rep(i, 0, m + 1) {
            while(!memo[i].empty()){
                auto &&[mi, ma, id] = memo[i].back();
                memo[i].pop_back();
                auto [x, y, z] = que[id];
                bool ok = true;
                if (uf.issame(x, y)) {
                    ok = uf.size(x) >= z;
                }
                else{
                    ok = uf.size(x) + uf.size(y) >= z;
                }

                if (ok) ma = i;
                else
                    mi = i;
                if(ma - mi > 1){
                    flag = false;
                    memo[(ma + mi) / 2].emplace_back(make_tuple(mi, ma, id));
                }
                else{
                    ans[id] = ma;
                }
            }
            if (i == m) break;
            uf.unite(v[i].first, v[i].second);
        }

        if (flag) break;
    }

    auto print = [](vector<ll> &v) {
        for(auto &i : v){
            cout << i;
            if (&i != &v.back()) cout << "\n";
        }
        cout << "\n";
    };
    auto print2 = [&print](vector<vector<ll>> &v) {
        for (auto x : v) print(x);
    };

    print(ans);
}