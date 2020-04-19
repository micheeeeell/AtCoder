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

vector<ll> tree_topo(vvl &graph, ll root){
    const ll n_max = 1e5+10;
    bitset<n_max> bs(0);
    vector<ll> ans;
    priority_queue<ll, vector<ll>, greater<ll>> que;
    que.emplace(root);
    bs[root] = 1;
    while(!que.empty()) {
        auto f = que.top();que.pop();
        ans.emplace_back(f + 1);
        for(auto &to : graph[f]){
            if(bs[to])continue;
            bs[to] = 1;
            que.emplace(to);
        }
    }
    return ans;
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    vector<vector<ll>> graph(n);
    rep(i,n-1) {
        ll a,b;cin >> a >> b;
        a--;b--;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    auto ans = tree_topo(graph, 0);
    for(auto & i : ans){
        cout << i;
        if(&i != &ans.back())cout << " ";
        else cout << "\n";
    }
}