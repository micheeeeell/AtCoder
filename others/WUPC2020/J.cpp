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
namespace internal {
template <class E>
struct csr {
    std::vector<int> start;
    std::vector<E> elist;
    csr(int n, const std::vector<std::pair<int, E>> &edges)
        : start(n + 1), elist(edges.size()) {
        for(auto e : edges) {
            start[e.first + 1]++;
        }
        for(int i = 1; i <= n; i++) {
            start[i] += start[i - 1];
        }
        auto counter = start;
        for(auto e : edges) {
            elist[counter[e.first]++] = e.second;
        }
    }
};

// Reference:
// R. Tarjan,
// Depth-First Search and Linear Graph Algorithms
struct scc_graph {
   public:
    scc_graph(int n) : _n(n) {
    }

    int num_vertices() {
        return _n;
    }

    void add_edge(int from, int to) {
        edges.push_back({from, {to}});
    }

    // @return pair of (# of scc, scc id)
    std::pair<int, std::vector<int>> scc_ids() {
        auto g = csr<edge>(_n, edges);
        int now_ord = 0, group_num = 0;
        std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);
        visited.reserve(_n);
        auto dfs = [&](auto self, int v) -> void {
            low[v] = ord[v] = now_ord++;
            visited.push_back(v);
            for(int i = g.start[v]; i < g.start[v + 1]; i++) {
                auto to = g.elist[i].to;
                if(ord[to] == -1) {
                    self(self, to);
                    low[v] = std::min(low[v], low[to]);
                } else {
                    low[v] = std::min(low[v], ord[to]);
                }
            }
            if(low[v] == ord[v]) {
                while(true) {
                    int u = visited.back();
                    visited.pop_back();
                    ord[u] = _n;
                    ids[u] = group_num;
                    if(u == v) break;
                }
                group_num++;
            }
        };
        for(int i = 0; i < _n; i++) {
            if(ord[i] == -1) dfs(dfs, i);
        }
        for(auto &x : ids) {
            x = group_num - 1 - x;
        }
        return {group_num, ids};
    }

    std::vector<std::vector<int>> scc() {
        auto ids = scc_ids();
        int group_num = ids.first;
        std::vector<int> counts(group_num);
        for(auto x : ids.second) counts[x]++;
        std::vector<std::vector<int>> groups(ids.first);
        for(int i = 0; i < group_num; i++) {
            groups[i].reserve(counts[i]);
        }
        for(int i = 0; i < _n; i++) {
            groups[ids.second[i]].push_back(i);
        }
        return groups;
    }

   private:
    int _n;
    struct edge {
        int to;
    };
    std::vector<std::pair<int, edge>> edges;
};
};
struct scc_graph {
   public:
    scc_graph() : internal(0) {
    }
    scc_graph(int n) : internal(n) {
    }

    void add_edge(int from, int to) {
        int n = internal.num_vertices();
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        internal.add_edge(from, to);
    }

    std::vector<std::vector<int>> scc() {
        return internal.scc();
    }

   private:
    internal::scc_graph internal;
};

template <typename T>
struct UnionFind {
   private:
    vector<T> par;
    vector<T> rank;
    vector<T> sz;
    int n;

   public:
    // n要素で親を初期化、par[x]はxの親を表す
    UnionFind(int n) : n(n) {
        par.resize(n, 0);
        rank.resize(n, 0);
        sz.resize(n, 1);
        for(int i = 0; i < n; i++) {
            par[i] = i;
        }
    }

    //木の根を求める
    int root(int x) {
        if(par[x] == x)
            return x;
        else
            return par[x] = root(par[x]);
    }

    // xとyの属する集合を併合
    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if(x == y) return;

        if(rank[x] < rank[y]) {
            swap(x, y);
        }

        par[y] = x;
        sz[x] += sz[y];
        if(rank[x] == rank[y]) rank[x]++;
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
        for(int i = 0; i < n; i++) {
            if(!cnt[root(i)]) ans++, cnt[root(i)] = 1;
        }
        return ans;
    }
};

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ifstream in("input.in");
    cin.rdbuf(in.rdbuf());
    ofstream ofstr("out.txt");
    streambuf* strbuf;
    strbuf = std::cout.rdbuf( ofstr.rdbuf() );

    ll n,m; cin >> n >> m;
    scc_graph scc(n);
    vector<Pll> e(m);
    rep(i,0,m){
        ll a,b; cin >> a >> b;
        a--;b--;
        scc.add_edge(a, b);
        e[i] = {a, b};
    }
    auto v = scc.scc();

    ll k = v.size();
    vector<ll> id(n);
    rep(i,0,k){
        for(auto &j : v[i]){
            id[j] = i;
        }
    }
    vvl rg(k);
    rep(i,0,m){
        auto [u, v] = e[i];
        if(id[u] != id[v]){
            rg[id[v]].emplace_back(id[u]);
        }
    }
    UnionFind<ll> uf(k);

    ll pos = id[0];
    auto update = [&](ll now){
        queue<ll> que;
        que.emplace(now);
        while(!que.empty()){
            ll t = que.front(); que.pop();
            for(auto &to : rg[t]){
                if(uf.issame(t, to))continue;
                uf.unite(t, to);
                que.emplace(to);
            }
        }
    };

    update(pos);
    ll q; cin >> q;
    rep(i,0,q){
        ll x,y; cin >> x >> y;
        y--;
        if(x == 1){
            pos = id[y];
            update(pos);
        }
        else{
            if(uf.issame(pos, id[y])){
                cout << "YES" << "\n";
            }
            else{
                cout << "NO" << "\n";
            }
        }
    }
}