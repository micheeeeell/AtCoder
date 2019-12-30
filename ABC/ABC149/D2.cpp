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
    ll n,k; cin >> n >> k;
    ll r,s,p; cin >> r >> s >> p;
    string t;cin >> t;
    vector<ll> vec(n);
    rep(i,n){
        if(t[i] == 'r')vec[i] = 1;
        if(t[i] == 's')vec[i] = 2;
        if(t[i] == 'p')vec[i] = 3;
    }
    auto f = [&](ll x) -> ll{
        if(x == 1)return p;
        if(x == 2)return r;
        if(x == 3)return s;
        return 0;
    };
    rep(i,n){
        if(i < k)continue;
        if(vec[i-k] == vec[i])vec[i] = 0;
    }
    ll sum = 0;
    rep(i,n)sum += f(vec[i]);
    cout << sum << endl;
}
