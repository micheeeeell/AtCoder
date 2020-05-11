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

template<class T>
vector<T> topo_sort(vector<vector<T>> &graph){
    ll n = graph.size();
    vector<ll> in(n);
    rep(i,n)for(auto &to : graph[i])in[to]++;
    deque<ll> deq;
    rep(i,n)if(in[i] == 0)deq.emplace_back(i);
    vector<T> ret;
    while(!deq.empty()){
        ll t = deq.front();deq.pop_front();
        ret.emplace_back(t);
        for(auto &to : graph[t]){
            in[to]--;
            if(in[to] == 0)deq.emplace_back(to);
        }
    }

    return ret;
};

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll n,m; cin >> n >> m;
    vector<vector<ll>> graph(n);
    rep(i,m) {
        ll a,b;cin >> a >> b;
        a--;b--;
        graph[a].emplace_back(b);
        // graph[b].emplace_back(a);
    }
    auto topo = topo_sort(graph);
    ll ans = 0;
    vector<ll> dp(n);
    rep(i,n){
        ll pos = topo[i];
        for(auto &to : graph[pos]){
            chmax(dp[to], dp[pos] + 1);
        }
    }

    rep(i,n)chmax(ans, dp[i]);

    cout << ans << endl;
}