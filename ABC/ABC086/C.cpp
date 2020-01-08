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
    ll n; cin >> n;
    vector<ll> t(n+1,0), x(n+1,0), y(n+1,0);
    rep(i,n)cin >> t[i+1] >> x[i+1] >> y[i+1];
    bool ok = true;
    rep(i,n){
        ll dis = abs(x[i+1] - x[i]) + abs(y[i+1] - y[i]);
        ll time = t[i+1] - t[i];
        ok &= (dis <= time && dis%2 == time%2);
    }

    cout << (ok ? "Yes" : "No") << endl;
}