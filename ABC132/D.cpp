#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define rep(i,x) for(int i = 0; i < x; i++)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> ivec;
const ll N = 1e9+7;

// const ll N = 1e9+7;
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


ll conv(ll x, ll y){
    ll ans;
    if(y > 0) ans = dp[x] * (invdp[y] * invdp[x-y] %N) % N;
    else ans = 1;
    // cout << dp[x] << " " << invdp[y] << " " << invdp[x-y] << " " << ans << endl;
    return ans;
}


int main(){
    int n,k; cin >> n >> k;
    int red = n-k;
    int kaijou[red];
    // kaijou[0] = 1;
    // for(int i = 1;i < red;i++){
    //     kaijou[i] = i * kaijou[i-1] % N ;
    // }
    expo();
    int convination[k];
    int amari[k];
    rep(i,k){
        convination[i] = conv(k-1,i);
        amari[i] = red - i;
    }
    // convination[k] = 1;
    // amari
    rep(i,k){
        int ans = 0;
        ans = convination[i] * conv(amari[i]+i+1,i+1) % N;
        cout << ans << endl;
    }

    return 0;

}