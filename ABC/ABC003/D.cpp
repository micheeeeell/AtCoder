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
const ll INF = LLONG_MAX/4;
const ll MOD = 1e9+7;
const int n_max = 1e5+10;

const int MAX = 1e5 + 10;
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

// 要素4の包除の定理

int main(){
    ll r,c; cin >> r >> c;
    ll x,y; cin >> x >> y;
    ll d,l; cin >> d >> l;
    COMinit();
    ll ret = 1;
    ret = ret * (r-x+1) * (c-y+1) % MOD;
    ll com;
    if(x*y == d+l)com = COM(x*y, d);
    else{
        com = COM(d+l,d);
        ll t = 0;
        t = COM(x*y, d+l);
        t -= 2 * (COM(x*(y-1), d+l) + COM((x-1)*y, d+l));
        while(t < 0)t += MOD;
        t += 4*(COM((x-1)*(y-1), l+d)) % MOD;
        t += COM((x-2)*y, d+l) + COM(x*(y-2), d+l);
        t %= MOD;
        t -= 2 * (COM((x-2)*(y-1), l+d) + COM((x-1)*(y-2), l+d));
        while(t < 0)t += MOD;
        t += COM((x-2)*(y-2), l+d);
        t %= MOD;
        com = com * t % MOD;
    }
    cout << ret * com % MOD << endl;
}