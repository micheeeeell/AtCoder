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
const int n_max = 2e5+10;

template<class Container, class T>
ll at_wrap(Container &mp, T v) {
    try {
        return mp.at(v);
    }
    catch(std::out_of_range&) {
        return 0;
    }
}

int main(){
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(all(a), greater<ll>());
    map<ll,ll> mp;
    rep(i,n)mp[a[i]]++;
    ll ans = 0;
    auto pow2 = [](ll x){
        ll res = 1;
        while(res <= x)res *= 2;
        return res;
    };
    rep(i,n){
        if(mp[a[i]] <= 0)continue;
        mp[a[i]]--;
        ll t = pow2(a[i]);
        if(at_wrap(mp, t - a[i]) > 0){
            // debug(t);
            // debug(at_wrap(mp, t - a[i]));
            ans++;
            mp[t-a[i]]--;
        }
        // // debug(a[i]);debug(ans);
    }

    cout << ans << endl;
}