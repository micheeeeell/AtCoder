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
const long double eps = 1e-12;

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

template <typename Monoid>
struct SegmentTree {
    using F = function<Monoid(Monoid, Monoid)>;

    int sz, n;
    vector<Monoid> seg;

    const F f;
    const Monoid M1;
    SegmentTree(const int n, const F f, const Monoid &M1) : n(n), f(f), M1(M1) {
        sz = 1;
        while (sz < n) sz <<= 1;
        seg.assign(2 * sz, M1);
    }

    void set(int k, const Monoid &x) {
        seg[k + sz] = x;
    }

    void build(vector<Monoid> &vec) {
        for (int i = 0; i < vec.size(); i++) set(i, vec[i]);
        for (int k = sz - 1; k > 0; k--) {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }

    void update(int k, const Monoid &x) {
        k += sz;
        seg[k] = x;
        while (k >>= 1) {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }

    Monoid query(int a, int b) {
        Monoid L = M1, R = M1;
        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if (a & 1) L = f(L, seg[a++]);
            if (b & 1) R = f(seg[--b], R);
        }
        return f(L, R);
    }

    Monoid operator[](const int &k) const {
        return seg[k + sz];
    }

    template <typename C>
    int find_subtree(int a, const C &check, Monoid &M, bool type) {
        while (a < sz) {
            Monoid nxt =
                type ? f(seg[2 * a + type], M) : f(M, seg[2 * a + type]);
            if (check(nxt))
                a = 2 * a + type;
            else
                M = nxt, a = 2 * a + 1 - type;
        }
        return a - sz;
    }

    template <typename C>
    int find_first(int a, const C &check) {
        Monoid L = M1;
        if (a <= 0) {
            if (check(f(L, seg[1]))) return find_subtree(1, check, L, false);
            return -1;
        }
        int b = sz;
        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if (a & 1) {
                Monoid nxt = f(L, seg[a]);
                if (check(nxt)) return find_subtree(a, check, L, false);
                L = nxt;
                ++a;
            }
        }
        return -1;
    }

    template <typename C>
    int find_last(int b, const C &check) {
        Monoid R = M1;
        if (b >= sz) {
            if (check(f(seg[1], R))) return find_subtree(1, check, R, true);
            return -1;
        }
        int a = sz;
        for (b += sz; a < b; a >>= 1, b >>= 1) {
            if (b & 1) {
                Monoid nxt = f(seg[--b], R);
                if (check(nxt)) return find_subtree(b, check, R, true);
                R = nxt;
            }
        }
        return -1;
    }

    friend string to_string(SegmentTree<Monoid> &seg) {
        string s;
        for (int i = 0; i < seg.n; i++) {
            s += to_string(seg[i]) + " ";
        }
        return s;
    }
};

// HL分解、木を列に落とすことで更新などに強くなる
// 任意のパス上でモノイド演算などができる
template<class T>
struct HLD {
    using F = function<T(T, T)>;
    struct edge {
        int f, t;
        T c;
        edge(){};
        edge(int f, int t, T c) : f(f), t(t), c(c){};
    };

    int n;
    const F f;
    const T M1;
    vector<vector<edge>> data;
    SegmentTree<T> seg;
    vector<int> rt, par, pos, sub, dep;
    vector<T> par_cost;

    HLD(int n, const F f, const T &M1)
        : n(n), f(f), M1(M1), data(n, vector<edge>()), seg(n, f, M1){
        rt.resize(n);
        for (int i = 0; i < n; i++) {
            rt[i] = i;
        }
        pos.assign(n, -1);
        sub.assign(n, 0);
        dep.assign(n, 0);
        par.resize(n);
        par_cost.resize(n);
    };

    void add_edge(int u, int v){
        add_edge(u, v, M1);
    }

    void add_edge(int u, int v, T c){
        data[u].emplace_back(u, v, c);
        data[v].emplace_back(v, u, c);
    }

    // 頂点に重みが設定されている場合 
    void build(int r, vector<T> vec){
        vector<int> a;
        dfs(r);
        vdfs(a, r);
        debug(a);
        vector<T> v(n, M1);
        for (int i = 0; i < n; i++){
            v[i] = vec[a[i]];
        }
        seg.build(v);
    }

    // 辺の重みを使って構築
    void build(int r){
        vector<int> a;
        dfs(r);
        vdfs(a, r);
        debug(a);
        vector<T> v(n, M1);
        for (int i = 0; i < n; i++) {
            v[i] = par_cost[a[i]];
        }
        seg.build(v);
    }

    T query(int u, int v, bool is_edge_weighted = false){
        T res = M1;
        while(root(u) != root(v)){
            if (dep[root(u)] < dep[root(v)]) swap(u, v);
            res = f(res, seg.query(pos[root(u)], pos[u] + 1));
            u = par[root(u)];
        }

        if(!is_edge_weighted)
            res = f(res, seg.query(min(pos[u], pos[v]), max(pos[u], pos[v]) + 1));
        else
            res = f(res, seg.query(min(pos[u], pos[v]) + 1,
                                   max(pos[u], pos[v]) + 1));

        return res;
    }



    void update(int k, T x){
        seg.update(pos[k], x);
    }

    void update(int u, int v, T x){
        if (par[v] != u) swap(u, v);
        seg.update(pos[v], x);
    }

    int root(int k){
        if (rt[k] == k) return k;
        else
            return rt[k] = root(rt[k]);
    }

    private:

    void dfs(int now, int pre = -1, int d = 0){
        Pll p = {0, -1};
        par[now] = pre;
        if (pre == -1) par_cost[now] = M1;
        dep[now] = d;
        for (auto e : data[now]) {
            if (e.t == pre) continue;
            dfs(e.t, now, d + 1);
            sub[now] += sub[e.t];
            par_cost[e.t] = e.c;
            chmax(p, {sub[e.t], e.t});
        }
        sub[now]++;
        if(p.second != -1){
            rt[p.second] = now;
        }
        
    }

    void vdfs(vector<int> &a, int now, int pre = -1){
        pos[now] = a.size();
        a.emplace_back(now);
        int c = -1;
        for (auto e : data[now]) {
            if (e.t == pre) continue;
            if(root(now) == root(e.t)){
                c = e.t;
                break;
            }
        }
        if(c != -1) vdfs(a, c, now);

        for(auto e : data[now]){
            if (e.t == pre || e.t == c) continue;
            vdfs(a, e.t, now);
        }
    }
};


signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n; cin >> n;
    auto f = [](ll a, ll b) { return a + b; };
    HLD<ll> hld(n, f, 0);
    rep(i,0,n-1){
        ll x,y; cin >> x >> y;
        x--;
        y--;
        hld.add_edge(x, y, 1);
    }
    hld.build(0);

    ll q; cin >> q;
    rep(i,0,q){
        ll a,b; cin >> a >> b;
        a--;
        b--;
        cout << hld.query(a, b, true) + 1 << "\n";
    }
}