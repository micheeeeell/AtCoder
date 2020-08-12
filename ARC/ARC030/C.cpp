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

template<typename T>
struct edge{
    int f,t;
    T c;
    int id;
    edge(){};
    edge(int f,int t,T c,int id = 0):f(f),t(t),c(c),id(id){};
    bool operator< (const edge &rhs) const {
        return (*this).c < rhs.c;
    }
    bool operator> (const edge &rhs) const {
        return (*this).c > rhs.c;
    }
    friend string to_string(edge<T> e){
        return "(" + to_string(e.f) + ", " + to_string(e.t) + ", " + to_string(e.c) + ")";
    }

};

template<typename T>
struct graph{
    std::vector<std::vector<edge<T> > > data;
    graph(){};
    graph(int v):data(v){};
    void resize(int n){
        data.resize(n);
    }
    void add_edge(edge<T> &e){
        data[e.f].push_back(e);
    }
    void add_edge(int f,int t,T c){
        data[f].emplace_back(f,t,c);
    }
    size_t size(){
        return data.size();
    }
    vector<edge<T>> &operator[](int n){
        return data[n];
    }
    std::vector<edge<T>> make_edges(){
        std::vector<edge<T>> r;
        for(auto &i:data)std::copy(i.begin(),i.end(),std::back_inserter(r));
        return r;
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
    }
    SCC(graph<T> &graph) : g(graph) {
        V = g.size();
        rg.resize(V);
        used.resize(V, 0);
        cmp.resize(V);
        for(int v = 0; v < V; v++) {
            for(auto &e : graph[v]) {
                rg.add_edge(e.t, e.f, e.c);
            }
        }
        build();
    }

    void build() {
        fill(used.begin(), used.end(), 0);
        vs.clear();
        for(int v = 0; v < V; v++) {
            if(!used[v]) dfs(v);
        }
        fill(used.begin(), used.end(), 0);
        ll k = 0;
        for(int i = vs.size() - 1; 0 <= i; i--) {
            if(!used[vs[i]]) rdfs(vs[i], k++);
        }
        dag.resize(k);
        for(int i = 0; i < V; i++) {
            for(auto &e : g[i]) {
                int x = cmp[e.f], y = cmp[e.t];
                if(x == y) continue;
                dag.add_edge(x, y, e.c);
            }
        }
        group.resize(k);
        for(int i = 0; i < g.size(); i++) {
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
        for(auto &e : g[v]) {
            if(!used[e.t]) dfs(e.t);
        }
        vs.emplace_back(v);
    }

    void rdfs(ll v, ll k) {
        used[v] = 1;
        cmp[v] = k;
        for(auto &e : rg[v]) {
            if(!used[e.t]) rdfs(e.t, k);
        }
    }
};
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,m,k; cin >> n >> m >> k;
    vector<string> c(n);
    for(int i = 0; i < n; i++) cin >> c[i];
    graph<ll> g(n);
    rep(i,0,m){
        ll a,b; cin >> a >> b;
        a--;
        b--;
        g.add_edge(a, b, 0);
    }
    SCC scc(g);
    ll N = scc.dag.size();
    debug(N, scc.dag.data);
    vector<string> str(N);
    rep(i,0,N) {
        for(auto &j : scc.group[i]){
            str[i] += c[j];
        }
        sort(all(str[i]));
    }

    debug(str);

    vector<vector<string>> dp(N, vector<string>(n+1));
    vector<ll> in(N);
    rep(i,0,N){
        for(auto &e : scc.dag[i]){
            in[e.t]++;
        }
    }
    debug(in);
    queue<ll> que;
    
    rep(i, 0, N) {
        if(!in[i])que.emplace(i);
    }
    graph<ll> par(N);
    rep(i,0,N){
        for(auto &e : scc.dag[i]){
            debug(e);
            par[e.t].emplace_back(e);
        }
    }
    debug(par.data);
    bool a = "aa" < "";
    bool b = "" > "aa";
    debug(a, b);
    while(!que.empty()) {
        auto t = que.front();
        que.pop();
        for(auto &e : par[t]){
            debug(e);
            rep(i, 0, n + 1) {
                rep(j,0,scc.group[t].size()+1){
                    if(i + j <= n){
                        if(dp[t][i+j] == ""){
                            if(dp[e.f][i].size() == i) {
                                dp[t][i + j] = dp[e.f][i] + str[t].substr(0, j);
                                debug(i + j, dp[t][i + j]);
                            }
                        } else {
                            string s1 = dp[t][i + j],
                                   s2 = dp[e.f][i] + str[t].substr(0, j);
                            if(s2.size() != i + j) continue;
                            debug(i, j, s1, s2, s1 > s2);
                            if(chmin(dp[t][i + j], s2)) {
                                debug(s1, s2);
                            }
                        }
                    }
                }
            }
        }
        rep(i, 0, scc.group[t].size()+1){
            if(dp[t][i] == ""){
                dp[t][i] = str[t].substr(0,i);
            }
            else{
                string s2 = str[t].substr(0, i);
                if(chmin(dp[t][i], s2)) {
                    debug(s2);
                }
            }
        }
        for(auto &e : scc.dag[t]) {
            if(!--in[e.t]) que.emplace(e.t);
        }
    }
    debug(dp);

    string ans, inf(n, 'z');
    ans = inf;
    rep(i, 0, N) {
        if(dp[i][k].size() >= k)chmin(ans, dp[i][k]);
    }

    cout << (ans == inf ? "-1" : ans) << "\n";
}