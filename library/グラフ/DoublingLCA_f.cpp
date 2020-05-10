#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define pb push_back
#define eb emplace_back
#define debug(x) cerr << #x << ": " << (x) << "\n";
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
const ll INF = LLONG_MAX/4;
const ll MOD = 1e9+7;
const int n_max = 1e5+10;
#define int ll

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
    graph(int v):data(v){};
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

// DoublingによりLowest Common Ancestor(最小共通祖先)を求める
// うしさんのライブラリです
// G はglaphの型, vector< vector<int> >など
// 検証：ABC014_D 木のノード間距離を求める問題
// 木の辺上のコストに対して、u,v間の単純パス上のコストに対するクエリO(logN)で答える
// 構築O(NlogN)、クエリO(logN)
// 辺にコストがある前提なので、graph<Monoid>を推奨、node上のコストについて考えるときは少し工夫すればできそう（多分）
// セグ木と違い、途中で更新が入る場合は構築し直しなので使えない
template<typename G, typename Monoid >
struct DoublingLCA {
    using F = function< Monoid(Monoid, Monoid) >;

    const F f;
    const Monoid M1;
    const int LOG;
    vector<int> dep;
    const G &g;
    vector<vector<int>> table;
    vector<vector<Monoid>> data;

    DoublingLCA(const G &g, const size_t n, const F f, const Monoid &M1) : g(g), dep(n), LOG(32 - __builtin_clz(n)), f(f), M1(M1) {
        table.assign(LOG, vector<int>(n, -1));
        data.assign(LOG, vector<Monoid>(n, M1));
        build();
    }

    void dfs(int idx, int par, int d) {
        table[0][idx] = par;
        dep[idx] = d;
        for(auto &to : g.data[idx]) {
            if(to.t != par){
                dfs(to.t, idx, d+1);
                data[0][to.t] = f(data[0][to.t], to.c);
            }
        }
    }

    void build() {
        dfs(0,-1,0);
        for(int k = 0; k+1 < LOG; k++) {
            for(int i = 0;i < table[k].size(); i++) {
                if(table[k][i] == -1){
                    table[k+1][i] = -1;
                }
                else {
                    table[k+1][i] = table[k][table[k][i]];
                    data[k+1][i] = f(data[k][i], data[k][table[k][i]]);
                }
            }
        }
    }

    int lca(int u, int v) {
        if(dep[u] > dep[v])swap(u,v);
        for(int i = LOG - 1; 0 <= i; i--) {
            if(((dep[v] - dep[u]) >> i) & 1) v = table[i][v];
        }
        if(u == v) return u;
        for(int i = LOG - 1; 0 <= i; i--) {
            if(table[i][u] != table[i][v]) {
                u = table[i][u];
                v = table[i][v];
            }
        }
        return table[0][u];
    }

    
    ll query(ll u, ll v){
        int p = lca(u,v);
        ll l_d = dep[u] - dep[p], r_d = dep[v] - dep[p];
        // print(u, v, l_d, r_d);
        ll left = M1, right = M1;
        for(int i = LOG - 1; 0 <= i; i--){
            if((l_d >> i) & 1){
                left = f(left, data[i][u]);
                u = table[i][u];
            }
            if((r_d >> i) & 1){
                right = f(right, data[i][v]);
                v = table[i][v];
            }
        }

        return f(left, right);
    }
};

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,m; cin >> n >> m;
    graph<ll> tree(n);
    vector<edge<ll>> v(m);
    vector<edge<ll>> v2(m);
    UnionFind uf(n);
    rep(i,m){
        ll f,t,c; cin >> f >> t >> c;
        f--;t--;
        v[i] = {f, t, c};
        v2[i] = {f,t,c};
    }
    sort(all(v));
    ll sum = 0;
    rep(i,m){
        auto e = v[i];
        if(uf.same(e.f, e.t))continue;
        tree.add_edge(e.f, e.t, e.c);
        tree.add_edge(e.t, e.f, e.c);
        sum += e.c;
        uf.unite(e.f, e.t);
    }
    auto f = [](ll a, ll b){return max(a, b);};
    DoublingLCA<graph<ll>, ll> lca(tree, tree.size(), f, 0);
    // print(lca.data);
    rep(i,m){
        auto e = v2[i];
        ll ma = lca.query(e.f, e.t);
        // print(e.f, e.t);debug(ma);
        cout << sum - ma + e.c << "\n";
    }
}