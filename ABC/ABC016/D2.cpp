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
const ll INF = LLONG_MAX/4;
const ll MOD = 1e9+7;
const int n_max = 1e5+10;

int main(){
    ll ax,ay; cin >> ax >> ay;
    ll bx,by; cin >> bx >> by;
    ll A,B,C;
    A = ay-by;
    B = bx-ax;
    C = ay*bx - ax*by;
    ll n; cin >> n;
    using Pld = pair<ld,ld>;
    vector<Pll> xy(n);
    rep(i,n){
        ll x,y; cin >> x >> y;
        xy[i] = {x, y};
    }
    // debug(A);debug(B);debug(C);
    ll cnt = 0;
    auto check = [](Pll a, Pll b, Pll c, Pll d){
        ll tc1 = (a.first - b.first) * (c.second - a.second) + (a.second - b.second) * (a.first - c.first);
        ll tc2 = (a.first - b.first) * (d.second - a.second) + (a.second - b.second) * (a.first - d.first);
        ll td1 = (c.first - d.first) * (a.second - c.second) + (c.second - d.second) * (c.first - a.first);
        ll td2 = (c.first - d.first) * (b.second - c.second) + (c.second - d.second) * (c.first - b.first);
        return (tc1 * tc2 < 0) && (td1 * td2 < 0);
    };
    rep(i,n){
        ll x1 = xy[i].first, x2 = xy[i].second;
        ll next = i+1;
        if(i == n-1)next = 0;
        ll y1 = xy[next].first, y2 = xy[next].second;
        if(check(Pll(ax,ay), Pll(bx,by), xy[i], xy[next]))cnt++;
    }
    cout << cnt / 2 + 1 << endl;
}