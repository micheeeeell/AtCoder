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
    ld a,b,c; cin >> a >> b >> c;
    auto func = [&](ld t) -> ld{
        return a*t + b * sin(M_PI * c*t);
    };
    ld fi = func(1.0/(2*c));
    cout << fixed << setprecision(15);
    if(2*b*c < a){
        ld ok = 100;
        ld ng = 0;
        ll cnt = 0;
        while(cnt < 100){
            ld x = (ok+ng)/2.0;
            if(func(x) >= 100)ok = x;
            else ng = x;
            cnt++;
        }
        cout << ok << endl;
        return 0;
    }

    ll x = 0;
    if(fi < 100){
        x = ceil((100-fi)*c/(2*a));
    }
    ld ok = (ld(1.0)/(2*c) + ld(2*x) / c);
    ld ng = ok - (2/c);
    debug(ok);
    debug(ng);
    debug(func(ok));
    debug(func(ng));
    assert(100 <= func(ok));
    assert(func(ng) < 100);
    ll cnt = 0;
    while(cnt < 100){
        ld t = (ok+ng)/2;
        if(func(t) >= 100)ok = t;
        else ng = t;
        cnt++;
    }
    cout << ok << endl;
}