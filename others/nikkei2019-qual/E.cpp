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

template< typename T>
struct UnionFind{
private:
    vector<T> par;
    vector<T> rank;
    vector<T> sz;
    vector<T> val;
    int n;

public:
    //n要素で親を初期化、par[x]はxの親を表す
    UnionFind(int n): n(n) {
        par.resize(n,0);
        rank.resize(n,0);
        sz.resize(n,1);
        val.resize(n);
        for(int i = 0; i < n; i++){
            par[i] = i;
        }
    }

    void init(vector<T> &v){
        val = v;
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
        val[x] += val[y];
        if(rank[x] == rank[y]) rank[x]++; 
    }

    //xとyが同じ集合に属するか否か
    bool issame(int x, int y){
        return root(x) == root(y);
    }

    //xが属する集合のサイズを返す
    int size(int x){
        return sz[root(x)];
    }

    T get_val(int x){
        return val[root(x)];
    }

    // 集合の数を返す
    int num_of_s(){
        vector<int> cnt(n);
        int ans = 0;
        for(int i = 0; i < n;i++){
            if(!cnt[root(i)])ans++, cnt[root(i)] = 1;
        }
        return ans;
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
    friend string to_string(edge<T> e){
        return "(" + to_string(e.f) + ", " + to_string(e.t) + ", " + to_string(e.c) + ", " + to_string(e.id) + ")";
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
    void add_edge(int f,int t,T c,int id){
        data[f].emplace_back(f,t,c,id);
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
    vector<ll> x(n);
    for(int i = 0; i < n; i++) cin >> x[i];
    graph<ll> g(n);
    vector<edge<ll>> edges(m);
    rep(i,0,m){
        ll a,b,y; cin >> a >> b >> y;
        a--;b--;
        edges[i] = {a, b, y, i};
    }
    sort(all(edges));
    UnionFind<ll> uf(n);
    uf.init(x);
    ll cnt = 0;
    vector<ll> canbe(m);
    rep(i,0,m){
        auto &[a, b, y, id] = edges[i];
        id = i;
        g.add_edge(edges[i]);
        g.add_edge(b,a,y,i);
        if(uf.issame(a, b)){
            if(uf.get_val(a) >= y)canbe[i] = 1;
        }
        else{
            if(uf.get_val(a) + uf.get_val(b) >= y){
                canbe[i] = 1;
            }
            uf.unite(a, b);
        }
    }
    debug(edges);
    debug(canbe);
    vector<ll> used(m);
    rrep(i,m,0){
        if(used[i])continue;
        if(!canbe[i])continue;
        queue<ll> que;
        auto &[a, b, y, id] = edges[i];
        que.emplace(a);que.emplace(b);
        used[id] = 1;
        cnt++;
        while(!que.empty()){
            auto t = que.front();que.pop();
            debug(t);
            for(auto &e : g[t]){
                if(used[e.id])continue;
                debug(e);
                if(e.c <= y){
                    cnt++;
                    que.emplace(e.t);
                    used[e.id] = 1;
                }
            }
        }
        debug(i, used);
    }

    cout << m - cnt  << "\n";
}