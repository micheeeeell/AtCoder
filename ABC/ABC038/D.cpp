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
#define mp make_pair
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

// 部分点解法
// 小さいものに対する有向辺を張って最長経路長が答え

ll n;
ll m;
vector<vector<ll>> graph;
vector<ll> memo(n_max,0);
ll dfs(ll pos){
    if(graph[pos].size() == 0){
        memo[pos] = 1;
        return 1;
    }
    if(memo[pos])return memo[pos];
    ll res = 0;
    for(auto i : graph[pos]){
        res = max(res, dfs(i) + 1);
    }
    memo[pos] = res;
    return res;
}

int main(){
    cin >> n;
    vector<ll> h(n), w(n);
    rep(i,n)cin >> h[i] >> w[i];
    graph.resize(n);
    vector<ll> in(n,0);
    rep(i,n)rep(j,n){
        if(i == j)continue;
        if(h[i] < h[j] && w[i] < w[j]){
            graph[j].emplace_back(i);
            in[i]++;
        }
    }

    ll ret = 0;
    rep(i,n){
        if(in[i] == 0)ret = max(ret, dfs(i));
    }

    cout << ret << endl;
}