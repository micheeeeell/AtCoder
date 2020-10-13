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
        if (&a != &vec.back()) cout << " ";
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
    ll n; cin >> n;
    vector g(n, vector<ll>());
    map<Pll, ll> mp;
    vector<ll> in(n);

    rep(i, 0, n) {
        ll u,v; cin >> u >> v;
        u--;
        v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        if (u > v) swap(u, v);
        if(mp.count({u, v})){
            cout << 2 << endl;
            cout << mp[{u, v}] << " " << i + 1 << endl;
            return 0;
        }
        mp[{u, v}] = i + 1;
        in[u]++;
        in[v]++;
    }

    vector<ll> used(n);
    queue<ll> que;
    rep(i, 0, n) if (in[i] == 1) {
        used[i] = 1;
        que.emplace(i);
    }
    while (!que.empty()){
        ll t = que.front();
        que.pop();
        debug(t);
        in[t] = 0;
        for (auto &to :g[t]){
            if (used[to]) continue;
            in[to]--;
            if(in[to] == 1){
                que.emplace(to);
                used[to] = 1;
            }
        }
    }

    debug(used);
    vector<ll> ans, path;
    auto dfs = [&](auto self, ll now, ll pre = -1) -> void {
        used[now] = 1;
        path.emplace_back(now);
        for (auto &to : g[now]) {
            if (to == pre) continue;
            if (used[to]) continue;
            ans.emplace_back(mp[Pll(min(now, to), max(now, to))]);
            self(self, to, now);
        }
    };
    rep(i,0,n)if(!used[i])dfs(dfs, i);
    debug(ans, path);

    ll u = path[0], v = path.back();
    if (u > v) swap(u, v);
    ans.emplace_back(mp[{u, v}]);

    cout << ans.size() << "\n";
    print(ans);
}