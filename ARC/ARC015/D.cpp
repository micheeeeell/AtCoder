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

template <class Abel>
struct WeightedUnionFind {
    vector<int> par;
    vector<int> rank;
    vector<Abel> diff_weight;
    int n;
    Abel M0;

    WeightedUnionFind(int n, Abel M0 = 0) : n(n), M0(M0) {
        init(n, M0);
    }

    void init(int n, Abel M0 = 0) {
        par.resize(n);
        rank.resize(n);
        diff_weight.resize(n);
        for(int i = 0; i < n; i++) {
            par[i] = i;
            rank[i] = 0;
            diff_weight[i] = M0;
        }
    }

    int root(int x) {
        if(par[x] == x)
            return x;
        else {
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }

    Abel weight(int x) {
        root(x);
        return diff_weight[x];
    }

    // w(x) + w == w(y)となるように併合
    bool unite(int x, int y, Abel &w) {
        w += weight(x) - weight(y);
        x = root(x);
        y = root(y);
        if(x == y) return w == 0;

        if(rank[x] < rank[y]) {
            swap(x, y);
            w = -w;
        }

        par[y] = x;
        diff_weight[y] = w;
        if(rank[x] == rank[y]) rank[x]++;
        return true;
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    Abel diff(int x, int y) {
        return weight(y) - weight(x);
    }
};

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    map<string, ll> mp;
    vector<tuple<string, ll, string>> v(n);
    for(auto &[s, i, t] : v) {
        cin >> s >> i >> t;
        mp[s] = 1;
        mp[t] = 1;
    }
    ll id = 0;
    for(auto &p : mp) {
        p.second = id++;
    }

    WeightedUnionFind<ld> uf(id, 0);
    for(auto &[s, i, t] : v) {
        ll x = mp[s], y = mp[t];
        if(uf.issame(x, y)) continue;
        ld w = log2(i);
        uf.unite(x, y, w);
    }

    ll root = 0, last = 0;
    
    ld max_ = 0, min_ = INF;

    rep(i,0,id){
        if(chmin(min_, uf.weight(i))) root = i;
        if(chmax(max_, uf.weight(i))) last = i;
    }
    string r, l;
    for(auto &p : mp){
        if(p.second == root) r = p.first;
        if(p.second == last) l = p.first;
        debug(p, uf.weight(p.second));
    }
    max_ -= min_;
    ll ans = ll(pow(2, max_) + 0.3);
    cout << "1" + r + "=" << ans << l << "\n";
}