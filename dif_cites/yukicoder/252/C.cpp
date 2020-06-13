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
constexpr ll n_max = 5e5+10;
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
    vector<edge<T>> operator[](int n){
        return data[n];
    }
    std::vector<edge<T>> make_edges(){
        std::vector<edge<T>> r;
        for(auto &i:data)std::copy(i.begin(),i.end(),std::back_inserter(r));
        return r;
    }
};
template<typename T>
string to_string(edge<T> e){
    return "(" + to_string(e.f) + ", " + to_string(e.t) + ", " + to_string(e.c) + ")";
}

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

// 強連結成分分解
template<typename T>
struct SCC {
    public:
    int V;
    graph<T> g;
    vector<int> cmp;
    graph<T> dag;
    vector<vector<int>> group;

    SCC(){};
    SCC(int n):V(n){
        g.resize(V);
        rg.resize(V);
        used.resize(V, 0);
        cmp.resize(V);
    }
    SCC(graph<T> &graph): g(graph) {
        V = g.size();
        rg.resize(V);
        used.resize(V, 0);
        cmp.resize(V);
        for(int v = 0;v < V; v++) {
            for(auto &e : graph[v]){
                rg.add_edge(e.t, e.f, e.c);
            }
        }
        build();
    }

    void add_edge(int f, int t, T c = 0){
        g.add_edge(f, t, c);
        rg.add_edge(t, f, c);
    }

    void build(){
        fill(used.begin(), used.end(), 0);
        vs.clear();
        for(int v = 0;v < V; v++) {
            if(!used[v]) dfs(v);
        }
        fill(used.begin(), used.end(), 0);
        ll k = 0;
        for(int i = vs.size()-1; 0 <= i; i--) {
            if(!used[vs[i]]) rdfs(vs[i], k++);
        }
        dag.resize(k);
        for(int i = 0; i < V; i++) {
            for(auto &e : g[i]) {
                int x = cmp[e.f], y = cmp[e.t];
                if(x == y)continue;
                dag.add_edge(x, y, e.c);
            }
        }
        group.resize(k);
        for(int i = 0; i < g.size(); i++){
            group[cmp[i]].emplace_back(i);
        }
    }

    private:
    graph<T> rg;
    vector<int> vs, used;

    void dfs(int v){
        used[v] = 1;
        for(auto &e : g[v]) {
            if(!used[e.t]) dfs(e.t);
        }
        vs.emplace_back(v);
    }

    void rdfs(int v, int k) {
        used[v] = 1;
        cmp[v] = k;
        for(auto &e : rg[v]){
            if(!used[e.t]) rdfs(e.t, k);
        }
    }
};

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    vector<ll> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];
    vector<ll> t(n);
    for(int i = 0; i < n; i++) cin >> t[i];
    vector<ll> u(n);
    for(int i = 0; i < n; i++) cin >> u[i];
    rep(i,0,n){
        s[i]--;t[i]--;
    }
    auto node = [&](ll i, ll j, ll k){
        return 2 * (i * n + j) + k;
    };
    auto rev = [&](ll nd, ll* k) -> pair<ll, ll>{
        if(nd & 1){
            *k = 1;
            nd--;
        }
        else{
            *k = 0;
        }
        nd /= 2;
        return {nd / n, nd % n};
    };

    // ll k = 1;
    // debug(rev(10, &k));
    // debug(k);
    graph<ll> g(n*n*2);
    // g.resize(n*n*2);rg.resize(n*n*2);cmp.resize(n*n*2);
    // V = n * n * 2;
    rep(i,0,n)rep(j,0,n){
        ll f1, f2, t1, t2;

        if(u[i] == 0){
            f1 = f2 = 0;
            t1 = t2 = 1;
        }
        if(u[i] == 1){
            f1 = t1 = 1;
            f2 = t2 = 0;
        }
        if(u[i] == 2){
            f1 = t1 = 0;
            f2 = t2 = 1;
        }
        if(u[i] == 3){
            f1 = f2 = 1;
            t1 = t2 = 0;
        }
        // debug(s[i], j, t[i], node(s[i], j, f1), node(j, t[i], t1));
        g.add_edge(node(s[i], j, f1), node(j, t[i], t1), 0);
        g.add_edge(node(j, t[i], f2), node(s[i], j, t2), 0);
    }
    SCC<ll> scc(g);
    // scc.build();
    debug(scc.g.data);
    debug(scc.cmp);
    rep(v,0,n*n){
        if(scc.cmp[v*2] == scc.cmp[v*2 + 1]){
            cout << -1 << endl;
            return 0;
        }
    }

    vector<vector<ll>> ans(n, vector<ll>(n));
    ll k = 0;
    rep(v, 0, n*n){
        if(scc.cmp[v*2] > scc.cmp[v*2 + 1]){
            auto p = rev(v*2, &k);
            ans[p.first][p.second] = k;
        }
        else{
            auto p = rev(v * 2 + 1, &k);
            ans[p.first][p.second] = k;
        }
    }

    for(auto &vec : ans){
        for(auto &t : vec){
            cout << t;
            if(&t != &vec.back()) cout << " ";
            else cout << "\n";
        }
    }
}