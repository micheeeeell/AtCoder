#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define pb push_back
#define eb emplace_back
#define debug(x) cerr << #x << ": " << (x) << "\n";
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
const ll INF = LLONG_MAX/4;
const ll MOD = 1e9+7;
const int n_max = 1e5+10;

template<typename G >
struct DoublingLCA {
    const int LOG;
    vector<int> dep;
    const G &g;
    int root;
    vector<vector<int>> table;

    DoublingLCA(const G &g, int root) : g(g), dep(g.size()), root(root), LOG(32 - __builtin_clz(g.size())) {
        table.assign(LOG, vector<int>(g.size(), -1));
    }

    void dfs(int idx, int par, int d) {
        table[0][idx] = par;
        dep[idx] = d;
        for(auto &to : g[idx]) {
            if(to != par)dfs(to, idx, d+1);
        }
    }

    void build() {
        dfs(root,-1,0);
        for(int k = 0; k+1 < LOG; k++) {
            for(int i = 0;i < table[k].size(); i++) {
                if(table[k][i] == -1)table[k+1][i] = -1;
                else table[k+1][i] = table[k][table[k][i]];
            }
        }
    }

    int query(int u, int v) {
        if(dep[u] > dep[v])swap(u,v);
        for(int i = LOG - 1; 0 <= i; i--) {
            if(((dep[v] - dep[u]) >> i) & 1) v = table[i][v];
        }
        if(u == v) return u;
        for(int i = LOG - 1; 0 <= i; i--) {
            if(table[i][u] != table[i][v]) {
                u = table[i][u];
                v = table[i][v];
            }
        }
        return table[0][u];
    }
};

int main(){
    ll n,u,v; cin >> n >> u >> v;
    u--;v--;
    vvl graph(n);
    rep(i,n-1) {
        ll a,b; cin >> a >> b;
        a--;b--;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    DoublingLCA<vvl> LCA(graph, v);
    LCA.build();
    Pll goal = {-1,-1};
    rep(i,n){
        ll dis = LCA.dep[i];
        ll t = LCA.dep[u] - LCA.dep[LCA.query(u,i)];
        if(0 < LCA.dep[LCA.query(u,i)] - t && goal.first < dis)goal = {dis, i};
    }
    if(goal.first == -1)goal = {LCA.dep[u], u};

    cout << goal.first - 1 << endl;
}