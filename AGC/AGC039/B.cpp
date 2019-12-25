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
void chmax(T &a, T b){if(a < b)a = b;}
template<class T>
void chmin(T &a, T b){if(a > b)a = b;}

int main(){

    // ifstream in("input.in");
    // cin.rdbuf(in.rdbuf());

    ll n; cin >> n;
    string s[n];
    rep(i,n)cin >> s[i];
    vector<vector<ll>> table(n,vector<ll>(n,INF));
    rep(i,n)rep(j,n)if(s[i][j] == '1')table[i][j] = 1;
    rep(i,n)table[i][i] = 0;

    rep(k,n)rep(i,n)rep(j,n){
        chmin(table[i][j], table[i][k] + table[k][j]);
    }
    bool ok = true;
    rep(i,n)rep(j,i){
        if(s[i][j] == '1' && abs(table[0][i] - table[0][j]) != 1){ok = false; break;}
    }
    ll ret = 0;
    Pll m = {-1,-1};
    // rep(i,n)chmax(m, Pll(table[0][i], i));
    // rep(i,n)chmax(ret, table[m.second][i]);
    rep(i,n)rep(j,n)chmax(ret, table[i][j]);
    cout << (ok ? ret + 1 : -1) << endl;
}