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
    ll n; cin >> n;
    ll l = 1, r = 1;
    ll ans = 0;
    rep(i,n){
        ll t,a; cin >> t >> a;
        ll nl = (t + l - 1) / t;
        ll nr = (a + r - 1) / a;
        ans = max(nl, nr) * (t + a);
        l = (ans / (t+a)) * t ;
        r = (ans / (t+a)) * a;
    }

    cout << ans << endl;
}