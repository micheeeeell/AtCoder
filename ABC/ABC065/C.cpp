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
    ll n,m; cin >> n >> m;
    ll temp = 1;
    ll ans = 1;
    rep(i,n) temp = (temp * (i+1)) % MOD;
    ans *= temp;
    temp = 1;
    rep(i,m) temp = (temp * (i+1)) % MOD;
    ans = (ans * temp) % MOD;
    if(n == m)ans *= 2;
    else if(abs(n-m) > 1)ans = 0;
    ans %= MOD;
    cout << ans << endl;
}