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
template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}
int main(){
    string s;cin >> s;
    ll n = s.size();
    vector<vector<ll>> dp(n+1,vector<ll>(2,-1));
    dp[0][1] = 0;
    rep(i,n){
        rep(small,2){
            ll t = s[i] - '0';
            if(small){
                rep(j,t)chmax(dp[i+1][0], dp[i][small] + j);
                chmax(dp[i+1][1], dp[i][1]+t);
            }
            else{
                if(dp[i][0] != -1)rep(j,10)chmax(dp[i+1][0], dp[i][small] + j);
            }
        }
    }

    cout << max(dp[n][0], dp[n][1]) << endl;
}