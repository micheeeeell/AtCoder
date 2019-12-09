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

int main(){
    ll n,m; cin >> n >> m;
    vector<ll> s(n);
    rep(i,n) cin >> s[i];
    vector<ll> t(m);
    rep(i,m) cin >> t[i];
    vector<vector<ll>> dp(n,vector<ll>(m,0)), sum(n+1, vector<ll>(m+1,0));
    // if(s[0] == t[0])dp[0][0] = 1;
    rep(i,n){
        rep(j,m){
            if(s[i] != t[j])dp[i][j] = 0;
            else dp[i][j] = (sum[i][j] + 1) % MOD;
            sum[i+1][j+1] = (sum[i][j+1] + sum[i+1][j] - sum[i][j] + dp[i][j]) % MOD;
            if(sum[i+1][j+1] < 0)sum[i+1][j+1] += MOD;
        }
    }
    cout << (sum[n][m] + 1) % MOD << endl;
}