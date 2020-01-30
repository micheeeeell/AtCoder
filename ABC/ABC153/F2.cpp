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
    ll n,d,a; cin >> n >> d >> a;
    vector<Pll> mon(n);
    rep(i,n){
        ll x,h; cin >> x >> h;
        mon[i] = Pll(x,h);
    }
    sort(all(mon));
    vector<ll> imos(n+1,0);
    vector<ll> X(n), H(n);
    rep(i,n){
        X[i] = mon[i].first;
        H[i] = mon[i].second;
    }
    ll ans = 0;
    ll damage = 0;
    rep(i,n){
        damage += imos[i];
        if(H[i] - damage <= 0)continue;
        ll num = (H[i] - damage + a - 1) / a;
        ans += num;
        ll ed = upper_bound(all(X), X[i] + 2 * d) - X.begin();
        damage += num * a;
        imos[ed] -= num * a;
    }

    cout << ans << endl;

}