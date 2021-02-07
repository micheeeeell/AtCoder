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

struct PersistentUnionFind {
    int n;
    int cnt = 0;
    using Pii = pair<int, int>;
    vector<int> par;
    vector<int> sz;
    vector<int> rank;
    vector<vector<Pii>> rpar;
    vector<vector<Pii>> rsz;

    PersistentUnionFind(int n): n(n){
        par.resize(n);
        sz.resize(n, 1);
        rank.resize(n);
        rpar.resize(n);
        rsz.resize(n, {Pii{0,1}});
        std::iota(par.begin(), par.end(), 0);
    }

    int root(int x){
        if (par[x] == x) return x;
        else
            return par[x] = root(par[x]);
    }

    int root(int x, int k){
        while(!rpar[x].empty() && rpar[x].back().first <= k){
            x = rpar[x].back().second;
        }
        return x;
    }

    void unite(int x, int y){
        unite(x, y, ++cnt);
    }

    void unite(int x, int y, int k){
        x = root(x);
        y = root(y);
        if (x == y) return;

        if(rank[x] < rank[y]){
            swap(x, y);
        }

        par[y] = x;
        sz[x] += sz[y];
        rpar[y].emplace_back(Pii{k, x});
        rsz[x].emplace_back(Pii{k, sz[x]});
        if (rank[x] == rank[y]) rank[x]++;
    }

    bool issame(int x, int y){
        return root(x) == root(y);
    }

    bool issame(int x, int y, int k){
        return root(x, k) == root(y, k);
    }

    int size(int x){
        return sz[root(x)];
    }

    int size(int x, int k){
        x = root(x, k);
        auto itr = lower_bound(rsz[x].begin(), rsz[x].end(), Pii(k, 0));
        if(itr == rsz[x].end() || itr->first > k){
            itr--;
        }
        return (*itr).second;
    }
};

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    PersistentUnionFind ruf(n);
    ll m; cin >> m;
    rep(i,0,m){
        ll a,b; cin >> a >> b;
        ruf.unite(a, b);
    }
    debug(ruf.rpar, ruf.rsz);
    ll q;
    cin >> q;
    rep(i,0,q){
        ll x,k; cin >> x >> k;
        cout << "root: " << ruf.root(x, k) << endl;
        cout << "size: " << ruf.size(x, k) << endl;
    }
}