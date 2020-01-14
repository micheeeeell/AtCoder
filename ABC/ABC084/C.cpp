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

template<typename T>
T ceil(T a, T b){
    return (a+b-1) / b;
}

int main(){
    ll n; cin >> n;
    vector<ll> c(n-1), s(n-1), f(n-1);
    rep(i,n-1)cin >> c[i] >> s[i] >> f[i];
    rep(i,n){
        ll time = 0;
        ll pos = i;
        while(pos < n-1){
            time = max(s[pos], ceil(time,f[pos]) * f[pos]);
            time += c[pos];
            pos++;
        }
        cout << time << "\n";
    }
}