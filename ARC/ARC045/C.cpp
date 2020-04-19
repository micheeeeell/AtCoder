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



//頂点fromから頂点toへのコストcostの辺
template<typename T>
struct edge{
    int f,t;
    T c;
    int id;
    edge(){};
    edge(int f,int t,T c,int id = 0):f(f),t(t),c(c),id(id){};
    bool operator< (const edge &s){
        return c < s.c;
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
    std::vector<edge<T>> make_edges(){
        std::vector<edge<T>> r;
        for(auto &i:data)std::copy(i.begin(),i.end(),std::back_inserter(r));
        return r;
    }
    vector<edge<T>> operator[](int i){
        return data[i];
    }
};

vector<ll> dp(n_max);
bitset<n_max> used = 0;
void dfs(graph<ll> &g, ll pos){
    used[pos] = 1;
    for(auto &e : g[pos]){
        if(used[e.t])continue;
        dp[e.t] = dp[pos] ^ e.c;
        dfs(g, e.t);
    }
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll n,x; cin >> n >> x;
    graph<ll> g(n);
    rep(i,n-1){
        ll a,b,c; cin >> a >> b >> c;
        a--;b--;
        g.add_edge(a,b,c);
        g.add_edge(b,a,c);
    }
    dfs(g, 0);
    unordered_map<ll,ll> mp;
    ll ans = 0;
    rep(i,n){
        if(mp.find(x ^ dp[i]) != mp.end())ans += mp[x ^ dp[i]];
        mp[dp[i]]++;
    }

    cout << ans << endl;
}