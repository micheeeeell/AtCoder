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
    map<ll,ll> map_;
    rep(i,n){
        ll a; cin >> a;
        map_[a]++;
    }
    ll ans = 0;
    vector<Pll> vec;
    for(auto itr = map_.begin(); itr != map_.end();itr++){
        if((*itr).second >= 2)vec.emplace_back((*itr).first, (*itr).second);
    }
    sort(all(vec), greater<Pll>());
    if(vec.size() >= 2){
        if(vec[0].second >= 4)ans = vec[0].first * vec[0].first;
        else ans = vec[0].first * vec[1].first;
    }
    cout << ans << endl;
}