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
    vector<ll> a(3), b(3);
    rep(i,3)cin >> a[i];
    rep(i,3)cin >> b[i];
    vector<ll> dp(n+1,0);
    rep(i,3){
        rep(j,n+1){
            if(j >= a[i])chmax(dp[j], dp[j - a[i]] + b[i] - a[i]);
        }
    }
    ll m = dp[n] + n;
    vector<ll> dp2(m+1,0);
    rep(i,3){
        rep(j,m+1){
            if(j >= b[i])chmax(dp2[j], dp2[j - b[i]] + a[i] - b[i]);
        }
    }

    cout << m + dp2[m] << endl;
}