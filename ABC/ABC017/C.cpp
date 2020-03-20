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

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

int main(){
    ll n,m; cin >> n >> m;
    using Plll = pair<Pll, ll>;
    priority_queue<Plll, vector<Plll>, greater<Plll>> pq;
    ll sum = 0, rmax = 0;
    rep(i,n){
        ll l,r,s; cin >> l >> r >> s;
        l--;
        sum += s;
        pq.emplace(Pll(l, s), 1);
        pq.emplace(Pll(r, s), 0);
        chmax(rmax, r);
    }

    if(rmax < m){cout << sum << endl;return 0;}

    ll ans = 0;
    ll temp = 0;
    rep(i,m){
        Plll p = pq.top();
        while(p.first.first == i){
            pq.pop();
            if(p.second == 1)temp += p.first.second;
            if(p.second == 0)temp -= p.first.second;
            p = pq.top();
        }
        chmax(ans, sum - temp);
    }

    cout << ans << endl;
}