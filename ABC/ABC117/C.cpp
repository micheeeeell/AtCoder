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
    ll n,m; cin >> n >> m;
    vector<ll> x(m);
    rep(i,m) cin >> x[i];
    sort(all(x));
    vector<ll> dif(m-1);
    ll sum = 0;
    rep(i,m-1){
        dif[i] = x[i+1] - x[i];
        sum += dif[i];
    }
    sort(all(dif),greater<ll>());
    rep(i,min(n-1, m-1))sum -= dif[i];
    cout << sum << endl;

}