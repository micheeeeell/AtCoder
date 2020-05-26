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
const int n_max = 11000;

int main(){
    ll n; cin >> n;
    vector<ll> p(n);
    rep(i,n) cin >> p[i];
    vector<ll> dp(n_max, 0);
    dp[0] = 1;
    rep(i,n){
        for(int j = n_max; j >= 0; j--){
            if(dp[j] && j + p[i] < n_max)dp[j+p[i]] = 1;
        }
    }
    ll ans = 0;
    rep(i,n_max)ans += dp[i];
    cout << ans << endl;
}