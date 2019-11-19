#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(int i = 0; i < (int)(x); i++)
#define pb push_back
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
const ll MOD = 1e9+7;
const int n_max = 1e5+10;


const ll N = 1e9+7;
const ll M = 1e6+5;
ll dp[M], invdp[M], inv[M];

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

void expo(){
    dp[0] = 1;
    invdp[0] = 1;
    inv[0] = 1;
    rep(i,M){
        dp[i+1] = dp[i] * (i + 1) % N;
        inv[i+1] = N - inv[N%(i+1)] * (N/(i+1)) % N;
        invdp[i+1] = modinv(dp[i+1], N);
    }
}


ll comb(ll x, ll y){
    ll ans;
    if(y > 0) ans = dp[x] * (invdp[y] * invdp[x-y] %N) % N;
    else ans = 1;
    // cout << dp[x] << " " << invdp[y] << " " << invdp[x-y] << " " << ans << endl;
    return ans;
}

int main(){
    ll X,Y;  cin >> X >> Y;
    ll x = 2*Y-X, y = 2*X-Y;
    bool ok = true;
    if(x%3 || y%3 || x < 0 || y < 0)ok = false;
    else{
        x /= 3;
        y /= 3;
    }
    expo();
    cout << (ok ? comb(x+y, y) : 0) << endl;
}