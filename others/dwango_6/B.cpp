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

void print() {
    cout << endl;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
    cout << head;
    if (sizeof...(tail) != 0) cout << ' ';
    print(forward<Tail>(tail)...);
}

template <class T>
void print(vector<T> &vec) {
    for (auto& a : vec) {
        cout << a;
        if (&a != &vec.back()) cout << ' ';
    }
    cout << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
    for (auto& vec : df) {
        print(vec);
    }
}

const ll MAX = 1e5+10;
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
    ll ans = 0;
    // assert(n <= 2000);
    vector<ll> dp(n+10,0);
    dp[0] = 1;
    rep(i,n)dp[i+1] = dp[i] * (i+1) % MOD;
    // print(dp);
    // rep(i,n-1){
    //     ll dis = x[i+1]- x[i];
    //     ll temp = dp[n-1];
    //     temp = (temp * dp[n-1] / (n-i-1));
    //     ans += temp * dis;
    //     ans %= MOD;
    // }
    COMinit();
    // rep(i,n)rep(j,n){
    //     if(i >= j)continue;
    //     ll dis = x[j] - x[i];
    //     ll temp;
    //     if(j == n-1){
    //         temp = dp[n-1] * modinv((j-i), MOD);
    //     }
    //     else{
    //         temp = (COM(n-1, j-i+1) * dp[j-i-1]) % MOD;
    //         temp = (temp * dp[n-j+i-2]) % MOD;
    //     }
    //     temp %= MOD;
    //     // debug(i);debug(j);
    //     // debug(temp);
    //     ans = (ans + (temp * dis) % MOD) % MOD;
    // }
    vector<ll> dp2(n+10);
    dp2[0] = 0;
    rep(i,n+1){
        dp2[i+1] = (dp2[i] * (i+1)) % MOD + (dp[i+1] * modinv((i+1), MOD)) % MOD;
        dp2[i+1] %= MOD;
    }
    // print(dp2);
    rep(i,n-1){
        ll dis = x[i+1]- x[i];
        ll temp = dp2[i+1];
        temp *= (dp[n-1] * modinv(dp[i+1], MOD)) % MOD;
        temp %= MOD;
        ans = (ans + (temp * dis) % MOD) % MOD;
    }
    cout << ans << endl;
}