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

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

int main(){
    ll n; cin >> n;
    vector<vector<ll>> f(n, vector<ll>(n,0));
    rep(i,n)rep(j,n)cin >> f[i][j];
    vector<vector<ll>> dp(n+1, vector<ll>(n,0));

    vector<vector<ll>> sum(n, vector<ll>(n+1,0));
    rep(i,n)rep(j,n)sum[i][j+1] = sum[i][j] + f[i][j];

    rep(i,n){
        ll max_ = -INF;
        rep(j,i+1){
            chmax(max_, dp[i][j]);
            dp[i+1][j] = max_ + sum[i][i+1] - sum[i][j];
        }
    }

    ll ans = -INF;
    rep(i,n)chmax(ans, dp[n][i]);

    cout << ans * 2 << endl;
}