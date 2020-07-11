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
    void add_edge(int f,int t,T c, int id){
        data[f].emplace_back(f,t,c,id);
    }
    size_t size() const {
        return data.size();
    }
    vector<edge<T>> operator[](int n) const {
        return data[n];
    }
    std::vector<edge<T>> make_edges(){
        std::vector<edge<T>> r;
        for(auto &i:data)std::copy(i.begin(),i.end(),std::back_inserter(r));
        return r;
    }
};


// Sparse Table
template<class MeetSemiLattice> struct SparseTable {
    vector<vector<MeetSemiLattice> > dat;
    vector<int> height;
    
    SparseTable() { }
    SparseTable(const vector<MeetSemiLattice> &vec) { init(vec); }
    void init(const vector<MeetSemiLattice> &vec) {
        int n = (int)vec.size(), h = 0;
        while ((1<<h) < n) ++h;
        dat.assign(h, vector<MeetSemiLattice>(1<<h));
        height.assign(n+1, 0);
        for (int i = 2; i <= n; i++) height[i] = height[i>>1]+1;
        for (int i = 0; i < n; ++i) dat[0][i] = vec[i];
        for (int i = 1; i < h; ++i)
            for (int j = 0; j < n; ++j)
                dat[i][j] = min(dat[i-1][j], dat[i-1][min(j+(1<<(i-1)),n-1)]);
    }
    
    MeetSemiLattice get(int a, int b) {
        return min(dat[height[b-a]][a], dat[height[b-a]][b-(1<<height[b-a])]);
    }
};

template< typename Monoid >
struct SegmentTree {

    int sz;
    vector< Monoid > seg;

    const Monoid M1 = 0;
    Monoid f(const Monoid a, const Monoid b){return a + b;};
    SegmentTree(){}
    SegmentTree(const int n){
        init(n);
    }

    void init(const int n){
        sz = 1;
        while(sz < n)sz <<= 1;
        seg.assign(2*sz, M1);
    }

    void set(int k, const Monoid &x) {
        seg[k + sz] = x;
    }

    void build(vector< Monoid > &vec) {
        for(int i = 0; i < vec.size(); i++)set(i, vec[i]);
        for(int k = sz - 1; k > 0; k--) {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }

    void update(int k, const Monoid &x) {
        k += sz;
        seg[k] = x;
        while(k >>= 1) {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }

    Monoid query(int a, int b) {
        Monoid L = M1, R = M1;
        for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if(a & 1) L = f(L, seg[a++]);
            if(b & 1) R = f(seg[--b], R);
        }
        return f(L, R);
    }

    Monoid operator[] (const int &k) const {
        return seg[k + sz];
    }
};

template <typename G, typename T>
struct EulerLCA{
    const G &g;
    vector<pair<int, int>> depth;
    vector<int> id;
    SparseTable< pair<int, int> > ST;
    int root;
    SegmentTree<T> seg;

    vector< vector<Pll> > cl;
    vector<vector<ll>> cl_sum, dis_sum;

    EulerLCA(const G &g, int root = 0): g(g), root(root) {
        int n = g.size();
        id.resize(n);depth.resize(2 * n - 1);
        cl.resize(n);cl_sum.resize(n);dis_sum.resize(n);
        seg.init(2 * n - 1);

        init(n, root);
        debug(depth, id);
        // rep(i,0,2*n-1)cerr << seg[i] << " ";
        debug(cl, cl_sum);
    }

    void dfs(int now, int par, int dep, int &k){
        id[now] = k;
        depth[k++] = {dep, now};
        for(auto &e : g[now]){
            if(e.t == par)continue;
            seg.update(k, e.c);
            cl[e.id].emplace_back(k, e.c);
            dfs(e.t, now, dep+1, k);
            seg.update(k, -e.c);
            cl[e.id].emplace_back(k, -e.c);
            depth[k++] = {dep, now};
        }
    }

    void init(int n, int root = 0){
        int k = 0;
        dfs(root, -1, 0, k);
        ST.init(depth);
        rep(i,0,n){
            cl_sum[i].resize(cl[i].size() + 1);
            dis_sum[i].resize(cl[i].size()+ 1);
            rep(j,0,cl[i].size()){
                cl_sum[i][j + 1] = cl_sum[i][j] + (cl[i][j].second > 0 ? 1 : -1);
                dis_sum[i][j + 1] = dis_sum[i][j] + cl[i][j].second;
            }
        }
    }

    int lca(int u, int v){
        return ST.get(min(id[u], id[v]), max(id[u], id[v]) + 1).second;
    }

    T query(int u, int v){
        int p = lca(u, v);
        return seg.query(id[p] + 1, id[u] + 1) + seg.query(id[p] + 1, id[v] + 1);
    }
};

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,q; cin >> n >> q;
    graph<ll> g(n);
    rep(i,0,n-1){
        ll a,b; cin >> a >> b;
        a--;b--;
        ll c,d; cin >> c >> d;
        g.add_edge(a, b, d, c);
        g.add_edge(b, a, d, c);
    }
    EulerLCA<graph<ll>, ll> elca(g);
    rep(j,0,q){
        ll x,y; cin >> x >> y;
        ll u,v; cin >> u >> v;
        u--;v--;
        ll p = elca.lca(u, v);
        ll dis = elca.query(u, v);
        ll pid = lower_bound(all(elca.cl[x]), (Pll){elca.id[p] + 1, -INF}) - elca.cl[x].begin();
        ll uid = lower_bound(all(elca.cl[x]), (Pll){elca.id[u] + 1, -INF}) - elca.cl[x].begin();
        ll vid = lower_bound(all(elca.cl[x]), (Pll){elca.id[v] + 1, -INF}) - elca.cl[x].begin();
        ll num = elca.cl_sum[x][uid] + elca.cl_sum[x][vid] - 2 * elca.cl_sum[x][pid];
        ll sub_dis = elca.dis_sum[x][uid] + elca.dis_sum[x][vid] - 2 * elca.dis_sum[x][pid];
        debug(pid, uid, vid, num, sub_dis);

        cout << dis - sub_dis + num * y << "\n";
    }
}