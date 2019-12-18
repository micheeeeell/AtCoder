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
    rep(i,n){
        ll D,E,F;
        ll a = xy[i].first, b = xy[i].second;
        ll next = i+1;
        if(i == n-1)next = 0;
        ll c = xy[next].first, d = xy[next].second;
        D = b-d; E = c-a; F = b*c - a*d;
        // debug(a);debug(b);debug(c);debug(d);
        // debug(D);debug(E);debug(F);
        if(A*E == D*B)continue;
        ld x = ld(C*E - F*B) / ld(A*E - D*B);
        ld y = ld(A*F - C*D) / ld(A*E - D*B);
        if(min(a,c) <= x && x <= max(a,c) && min(b,d) <= y && y <= max(b,d))cnt++;
        // debug(x);
        // debug(y);
        // debug(a);
        // debug(c);
    }
    cout << cnt / 2 + 1 << endl;
}