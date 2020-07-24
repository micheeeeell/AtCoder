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

// 有向グラフ上のトポロジカルソート
vector<ll> topo_sort(vvl &graph, vector<ll> &used){
    queue<ll> que;
    vector<ll> ans;
    ll v = graph.size();
    vector<ll> in(v);
    for(auto &vec : graph){
        for(auto &to : vec)in[to]++;
    }

    // rep(i,0,v){
    //     if(!used[i])continue;
    //     for(auto &to : graph[i])in[to]--;
    // }
    rep(i,0,v)if(in[i] == 0){
        que.emplace(i);
        ans.emplace_back(i);
    }
    while(!que.empty()) {
        auto f = que.front();que.pop();
        for(auto &to : graph[f]) {
            in[to]--;
            if(used[to])continue;
            if(!in[to]) {
                ans.emplace_back(to);
                que.emplace(to);
            }
        }
    }

    return ans;
};

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    ll m; cin >> m;
    vector<vector<ll>> graph(n);
    for(int i = 0; i < m; i++) {
        ll a,b;cin >> a >> b;
        a--;b--;
        graph[b].emplace_back(a);
    }
    vector<Pll> b;
    ll k; cin >> k;
    rep(i,0,k){
        ll f,t; cin >> f >> t;
        f--;t--;
        b.emplace_back(f, t);
    }
    ll ans = 0;
    vector<ll> used(n);
    rep(i,0,1LL << k){
        rep(j,0,k){
            auto &[f, t] = b[j];
            if((i >> j) & 1){
                graph[f].emplace_back(t);
            }
            else{
                used[f] = 1;
            }
        }
        auto p = topo_sort(graph, used);
        chmax(ans, (ll)p.size());
        rep(j,0,k){
            auto &[f, t] = b[j];
            if((i >> j) & 1){
                graph[f].pop_back();
            }
            else{
                used[f] = 0;
            }
        }
    }

    cout << ans << "\n";
}