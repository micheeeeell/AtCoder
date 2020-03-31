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
    ll t,n; cin >> t >> n;
    priority_queue<Pll, vector<Pll>, greater<Pll> > pq;
    rep(i,n){
        ll a; cin >> a;
        pq.emplace(a,0);
    }
    ll m; cin >> m;
    rep(i,m){
        ll b; cin >> b;
        pq.emplace(b,1);
    }
    queue<ll> que;
    bool ok = true;
    while(!pq.empty()){
        auto p = pq.top();pq.pop();
        if(!p.second)que.emplace(p.first);
        else{
            ll tmp = -1;
            while(!que.empty()){
                tmp = que.front();que.pop();
                if(p.first - tmp <= t)break;
            }
            if(tmp == -1 || p.first - tmp > t)ok = false;
        }
    }

    cout << (ok ? "yes" : "no") << endl;
}