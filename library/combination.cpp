#include<bits/stdc++.h>
typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
using namespace std;

const ll N = 1e9+7;
const ll M = 2*1e5+5;
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
    ll n,m;
    cin >> n >> m;
    expo(); 
    cout << conv(n,m) << endl;
    return 0;
}
