#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include<bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
    vector a(n, vector<ll>(n));

    mcf_graph<ll, ll> g(2 * n + 2);
    ll s = 2 * n, t = s + 1;
    auto id = [&](ll i, ll j, ll k) {
        ll res = 0;
        if(k == 1)res = i;
        if(k == 2)res = n + j;
        return res;
    };
    const ll max = 1e9;
    rep(i,0,n)rep(j,0,n){
        cin >> a[i][j];
        g.add_edge(id(i, j, 1), id(i, j, 2), 1, max-a[i][j]);
    }
    rep(i,0,n){
        g.add_edge(s, id(i, 0, 1), k, 0);
        g.add_edge(id(0, i, 2), t, k, 0);
    }

    g.add_edge(s, t, n*k, max);

    auto [cap, cost] = g.flow(s, t, n*k);
    auto edges = g.edges();
    vector<string> ans(n, string(n, '.'));
    for(auto &e : edges){
        debug(e.from, e.to, e.flow, e.cap, e.cost);
        if(e.from < s && e.to < s && e.flow){
            ll x = e.from;
            ll y = e.to - n;
            ans[x][y]= 'X';
        }
    }
    debug(cap, cost);
    cout << abs(cost - max * cap) << endl;
    print(ans);
}