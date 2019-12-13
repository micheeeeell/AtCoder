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

vector<vector<ll>> dp(2,vector<ll>(n_max,0));
bitset<n_max> bs(0);
ll dfs(vvl &graph, ll pos, ll pre, ll f){
    ll res = 1;
    // bs[pos] = 1;
    if(dp[f][pos])return dp[f][pos];
    if(f == 0){
        for(auto i : graph[pos]){
            if(i == pre)continue;
            ll num = (dfs(graph, i, pos, 0) + dfs(graph, i, pos, 1)) % MOD;
            res = (res * num) % MOD;
        }
    }
    else{
        for(auto i : graph[pos]){
            if(i == pre)continue;
            res = (res * dfs(graph, i, pos, 0)) % MOD;
        }
    }
    // debug(pos);
    // debug(f);
    // debug(res);
    dp[f][pos] = res;
    return res;
}

int main(){
    ll n; cin >> n;
    vector<vector<ll>> graph(n);
    rep(i,n-1){
        ll a,b; cin >> a >> b;
        a--;b--;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }

    cout << (dfs(graph, 0, -1, 0) + dfs(graph, 0, -1, 1)) % MOD << endl;
}