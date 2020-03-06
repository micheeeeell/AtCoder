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
const int MOD = 1e9+7;

const int MAX = 1e6 + 10;

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

// パスカルの三角形で求める方法
// 時間計算量はO(MAX^2)
const int MAX = 51;
vector<vector<ll>> com(MAX+1,vector<ll>(MAX+1,0));
void COMinit(){
    com[0][0] = 1;
    rep(i,MAX){
        rep(j,MAX){
            if(i == 0 || j == 0)com[i][j] = 1;
            else com[i][j] = com[i][j-1] + com[i-1][j];
        }
    }
}
ll COM(ll n, ll k){
    return com[n-k][k];
}

// modintが必要
// modintによる実装
const int MAX = 1e6;
vector<mint> fac(MAX);
void COMinit(){
    fac[0] = 1;
    reps(i,n_max-1){
        fac[i] = fac[i-1] * mint(i);
    }
}

mint COM(ll n, ll k){
    if (n < k) return (mint)0;
    if (n < 0 || k < 0) return (mint)0;
    return fac[n] / (fac[k] * fac[n-k]);
}


int main() {
    // 前処理
    COMinit();

    // 計算例
    ll n,m;
    cin >> n >> m;
    cout << COM(n, m) << endl;
}