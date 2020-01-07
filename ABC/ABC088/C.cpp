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

int main(){
    vector<vector<ll>> c(3,vector<ll>(3));
    rep(i,3)rep(j,3)cin >> c[i][j];
    bool ok = true;
    rep(i,2){
        bool temp = true;
        ll sub = c[i+1][0] - c[i][0];
        rep(j,2)temp &= ((c[i+1][j+1] - c[i][j+1]) == sub);
        ok &= temp;
    }
    rep(i,2){
        bool temp = true;
        ll sub = c[0][i+1] - c[0][i];
        rep(j,2)temp &= ((c[j+1][i+1] - c[j+1][i]) == sub);
        ok &= temp;
    }

    cout << (ok ? "Yes" : "No") << endl;
}