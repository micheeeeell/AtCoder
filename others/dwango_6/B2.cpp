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

ll modinv(ll a, ll m){
    ll b = m, u = 1, v = 0;
    while(b){
        ll t = a/b;
        a -= t * b; swap(a,b);
        u -= t * v; swap(u,v);
    }
    u %= m;
    if(u < 0) u += m;
    return u;

}

int main(){
    ll n; cin >> n;
    vector<ll> x(n);
    rep(i,n) cin >> x[i];
    ll k = 1;
    rep(i,n-1)k = (k * (i+1)) % MOD;
    vector<ll> dp(n-1), sum(n,0);
    rep(i,n-1)dp[i] = (k * modinv((i+1),MOD)) % MOD;
    rep(i,n-1)sum[i+1] = (sum[i] + dp[i]) % MOD;
    ll ans = 0;
    rep(i,n-1){
        ll dis = x[i+1] - x[i];
        ll temp = sum[i+1] - sum[0];
        ans = (ans + (dis * temp) % MOD) % MOD;
    }
    cout << ans << endl;
}