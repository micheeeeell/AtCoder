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
#define int ll

signed main(){
    ll n; cin >> n;
    // vector<ll> red, blue;
    // rep(i,n){
    //     ll x; cin >> x;
    //     char c; cin >> c;
    //     if(c == 'R')red.emplace_back(x);
    //     else blue.emplace_back(x);
    // }

    // sort(all(red));sort(all(blue));
    // for(auto &i : red)cout << i << "\n";
    // for(auto &j : blue)cout << j << "\n";
    // return 0;
    vector<pair<ll, char>> vec(n);
    rep(i,n)cin >> vec[i].first >> vec[i].second;
    // sort(all(vec), [&](const auto &a, const auto &b){
    //     if(a.second == 'R'){
    //         if(b.second == 'B')return true;
    //         else return a.first < b.first;
    //     }
    //     else{
    //         if(b.second == 'R')return false;
    //         else return a.first < b.first;
    //     }
    // });

    sort(all(vec), [&](const auto &a, const auto &b){
        return a.second > b.second || (a.second == b.second && a.first < b.first);
    });
    for(auto [x , c] : vec){
        cout << x << "\n";
    }
    return 0;
}