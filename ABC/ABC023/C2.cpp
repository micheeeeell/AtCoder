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
    ll R,C,k; cin >> R >> C >> k;
    ll n; cin >> n;
    vector<Pll> rc(n);
    vector<ll> rvec(R,0), cvec(C,0), rcnt(k+1,0), ccnt(k+1,0);
    rep(i,n){
        ll r,c; cin >> r >> c;
        r--;c--;
        rc[i] = {r,c};
        rvec[r]++;cvec[c]++;
    }
    rep(i,R)if(rvec[i] <= k)rcnt[rvec[i]]++;
    rep(i,C)if(cvec[i] <= k)ccnt[cvec[i]]++;
    ll ans = 0;
    rep(i,k+1){
        ans += rcnt[i] * ccnt[k-i];
    }

    rep(i,n){
        Pll p = rc[i];
        if(rvec[p.first] + cvec[p.second] == k)ans--;
        if(rvec[p.first] + cvec[p.second] == k+1)ans++;
    }

    cout << ans << endl;
}