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
// #define mp make_pair
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

const int MAX = 100;
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
template <typename T>
long long COM(T n, T k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

long long com(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    k = min(k,n-k);
    ll res = 1;
    rep(i,k){
        res *= (n-i);
        res /= (i+1);
    }
    return res;
}

int main(){
    ll n,a,b; cin >> n >> a >> b;
    vector<ll> v(n);
    map<ll, int> mp, used, clear;
    rep(i,n){
        cin >> v[i];
        mp[v[i]]++;
    }
    sort(all(v), greater<ll>());
    ld mean = 0;
    ll num = 0;
    COMinit();
    for(int i = a; i <= b; i++){
        ll temp = 0;
        rep(j,i){
            temp += v[j];
            used[v[j]]++;
        }
        ld m = temp * (ld)1.0 / i;
        debug(temp);
        debug(m);
        if(mean < m){
            mean = m;
            num = com(mp[v[i-1]], used[v[i-1]]);
        }
        else if(mean == m){
            debug(num);
            debug(mp[v[i-1]]);
            debug(used[v[i-1]]);
            debug(com(mp[v[i-1]], used[v[i-1]]));
            // debug(num);
            num += com(mp[v[i-1]], used[v[i-1]]);
        }
        else break;
        used = clear;
    }

    cout << fixed << setprecision(10) << mean << endl;
    cout << num << endl;
}