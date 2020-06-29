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



vector<vector<ll>> graph;
vector<ll> color;
bool ok = true;
void dfs(ll now, ll c){
    color[now] = c;
    for(auto &to : graph[now]){
        if(color[to] == -1) dfs(to, c ^ 1);
        else if(color[to] == c) ok = false;
    }
}


template< typename T>
struct UnionFind{
private:
    vector<T> par;
    vector<T> rank;
    vector<Pll> sz;
    int n;

public:
    //n要素で親を初期化、par[x]はxの親を表す
    UnionFind(int n): n(n) {
        par.resize(n,0);
        rank.resize(n,0);
        for(int i = 0; i < n; i++){
            par[i] = i;
        }
    }

    void init(vector<ll> &color){
        sz.resize(n);
        rep(i,0,n){
            if(color[i] == 0)sz[i].first = 1;
            else sz[i].second = 1;
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
        sz[x].first += sz[y].first;
        sz[x].second += sz[y].second;
        if(rank[x] == rank[y]) rank[x]++; 
    }

    //xとyが同じ集合に属するか否か
    bool same(int x, int y){
        return root(x) == root(y);
    }

    //xが属する集合のサイズを返す
    Pll size(int x){
        return sz[root(x)];
    }

    // 集合の数を返す
    int num_of_s(){
        set<int> st;
        for(int i = 0; i < n; i++) st.insert(root(i));
        return st.size();
    }
};


signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,m; cin >> n >> m;
    graph.resize(n);
    color.resize(n, -1);

    vector<vector<bool>> gt(n, vector<bool>(n, 1));
    rep(i,0,m){
        ll a,b; cin >> a >> b;
        a--;b--;
        gt[a][b] = 0;
        gt[b][a] = 0;
    }

    rep(i,0,n)rep(j,i+1,n){
        if(gt[i][j]){
            graph[i].emplace_back(j);
            graph[j].emplace_back(i);
        }
    }

    rep(i,0,n){
        if(color[i] == -1){
            dfs(i, 0);
        }
    }

    if(!ok){
        cout << -1 << endl;
        return 0;
    }

    UnionFind<ll> uf(n);
    uf.init(color);
    rep(i,0,n){
        for(auto &j : graph[i]){
            uf.unite(i, j);
        }
    }

    vector<ll> used(n, 0);
    vector<Pll> item;
    rep(i,0,n){
        if(used[uf.root(i)])continue;
        item.emplace_back(uf.size(i));
        used[uf.root(i)] = 1;
    }
    debug(item);
    vector dp(n+1, vector<ll>(n+1,0));
    dp[0][0] = 1;
    rep(i,0,item.size()){
        rep(j,0,n+1){
            if(j >= item[i].first)chmax(dp[i+1][j], dp[i][j - item[i].first]);
            if(j >= item[i].second)chmax(dp[i+1][j], dp[i][j - item[i].second]);
        }
    }
    debug(dp);
    ll ans = INF;
    rep(i,0,n+1){
        if(dp[item.size()][i]){
            ll t1 = i, t2 = n - i;
            chmin(ans, t1 * (t1-1) / 2 + t2 * (t2 - 1) / 2);
        }
    }

    cout << ans << endl;
}