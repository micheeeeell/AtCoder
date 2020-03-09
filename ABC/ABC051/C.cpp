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
    ll sx,sy; cin >> sx >> sy;
    ll tx,ty; cin >> tx >> ty;
    string ans;
    ll x = tx - sx;
    ll y = ty - sy;
    rep(i, x)ans += 'R';
    rep(i, y)ans += 'U';
    rep(i,x)ans += 'L';
    rep(i,y)ans += 'D';
    
    ans += 'D';
    rep(i,x+1)ans += 'R';
    rep(i,y+1)ans += 'U';
    ans += 'L';
    ans += 'U';
    rep(i,x+1)ans += 'L';
    rep(i,y+1)ans += 'D';
    ans += 'R';

    cout << ans << endl;
}