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
const ll MOD = 1e9+7;
const int n_max = 1e5+10;

int main(){
    ll n; cin >> n;
    string s;cin >> s;
    vector<ll> dp(n+1,0), str(26,0);
    dp[0] = 1;
    rep(i,n){
        ll t = s[i] - 'a';
        dp[i+1] = (dp[i] + dp[i] - str[t]) % MOD;
        if(dp[i+1] < 0)dp[i+1] += MOD;
        rep(j,26){
            if(j == t)str[j] = dp[i];
            else str[j] += (dp[i+1] - dp[i]) / 2;
            str[j] %= MOD;
            if(str[j] < 0)str[j] += MOD;
        }
        str[t] = dp[i];
    }
    cout << dp[n]-1 << endl;
}