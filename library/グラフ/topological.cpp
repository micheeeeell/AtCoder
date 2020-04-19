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

// 有向グラフ上のトポロジカルソート
vector<ll> topo_sort(vvl &graph){
    queue<ll> que;
    vector<ll> ans;
    ll v = graph.size();
    vector<ll> in(v);
    for(auto &vec : graph){
        for(auto &to : vec)in[to]++;
    }
    rep(i,v)if(in[i] == 0){
        que.emplace(i);
        ans.emplace_back(i);
    }
    while(!que.empty()) {
        auto f = que.front();que.pop();
        for(auto &to : graph[f]) {
            in[to]--;
            if(!in[to]) {
                ans.emplace_back(to);
                que.emplace(to);
            }
        }
    }

    return ans;
};

// 木の上のトポロジカルソート
// 適当な根から有向であるとみなしてBFS
vector<ll> tree_topo(vvl &graph, ll root){
    // const ll n_max = 1e5+10;
    bitset<n_max> bs(0);
    vector<ll> ans;
    queue<ll> que;
    que.emplace(root);
    bs[root] = 1;
    while(!que.empty()) {
        auto f = que.front();que.pop();
        ans.emplace_back(f);
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
    
    ll v,e; cin >> v >> e;
    vvl graph(v);
    vector<ll> in(v);
    rep(i,e){
        ll f,t; cin >> f >> t;
        // f--;t--;
        graph[f].emplace_back(t);
        in[t]++;
    }
    auto ans = topo_sort(graph);

    for(auto &i : ans){
        cout << i;
        if(&i != &ans.back())cout << "\n";
    }
    cout << endl;
}