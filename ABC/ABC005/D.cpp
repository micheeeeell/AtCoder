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

template<class T>
void chmax(T &a, T &b){if(a < b)a = b;}
template<class T>
void chmin(T &a, T &b){if(a > b)a = b;}

int main(){
    ll n; cin >> n;
    vvl d(n, vector<ll>(n)), sum(n+1, vector<ll>(n+1,0));
    rep(i,n)rep(j,n){
        cin >> d[i][j];
        sum[i+1][j+1] = sum[i+1][j] + sum[i][j+1] - sum[i][j] + d[i][j];
    }
    vector<ll> ret(n*n+1,0);
    rep(i,n)for(int ii = i+1; ii <= n; ii++){
        rep(j,n)for(int jj = j+1; jj <= n;jj++){
            ll x = ii - i, y = jj - j;
            ll temp = sum[ii][jj] - sum[ii][j] - sum[i][jj] + sum[i][j];
            chmax(ret[x*y], temp);
        }
    }
    ll m = 0;
    rep(i,n*n+1){
        chmax(ret[i],m);
        chmax(m,ret[i]);
    }
    ll q; cin >> q;
    rep(i,q){
        ll p; cin >> p;
        cout << ret[p] << "\n";
    }
}