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
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(all(a));
    auto check = [&](int id){
        ll sz = a[id];
        rep(i,n){
            if(i == id)continue;
            if(a[i] <= 2*sz)sz += a[i];
            else return false;
        }
        return true;
    };

    int ok = n-1;
    int ng = -1;
    while(abs(ok - ng) > 1){
        int x = (ok + ng)/2;

        if(check(x))ok = x;
        else ng = x;
    }
    cout << n - ok << endl;
}