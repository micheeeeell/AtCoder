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
    ll h,w,n; cin >> h >> w >> n;
    ll sr,sc; cin >> sr >> sc;

    string t,a; cin >> t >> a;

    bool ok = false;
    ll pos,end;
    pos = sc;end = 0;
    rep(i,n){
        if(t[i] == 'L')pos--;
        if(pos == end){ok = true; break;}
        if(a[i] == 'R' && pos < w)pos++;
        // debug(pos);
    }
    debug(ok);
    pos = sc;end = w+1;
    rep(i,n){
        // ll pos = sc, end = w+1;
        if(t[i] == 'R')pos++;
        if(pos == end){ok = true; break;}
        if(a[i] == 'L' && 1 < pos)pos--;
    }
    debug(ok);
    pos = sr;end = 0;
    rep(i,n){
        // ll pos = sr, end = 0;
        if(t[i] == 'U')pos--;
        if(pos == end){ok = true; break;}
        if(a[i] == 'D' && pos < h)pos++;
    }
    pos = sr;end = h+1;
    debug(ok);
    rep(i,n){
        // ll pos = sr, end = h+1;
        if(t[i] == 'D')pos++;
        if(pos == end){ok = true; break;}
        if(a[i] == 'U' && 1 < pos)pos--;
    }
    debug(ok);

    cout << (ok ? "NO" : "YES") << endl;
}