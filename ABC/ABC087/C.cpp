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
    ll n; cin >> n;
    vector<vector<ll>> a(2,vector<ll>(n));
    rep(i,2)rep(j,n)cin >> a[i][j];
    ll ans = 0;
    vector<vector<ll>> sum(2,vector<ll>(n+1,0));
    rep(i,2)rep(j,n)sum[i][j+1] = sum[i][j] + a[i][j];
    rep(i,n){
        ll temp = sum[0][i+1] - sum[0][0];
        temp += sum[1][n] - sum[1][i];
        chmax(ans, temp);
    }
    cout << ans << endl;
}