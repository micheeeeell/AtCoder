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

int main(){
    ll n,m; cin >> n >> m;
    vector<ll> x(n);
    rep(i,n) cin >> x[i];
    vector<ll> y(m);
    rep(i,m) cin >> y[i];
    ll res;
    ll x_t = 0, y_t = 0;
    rep(i,n-1){
        ll len = (x[i+1] - x[i]) % MOD;
        ll num = (i+1) * (n - (i+1)) % MOD;
        x_t = (x_t + len * num) % MOD;
    }
    rep(i,m-1){
        ll len = (y[i+1] - y[i]) % MOD;
        ll num = (i+1) * (m - (i+1)) % MOD;
        y_t = (y_t + len * num) % MOD;
    }

    res = (x_t * y_t) % MOD;
    cout << res << endl;
}