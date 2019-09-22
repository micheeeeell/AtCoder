#include<bits/stdc++.h>
typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)

using namespace std;
ll N = 1e9+7;
ll M = 2*1e5+5;
vector<ll> dp(M);

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

ll conv(ll x, ll y){
    ll ans;
    if(y > 0) ans = dp[x] / (dp[y] * dp[x - y] %N) % N;
    else ans = 1;
    cout << dp[x] << " " << dp[y] << " " << dp[x-y] << ans << endl;
    return ans;
}

int main(){
    int n,m,k; cin >> n >> m >> k;
    dp[0] = 1;
    rep(i,m*n+5){
        dp[i+1] = dp[i] * (i + 1) % N;
    }
    // rep(i,10) cout << dp[i] << endl;
    ll xans = 0;
    ll yans = 0;
    cout << conv(n*m-3,k-3) << endl;
    for(int d = 1; d < n; d++){
        xans += conv(n*m-3, k-3) * (n-d) *m * m % N; 
    }
    for(int d = 1; d < m; d++){
        yans += conv(n*m-3, k-3) * (m-d) *n * n % N; 
    }

    ll ans = (xans + yans ) % N;
    cout << ans << endl;   
}