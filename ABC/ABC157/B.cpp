#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define rrep(i,x) for(ll i = (ll)(x)-1;0 <= i; i--)
#define reps(i,x) for(ll i = 1; i < (ll)(x)+1; i++)
#define rreps(i,x) for(ll i = (ll)(x); 1 <= i; i--)
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
const int n_max = 1e5+10;

int main(){
    vvl a(3, vl(3));
    rep(i,3)rep(j,3)cin >> a[i][j];
    ll n; cin >> n;
    vector<ll> b(n);
    rep(i,n) cin >> b[i];
    vvl g(3, vl(3,0));
    rep(k,n){
        rep(i,3)rep(j,3)if(a[i][j] == b[k])g[i][j] = 1;
    }
    bool ok = false;

    rep(i,3){
        bool temp = true;
        rep(j,3)temp &= g[i][j];
        ok |= temp;
        temp = true;
        rep(j,3)temp &= g[j][i];
        ok |= temp;
    }
    bool temp = true;
    rep(i,3)temp &= g[i][i];
    ok |= temp;
    temp = true;
    temp &= (g[2][0] & g[1][1] & g[0][2]);
    ok |= temp;

    cout << (ok ? "Yes" : "No") << endl;
}