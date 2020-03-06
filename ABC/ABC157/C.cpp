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
    ll n,m; cin >> n >> m;
    auto dig = [&](ll x){
        ll cnt = 0;
        while(x){
            cnt++;
            x /= 10;
        }
        return cnt;
    };
    map<ll,ll> map_;
    bool ok = true;
    rep(i,m){
        ll s,c; cin >> s >> c;
        if(map_.find(s) != map_.end() && map_[s] != c)ok = false;
        map_[s] = c;
    }

    
    bool r = false;
    rep(i,1000){
        if(dig(i) != n)continue;

    }
}