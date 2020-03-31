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
    ll x,y; cin >> x >> y;
    ll a,b,c; cin >> a >> b >> c;
    vector<Pll> all;
    rep(i,a){
        ll p; cin >> p;
        all.emplace_back(Pll(p, 1));
    }
    rep(i,b){
        ll q; cin >> q;
        all.emplace_back(Pll(q, 2));
    }
    rep(i,c){
        ll r; cin >> r;
        all.emplace_back(Pll(r, 0));
    }

    sort(all(all), greater<Pll>());
    ll xc = 0, yc = 0, z = 0;
    ll ans = 0;
    for(auto i : all){
        if(i.second == 0){
            z++;
            ans += i.first;
        }
        if(i.second == 1){
            xc++;
            if(xc <= x)ans += i.first;
        }
        if(i.second == 2){
            yc++;
            if(yc <= y)ans += i.first;
        }
        if(xc >= x && yc + z == y)break;
        if(yc >= y && xc + z == x)break;
        if(xc <= x && yc <= y && xc + yc + z == x + y)break;
    }

    cout << ans << endl;
}