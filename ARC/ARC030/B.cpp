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
void print(vector<T> &vec, ll k){
    rep(i,k)cout << vec[i] << " ";
    cout << endl;
}
bitset<n_max> used(0);
vector<ll> h(n_max), cnt(n_max);
ll number(vvl &graph, ll pos){
    used[pos] = 1;
    ll ret = 0;
    for(auto &to : graph[pos]){
        if(used[to])continue;
        cnt[pos] += number(graph, to);
    }
    cnt[pos] += h[pos];
    return cnt[pos];
}

vector<ll> memo(n_max);
ll dfs(vvl &graph, ll pos){
    used[pos] = 1;
    ll ret = 0;
    for(auto &to : graph[pos]){
        if(used[to])continue;
        if(cnt[to] == 0)continue;
        ret += 2 + dfs(graph, to);
    }
    return memo[pos] = ret;
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll n,x; cin >> n >> x;
    x--;
    // vector<ll> h(n);
    rep(i,n) cin >> h[i];
    vector<vector<ll>> graph(n);
    rep(i,n-1) {
        ll a,b;cin >> a >> b;
        a--;b--;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    number(graph, x);
    // print(h, 10);
    // print(cnt, 10);
    used = 0;
    cout << dfs(graph, x) << endl;
    // print(memo, 10);
}