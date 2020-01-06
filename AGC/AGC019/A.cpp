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
    ll q,h; cin >> q >> h;
    ll s,d; cin >> s >> d;
    ll n; cin >> n;
    vector<Pll> vec = {
        {q*8,1},
        {h*4,2},
        {s*2,4},
        {d,8}
    };
    sort(all(vec));
    ll ans = 0;
    ll id = 0;
    n *= 4;
    while(0 < n){
        ans += (n/vec[id].second) * (vec[id].first*vec[id].second / 8);
        n %= vec[id].second;
        id++;
    }
    cout << ans << endl;
}