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
    void add_edge(int f,int t,T c, int id){
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

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll n,m; cin >> n >> m;
    ll s; cin >> s;
    graph<ll> g(n);
    rep(i,m){
        ll u,v; cin >> u >> v;
        ll a,b; cin >> a >> b;
        u--;v--;
        g.add_edge(u,v,a,b);
        g.add_edge(v,u,a,b);
    }

    vector<ll> rate(n), time(n);
    rep(i,n) cin >> rate[i] >> time[i];

    vector dp(n, vector(2550, INF));
    auto dijkstra = [&](ll start, ll coin){
        coin = min(coin, 2549LL);
        dp[start][coin] = 0;
        using state = pair<ll, Pll>;
        priority_queue<state, vector<state>, greater<state>> pq;
        pq.emplace(0, Pll(start, coin));
        while(!pq.empty()){
            state cur = pq.top();pq.pop();
            ll c = cur.first; ll pos = cur.second.first, co = cur.second.second;
            if(dp[pos][co] < c)continue;
            for(auto &e : g.data[pos]){
                if(e.c > co)continue;
                if(c + e.id < dp[e.t][co - e.c]){
                    dp[e.t][co - e.c] = c + e.id;
                    pq.emplace(c + e.id, Pll(e.t, co - e.c));
                }
            }
            ll i = 1;
            ll co_temp, time_temp;
            do{
                co_temp = min(2549LL, co + i * rate[pos]);
                time_temp = c + time[pos] * i;
                if(time_temp < dp[pos][co_temp]){
                    dp[pos][co_temp] = time_temp;
                    pq.emplace(time_temp, Pll(pos, co_temp));
                }
                i++;
            }while(co_temp < 2549);
            // debug(pos);debug(co);
        }
    };


    dijkstra(0, s);
    ll temp;
    reps(i,n-1){
        temp = INF;
        rep(j,2550)chmin(temp, dp[i][j]);

        cout << temp << "\n";
    }
}