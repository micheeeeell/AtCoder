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

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

template<typename flow_t>
struct FoldFulkerson {
    struct edge {
        int to;
        flow_t cap;
        int rev;
        bool isrev;
        int idx;
    };

    vector<vector<edge>> graph;
    vector<int> used;
    const flow_t INF;
    int timestamp;

    FoldFulkerson(int n) : INF(numeric_limits<flow_t>::max()), timestamp(0) {
        graph.resize(n);
        used.assign(n,-1);
    }

    void add_edge(int from, int to, flow_t cap, int idx = -1) {
        graph[from].emplace_back((edge) {to, cap, (int) graph[to].size(), false, idx});
        graph[to].emplace_back((edge) {from, 0, (int) graph[from].size() - 1, true, idx});
    }

    flow_t dfs(int idx, const int t, flow_t flow) {
        if(idx == t) return flow;
        used[idx] = timestamp;
        for(auto &e : graph[idx]) {
            if(e.cap > 0 && used[e.to] != timestamp) {
                flow_t d = dfs(e.to, t, min(flow, e.cap));
                if(0 < d) {
                    e.cap -= d;
                    graph[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    flow_t max_flow(int s, int t) {
        flow_t flow = 0;
        for(flow_t f; (f = dfs(s,t,INF)) > 0; timestamp++) {
            flow += f;
        }
        return flow;
    }

    void output() {
        for(int i = 0; i < graph.size(); i++) {
            for(auto &e : graph[i]) {
                if(e.isrev) continue;
                auto &rev_e = graph[e.to][e.rev];
                cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << e.cap + rev_e.cap << ")" << endl;
            }
        }
    }
};

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,m; cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    vector<vector<ll>> b(n, vector<ll>(m));
    rep(i,0,n)rep(j,0,m)cin >> a[i][j];
    rep(i,0,n)rep(j,0,m)cin >> b[i][j];
    
    ll dx[] = {0,0,1,-1};
    ll dy[] = {1,-1,0,0};
    auto is_out = [&](ll x, ll y){
       if(x < 0 || x >= n || y < 0 || y >= m)return true;
       return false;
    };
    FoldFulkerson<ll> ff(n * m + 2);
    int s = n * m, t = n * m + 1;
    ll cnt = 0;
    rep(i,0,n)rep(j,0,m){
        if(a[i][j] == b[i][j])continue;
        if(a[i][j] == 0){
            ff.add_edge(s, i * m + j, 1);
        }
        else{
            ff.add_edge(i * m + j, t, 1);
        }
        rep(k,0,4){
            ll nx = i + dx[k], ny = j + dy[k];
            if(is_out(nx, ny))continue;
            if(a[nx][ny] != b[nx][ny] && a[nx][ny] != a[i][j]){
                if(a[i][j] == 0)ff.add_edge(i * m + j, nx * m + ny, 1);
                else ff.add_edge(nx * m + ny, i * m + j, 1);
            }
        }
        ++cnt;
    }

    int flow = ff.max_flow(s, t);
    // ff.output();
    cout << cnt - flow << endl;
}
