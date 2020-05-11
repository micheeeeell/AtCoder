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
const int n_max = 2e5+10;
#define int ll
vector<ll> N_LIS(vector<int> a){
    vector<ll> dp(n_max, INF);
    // fill(all(dp), INF);
    int n = a.size();
    rep(i,n){
        *lower_bound(all(dp), a[i]) = a[i];
    }
    cout << lower_bound(all(dp), INF) - dp.begin() << endl;
    return dp;
}


vector<ll> dp(n_max, INF);
vector<ll> a(n_max);
void dfs(vvl &graph, vl &v, ll pos, ll par){
    ll id = lower_bound(all(v), a[pos]) - v.begin();
    ll temp = v[id];
    v[id] = a[pos];
    for(auto &to : graph[pos]){
        if(to != par){
            dfs(graph, v, to, pos);
        }
    }
    dp[pos] = lower_bound(all(v), INF) - v.begin();
    v[id] = temp;
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;

    rep(i,n) cin >> a[i];
    vector<vector<ll>> graph(n);
    rep(i,n-1) {
        ll a,b;cin >> a >> b;
        a--;b--;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    vector<ll> v(n, INF);
    dfs(graph, v, 0, -1);
    rep(i,n){
        cout << dp[i] << "\n";
    }
}