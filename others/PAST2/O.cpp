#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define rrep(i,x) for(ll i = (ll)(x)-1;0 <= i; i--)
#define reps(i,x) for(ll i = 1; i < (ll)(x)+1; i++)
#define rreps(i,x) for(ll i = (ll)(x); 1 <= i; i--)
#define debug(x) cerr << #x << ": " << (x) << "\n";
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
const ll INF = numeric_limits<ll>::max()/4;
const int n_max = 1e5+10;
#define int ll

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
void print(vector<T> &vec, ll k){
   ll n = vec.size();
   k = min(k, n);
   rep(i,k-1)cout << vec[i] << " ";
   cout << vec[k-1] << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
    for (auto& vec : df) {
        print(vec);
    }
}

template<class T, class U>
void print(pair<T,U> &p){
    cout << p.first << " " << p.second << "\n";
}

struct UnionFind{
private:
    vector<int> par;
    vector<int> rank;
    vector<int> sz;

public:
    //n要素で親を初期化、par[x]はxの親を表す
    UnionFind(int n){
        par.resize(n,0);
        rank.resize(n,0);
        sz.resize(n,1);
        rep(i,n){
            par[i] = i;
        }
    }

    //木の根を求める
    int root(int x){
        if(par[x] == x) return x;
        else return par[x] = root(par[x]);
    }

    //xとyの属する集合を併合
    void unite(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y) return;
        
        if(rank[x] < rank[y]){
            swap(x,y);
        }
        
        par[y] = x;
        sz[x] += sz[y];
        if(rank[x] == rank[y]) rank[x]++; 
    }

    //xとyが同じ集合に属するか否か
    bool same(int x, int y){
        return root(x) == root(y);
    }

    //xが属する集合のサイズを返す
    int size(int x){
        return sz[root(x)];
    }

    // 集合の数を返す
    int num_of_s(){
        set<int> st;
        rep(i,par.size()) st.insert(root(i));
        return st.size();
    }
};

template<typename G >
struct DoublingLCA {
    const int LOG;
    vector<int> dep;
    const G &g;
    vector<vector<int>> table;
    vector<vector<ll>> data;

    DoublingLCA(const G &g, size_t n) : g(g), dep(n), LOG(32 - __builtin_clz(n)) {
        table.assign(LOG, vector<int>(n, -1));
        data.assign(LOG, vector<int>(n, -1));
        build();
    }

    void dfs(int idx, int par, int d) {
        table[0][idx] = par;
        dep[idx] = d;
        for(auto &to : g.data[idx]) {
            if(to.t != par){
                dfs(to.t, idx, d+1);
                data[0][to.t] = to.c;
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
                    data[k+1][i] = max(data[k][i], data[k][table[k][i]]);
                }
            }
        }
    }

    int query(int u, int v) {
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

    ll function_qury(ll u, ll v){
        int p = query(u,v);
        ll l_d = dep[u] - dep[p], r_d = dep[v] - dep[p];
        // print(u, v, l_d, r_d);
        ll left = 0, right = 0;
        for(int i = LOG - 1; 0 <= i; i--){
            if((l_d >> i) & 1){
                left = max(left, data[i][u]);
                u = table[i][u];
            }
            if((r_d >> i) & 1){
                right = max(right, data[i][v]);
                v = table[i][v];
            }
        }

        return max(left, right);
    }

};

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
    DoublingLCA<graph<ll>> lca(tree, tree.size());
    // print(lca.data);
    rep(i,m){
        auto e = v2[i];
        ll ma = lca.function_qury(e.f, e.t);
        // print(e.f, e.t);debug(ma);
        cout << sum - ma + e.c << "\n";
    }
}