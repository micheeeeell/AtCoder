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
    ll n,m; cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> sum(n+1,0);
    sort(all(a));
    rep(i,n)sum[i+1] = sum[i] + a[i];
    auto check = [&](ll x){
        bool ret = false;
        ll count = 0;
        rep(i,n){
            count += a.end() - lower_bound(all(a), x-a[i]);
        }
        if(m <=count)ret = true;
        // debug(x);debug(count);
        return ret;
    };
    ll ok = 0;
    ll ng = 1e6;
    while(abs(ok - ng) > 1){
        ll x = (ok + ng) / 2;
        if(check(x))ok = x;
        else ng = x;
    }
    // debug(ok);
    ll count = 0;
    ll ans = 0;
    rep(i,n){
        auto itr = upper_bound(all(a), ok- a[i]);
        count += a.end() - itr;
        ll index = itr - a.begin();
        ans += sum[n] - sum[index];
        ans += a[i] * (a.end() - itr);
    }
    if(count < m)ans += ok * (m - count);
    cout << ans << endl;
}