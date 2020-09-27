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
#define int ll

signed main(){
    ll w,h; cin >> w >> h;
    ll ans = 0;
    priority_queue<Pll, vector<Pll>, greater<Pll>> pq;
    rep(i,w){
        ll p; cin >> p;
        pq.emplace(p, 0);
    }SCHED_OTHER
    rep(i,h){
        ll q; cin >> q;
        pq.emplace(q, 1);
    }
    h++;w++;
    while(!pq.empty()){
        auto p = pq.top();pq.pop();
        if(p.second == 0){
            ans += h * p.first;
            w--;
        }
        if(p.second == 1){
            ans += w * p.first;
            h--;
        }
    }
    cout << ans << endl;
}