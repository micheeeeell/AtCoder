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
const ll INF = numeric_limits<ll>::max()/4;
const int n_max = 1e5+10;

// DoublingによりLowest Common Ancestor(最小共通祖先)を求める
// うしさんのライブラリです
// G はvector< vector<int> >とかで行ける
// 検証：ABC014_D 木のノード間距離を求める問題
template<typename G >
struct DoublingLCA {
    const int LOG;
    vector<int> dep;
    const G &g;
    vector<vector<int>> table;

    DoublingLCA(const G &g) : g(g), dep(g.size()), LOG(32 - __builtin_clz(g.size())) {
        table.assign(LOG, vector<int>(g.size(), -1));
    }

    void dfs(int idx, int par, int d) {
        table[0][idx] = par;
        dep[idx] = d;
        for(auto &to : g[idx]) {
            if(to != par)dfs(to, idx, d+1);
        }
    }

    void build(int root) {
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
    ll n; cin >> n;
    vvl g(n);
    ll r;
    rep(i,n){
        ll q; cin >> q;
        if(q == -1){
            r = i;
            continue;
        }
            
        q--;
        g[q].emplace_back(i);
    }
    DoublingLCA<vvl> lca(g);
    lca.build(r);
    ll q; cin >> q;
    rep(i,q){
        ll a,b; cin >> a >> b;
        a--;b--;
        bool ok = false;
        if(lca.query(a,b) == b)ok = true;
        cout << (ok ? "Yes" : "No") << "\n";
    }
}