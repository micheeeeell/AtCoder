#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#define rep(i,x) for(int i = 0; i < x; i++)
typedef long long ll;
using namespace std;
const ll N = 1e9+7;

int main(){
    ll n,m; cin >> n >> m;
    vector<ll> s(n),t(m);
    rep(i,n) cin >> s[i];
    rep(i,m) cin >> t[i];
    ll dp[n][m] = {},sum[n][m] = {};
    // rep(i,n) rep(j,m)cout << sum[i][j] << " ";
    if(s[0] == t[0]) dp[0][0] = 1;
    else dp[0][0] = 0;
    rep(i,m){
        if(i > 0){
            if(s[0] == t[i])dp[0][i] = 1;
            else dp[0][i] = 0;
            sum[0][i] = (sum[0][i-1] + dp[0][i]) % N;
        }
        else sum[0][i] = dp[0][i];
    }
    rep(i,n){
        // if(s[0] == t[0])dp[0][0] = 1;
        if(i > 0){
            if(s[i] == t[0])dp[i][0] = 1;
            else dp[i][0] = 0;
            sum[i][0] = (sum[i-1][0] + dp[i][0]) % N;
        }
        else sum[i][0] = dp[i][0];
    }
    for(int i = 1;i < n; i++){
        for(int j = 1; j < m; j++){
            if(s[i] == t[j]) dp[i][j] = (sum[i-1][j-1] + 1) % N;
            else dp[i][j] = 0;
            sum[i][j] = (sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + dp[i][j]) % N;
        }
    }
    cout << (sum[n-1][m-1] + 1) % N << endl;
    // rep(i,n){
    //     rep(j,m){
    //         cout << sum[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    }