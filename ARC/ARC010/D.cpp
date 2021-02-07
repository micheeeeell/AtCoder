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
// #define int ll
const long double pi = 3.14159265358979323846;
const long double eps = 1e-12;

template<typename T>
int comp(T a){
    if (abs(a) <= eps) return 0;
    if (a > eps) return 1;
    return -1;
}

template<typename T>
int comp(T a, T b){
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


template<typename T>
struct graph{
    struct edge {
        T t;
    };
    vector<vector<edge>> data;
    ll n;
    graph(){};
    graph(ll n) : n(n), data(n){};

    void add_edge(int f, int t, T c = 0) {
        data[f].emplace_back(edge{t});
    }
    int size(){
        return data.size();
    }
    void resize(int k){
        data.resize(k);
    }
    vector<edge> &operator[](int k){
        return data[k];
    }
};
// 強連結成分分解
template <typename T>
struct SCC {
   public:
    int V;
    graph<T> g;
    // 元のグラフのノードが所属するグループ
    vector<int> cmp;
    // 最終的なdagグラフ
    graph<T> dag;
    // cmpの逆、dagのグループごとにどのノードが入っているか
    vector<vector<int>> group;

    SCC(){};
    SCC(int n) : V(n) {
        g.resize(V);
        rg.resize(V);
        used.resize(V, 0);
        cmp.resize(V);
    };
    SCC(graph<T> &graph) : g(graph) {
        V = g.size();
        rg.resize(V);
        used.resize(V, 0);
        cmp.resize(V);
        for (int v = 0; v < V; v++) {
            for (auto &e : graph[v]) {
                rg.add_edge(e.t, e.f, e.c);
            }
        }
        build();
    }

    void build() {
        fill(used.begin(), used.end(), 0);
        vs.clear();
        for (int v = 0; v < V; v++) {
            if (!used[v]) dfs(v);
        }
        fill(used.begin(), used.end(), 0);
        ll k = 0;
        for (int i = vs.size() - 1; 0 <= i; i--) {
            if (!used[vs[i]]) rdfs(vs[i], k++);
        }
        dag.resize(k);
        for (int i = 0; i < V; i++) {
            for (auto &e : g[i]) {
                int x = cmp[i], y = cmp[e.t];
                if (x == y) continue;
                dag.add_edge(x, y);
            }
        }
        group.resize(k);
        for (int i = 0; i < g.size(); i++) {
            group[cmp[i]].emplace_back(i);
        }
    }

    void add_edge(int f, int t, T c = 0) {
        g.add_edge(f, t, c);
        rg.add_edge(t, f, c);
    }

   private:
    graph<T> rg;
    vector<int> vs, used;

    void dfs(int v) {
        used[v] = 1;
        for (auto &e : g[v]) {
            if (!used[e.t]) dfs(e.t);
        }
        vs.emplace_back(v);
    }

    void rdfs(ll v, ll k) {
        used[v] = 1;
        cmp[v] = k;
        for (auto &e : rg[v]) {
            if (!used[e.t]) rdfs(e.t, k);
        }
    }
};

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    ll b = 1e9;
    vector<Pll> f(n);
    for(auto &[x, y] : f){
        cin >> x >> y;
        x += b;
        y += b;
    }

    ll m; cin >> m;
    vector<Pll> s(m);
    for (auto &[x, y] : s) {
        cin >> x >> y;
        x += b;
        y += b;
    }
    
    vector<ld> near(n, INF);
    if(m <= 1000){
        rep(i,0,n)rep(j,0,m){
            chmin(near[i],
                  hypot((ld)f[i].first - s[j].first, (ld)f[i].second - s[j].second));
        }
    }
    else{
        // atode
        ll r = sqrt(sqrt(m));
        vector table(r + 1, vector(r + 1, vector<Pll>()));
        ll d = b * 2 / r;
        ll dx[] = {0,1,-1,0,1,1,-1,-1, 0};
        ll dy[] = {1,0,0,-1,1,-1,1,-1, 0};
        auto is_out = [&](ll x, ll y){
           if(x < 0 || x >= r + 1 || y < 0 || y >= r + 1)return true;
           return false;
        };
        rep(i,0,m){
            auto [x, y] = s[i];
            table[x / d][y / d].emplace_back(s[i]);
        }

        rep(i,0,n){
            ll x = f[i].first / d;
            ll y = f[i].second / d;
            rep(k,0,9){
                ll nx = x + dx[k], ny = y + dy[k];
                if (is_out(nx, ny)) continue;
                for (auto [sx, sy] : table[nx][ny]) {
                    chmin(near[i],
                          hypot((ld)f[i].first - sx, (ld)f[i].second - sy));
                }
            }

            ll c = 2;
            while(near[i] == INF){
                rep(k,0,8){
                    ll nx = x + dx[k] * c, ny = y + dy[k] * c;
                    if (is_out(nx, ny)) continue;
                    for (auto [sx, sy] : table[nx][ny]) {
                        chmin(near[i],
                              hypot((ld)f[i].first - sx, (ld)f[i].second - sy));
                    }
                }
            }


        }
    }
    debug(near);
    SCC<int> scc(n);
    rep(i, 0, n) rep(j, i + 1, n) {
        ld dist = hypot(f[i].first - f[j].first, f[i].second - f[j].second);

        if (comp(near[i], dist) == 1) {
            scc.add_edge(i, j, 1);
        }
        if (comp(near[j], dist) == 1) {
            scc.add_edge(j, i, 1);
        }
    }
    scc.build();
    vector<ll> in(scc.dag.size());
    ll t = scc.dag.size();
    rep(i, 0, t) {
        for (auto e : scc.dag.data[i]) in[e.t]++;
    }

    ll ans = 0;
    for (auto i : in) {
        if (i == 0) ans++;
    }
    cout << ans << endl;
}