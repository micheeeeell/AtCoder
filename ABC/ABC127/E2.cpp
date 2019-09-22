#include<bits/stdc++.h>
typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
using namespace std;

const ll N = 1e9+7;
const ll M = 2*1e5+5;
ll dp[M], invdp[M];

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
    // inv[0] = 1;
    rep(i,M){
        dp[i+1] = dp[i] * (i + 1) % N;
        // inv[i+1] = N - inv[N%(i+1)] * (N/(i+1)) % N;
        invdp[i+1] = modinv(dp[i+1], N);
    }
}


ll conv(ll x, ll y){
    ll ans;
    if(y > 0 && x > y) ans = dp[x] * (invdp[y] * invdp[x-y] %N) % N;
    else ans = 1;
    // cout << dp[x] << " " << invdp[y] << " " << invdp[x-y] << " " << ans << endl;
    return ans;
}

int main(){
    int n,m,k; cin >> n >> m >> k;
    // dp[0] = 1;
    // rep(i,m*n+5){
    //     dp[i+1] = dp[i] * (i + 1) % N;
    // }
    // rep(i,10) cout << dp[i] << endl;
    expo();
    ll xans = 0;
    ll yans = 0;
    // cout << conv(n*m-2,k-2) << endl;
    ll cv = conv(n*m-2,k-2);
    for(int d = 1; d < n; d++){
        xans += cv * d * (n-d) *m * m % N; 
    }
    for(int d = 1; d < m; d++){
        yans += cv * d * (m-d) *n * n % N; 
    }

    ll ans = (xans + yans ) % N;
    cout << ans << endl;   
}