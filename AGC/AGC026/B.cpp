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
    ll t; cin >> t;
    vector<ll> a(t),b(t),c(t),d(t);
    rep(i,t)cin >> a[i] >> b[i] >> c[i] >> d[i];
    bitset<n_max> ans(0);
    rep(i,t){
        
        if(d[i] % b[i] == 0){
            ans[i] = (a[i] >= b[i] && a[i]%b[i] <= c[i]);
            // debug(a[i]);debug(a[i]%b[i]);
        }
        else if(d[i] < b[i]){
            ans[i] = 0;
        }
        else{
            ll step = d[i] % b[i];
            ll f = a[i] % b[i];
            ll g = euclid_gcd(b[i], step);
            ll jud = b[i] - (g - f%g);
            if(jud == b[i])jud -= step;
            ans[i] = (jud <= c[i] && a[i] >= b[i] && f <= c[i]);
        }
    }
    rep(i,t)cout << (ans[i] ? "Yes" : "No") << endl;
}