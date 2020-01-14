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


template <class T, class U>
ll euclid_gcd(T a, U b){
    if(a < b)return euclid_gcd(b,a);
    ll r;
    while((r = a%b)){
        a = b;
        b = r;
    }
    return b;
}

int main(){
    ll n,m; cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) {
        cin >> a[i];
        a[i]/= 2;
    }
    ll ans = 0;
    ll lcm = 1;
    bool ok = true;
    rep(i,n){
        ll g = euclid_gcd(lcm, a[i]);
        lcm *= a[i] / g;
    }
    rep(i,n){
        ll t = lcm / a[i];
        if(t % 2 == 0)ok = false;
    }
    if(ok){
        ans = m/lcm;
        ans = (ans + 1) / 2;
    }
    
    cout << ans << endl;
}