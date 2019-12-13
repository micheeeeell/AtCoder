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
#define mp make_pair
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

int main(){
    ll n,k; cin >> n >> k;
    vector<Pll> wp(n);
    rep(i,n){
        ll w,p; cin >> w >> p;
        wp[i] = Pll(w,p);
    }
    ld ok = 0;
    ld ng = 100;
    ll cnt = 0;
    while(cnt < 100){
        ld x = (ok+ng) / 2;
        sort(all(wp),
        [&](const auto &a, const auto &b){
            ld ta = x * a.first;
            ld tb = x * b.first;
            ld na = a.first * a.second; 
            ld nb = b.first * b.second; 
            return (na - ta) > (nb - tb);
        });
        ll wat = 0;
        ld sal = 0;
        rep(i,k){
            wat += wp[i].first;
            sal += ld(wp[i].first * wp[i].second);
        }
        ld con = sal / ld(wat);
        if(x <= con)ok = x;
        else ng = x;
        cnt++;
    }

    cout << fixed << setprecision(10);
    cout << ok << endl;
}