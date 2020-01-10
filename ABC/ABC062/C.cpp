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

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

int main(){
    ll h,w; cin >> h >> w;
    ll ans = INF;
    rep(i,h-1){
        ll a = (i+1) * w;
        ll b, c;
        b = ((h - (i+1))/2) * w;
        c = h*w - (a+b);
        chmin(ans, max({a,b,c}) - min({a,b,c}));
        b = (w/2) * (h - (i+1));
        c = h*w - (a+b);
        chmin(ans, max({a,b,c}) - min({a,b,c}));
    }
    rep(i,w-1){
        ll a = (i+1) * h;
        ll b, c;
        b = h * ((w - (i+1))/2);
        c = h*w - (a+b);
        chmin(ans, max({a,b,c}) - min({a,b,c}));
        b = (h/2) * (w - (i+1));
        c = h*w - (a+b);
        chmin(ans, max({a,b,c}) - min({a,b,c}));
    }

    cout << ans << endl;
}