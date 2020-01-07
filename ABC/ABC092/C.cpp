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
    vector<ll> a(n+2,0);
    rep(i,n)cin >> a[i+1];
    vector<ll> one(n+1), two(n);
    rep(i,n+1)one[i] = abs(a[i+1] - a[i]);
    rep(i,n)two[i] = abs(a[i+2] - a[i]);
    ll all = 0;
    rep(i,n+1)all += one[i];
    rep(i,n){
        ll temp = all;
        temp -= one[i] + one[i+1];
        temp += two[i];
        cout << temp << "\n";
    }
}