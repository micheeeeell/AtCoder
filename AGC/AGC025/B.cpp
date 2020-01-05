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
const ll MOD = 998244353;
const int n_max = 1e5+10;

const int MAX = 3e5 + 10;
// const int MOD = 1e9+7;

long long fac[MAX], finv[MAX], inv[MAX];
// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
    ll n; cin >> n;
    ll a,b,k; cin >> a >> b >> k;
    // bool ok = false;
    COMinit();
    ll ans = 0;
    rep(i,n+1){
        ll r = k - a*i;
        if(r < 0)break;
        if(r % b != 0)continue;
        r /= b;
        // debug(i);debug(r);
        // rep(G,min(i,r)+1){
        //     if(n < r+i-G)continue;
        //     ll A = i-G, B = r-G;
        //     ans = (ans + ((COM(n,A) * COM(n-A,B)) % MOD) * COM(n-A-B,G) % MOD) % MOD;
        // }
        ans = (ans + (COM(n,i) * COM(n,r) % MOD)) % MOD;
    }

    cout << ans << endl;
}