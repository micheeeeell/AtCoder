// #define _GLIBCXX_DEBUG
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

// template <class T>
// void print(vector<T> &vec, ll k){
//    ll n = vec.size();
//    k = min(k, n);
//    rep(i,k-1)cout << vec[i] << " ";
//    cout << vec[k-1] << endl;
// }

template <class T>
void print(vector<vector<T>> &df) {
    for (auto& vec : df) {
        print(vec);
    }
}

template<class T, class U>
void print(pair<T,U> &p){
    print(p.first, p.second);
}

//頂点fromから頂点toへのコストcostの辺
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

bitset<n_max> used(0);
template<typename T>
vector<edge<T>> prim(graph<T> &g, ll root){
    ll n = g.size();
    priority_queue< edge<T>, vector<edge<T>>, greater<edge<T>> > pq;
    for(auto &e : g.data[root]){
        pq.emplace(e);
    }
    used[root] = 1;
    vector<edge<T>> ret;
    // debug(used.count());
    while(!pq.empty() && used.count() < n){
        auto e = pq.top();pq.pop();
        if(used[e.t])continue;
        assert(used[e.f]);
        used[e.t] = 1;
        ret.emplace_back(e);
        for(auto &ed : g.data[e.t]){
            if(used[ed.t])continue;
            pq.emplace(ed);
        }
    }
    return ret;
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

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,m; cin >> n >> m;
    graph<ll> g(n+1);
    rep(i,n){
        ll c; cin >> c;
        g.add_edge(0, i+1, c);
        g.add_edge(i+1, 0, c);
    }
    rep(i,m){
        ll f,t,c; cin >> f >> t >> c;
        g.add_edge(f,t,c);
        g.add_edge(t,f,c);
    }

    auto edges = g.make_edges();
    // sort(all(edges), [](const auto &a, const auto &b){
    //     return a.c < b.c;
    // });

    // // クラシカル法
    // sort(all(edges));
    // UnionFind uf(n+1);
    // ll ans = 0;
    // for(auto &e : edges){
    //     if(uf.same(e.f, e.t))continue;
    //     ans += e.c;
    //     uf.unite(e.f, e.t);
    // }

    // cout << ans << endl;

    // プリム法
    auto pr = prim(g, 0);
    ll ans = 0;
    for(auto &e : pr){
        // print(e.f, e.t, e.c);
        ans += e.c;
    }

    cout << ans << endl;
}