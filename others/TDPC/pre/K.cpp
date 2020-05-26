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
const int n_max = 1e5+10;

int main(){
    ll n; cin >> n;
    vector<Pll> cir(n);
    rep(i,n){
        ll x,r; cin >> x >> r;
        cir[i] = {x-r, x+r};
    }
    sort(all(cir), [&](auto const &a, auto const &b){
        return (a.first < b.first) || (a.first == b.first && a.second < b.second);
    });
    vector<ll> dp(n,-INF);

    rep(i,n){
        int ok = n-1;
        int ng = -1;
        while(abs(ok - ng) > 1){
            int x = (ok + ng) / 2;
            if(dp[x] > cir[i].second)ng = x;
            else ok = x;
        }
        dp[ok] = cir[i].second;
        // debug(i);
        // debug(ok);
    }

    int ng = n;
    int ok = 0;
    while (abs(ok - ng) > 1){
        int x = (ok + ng) / 2;
        if(dp[x] == -INF)ng = x;
        else ok = x;
    }
    cout << ok+1 << endl;
}