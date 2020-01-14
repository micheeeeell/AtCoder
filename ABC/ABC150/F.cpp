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

int main(){
    ll n; cin >> n;
    int a[n*2];
    rep(i,n) cin >> a[i];
    int b[n];
    rep(i,n) cin >> b[i];
    rep(i,n)a[n+i] = a[i];
    random_device rnd;
    mt19937 mt;
    mt.seed(rnd());
    auto check = [&](ll k, ll x) -> bool{
        ll cnt = 0;
        ll t;
        while (cnt < 1000)
        {
            t = mt() % n;
            // debug(t);debug(a[(t + k) % n] ^ b[t]);debug(x);
            // debug(a[(t + k) % n] ^ b[t] != x);
            if((a[t+k] ^ b[t]) != x)return false;
            cnt++;
        }
        return true;
    };
    auto check_all = [&](ll k){
        // bool ok = true;
        ll x = a[0+k]^b[0];
        rep(i,n)if((a[i+k] ^ b[i]) != x)return false;
        return true;
    };
    
    vector<Pll> vec;
    rep(k,n){
        ll x = a[0+k] ^ b[0];
        if(check(k,x)){
            vec.emplace_back(Pll(k,x));
        }
    }

    for(auto i : vec){
        cout << i.first << " " << i.second << "\n";
    }
    
}