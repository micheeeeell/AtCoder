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
    ll n,m; cin >> n >> m;
    vector<vector<ll>> table(n, vector<ll>(n,INF));
    rep(i,m){
        ll a,b,t; cin >> a >> b >> t;
        a--;b--;
        table[a][b] = t;
        table[b][a] = t;
    }
    rep(i,n)table[i][i] = 0;

    rep(k,n)rep(i,n)rep(j,n){
        table[i][j] = min(table[i][j], table[i][k] + table[k][j]);
    }

    ll ret = INF;
    rep(i,n){
        ll temp = 0;
        rep(j,n)temp = max(temp, table[i][j]);
        ret = min(ret, temp);
    }
    cout << ret << endl;
    return 0;
}