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
const int n_max = 1e5+10;

int main(){
    ll n; cin >> n;
    vector<ll> x(n),l(n);
    rep(i,n) cin >> x[i] >> l[i];
    priority_queue<Pll, vector<Pll>, greater<Pll>> pq;
    ll ans = 0;
    rep(i,n)pq.push(Pll(x[i]+l[i], x[i]-l[i]));
    ll max_ = -INF;
    while(pq.size()){
        Pll t = pq.top();pq.pop();
        if(max_ <= t.second){
            ans++;
            max_ = t.first;
        }
    }
    cout << ans << endl;
}