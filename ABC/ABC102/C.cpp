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
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
        a[i] -= i+1;
    }
    sort(all(a));
    ld left = a[0];
    ld right = a[n-1];
    
    auto func = [&](auto x){
        ld ret = 0;
        rep(i,n)ret += abs(a[i] - x);
        return ret;
    };
    rep(i,100){
        ld t1 = (2*left + right) / 3;
        ld t2 = (left + 2*right) / 3;
        if(func(t1) < func(t2))right = t2;
        else left = t1;
    }
    
    ll ret = round(func(left));
    cout << ret << endl;
}