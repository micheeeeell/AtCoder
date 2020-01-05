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
    string s;cin >> s;
    reverse(s.begin(), s.begin() + n);
    // debug(s);
    using Ps = pair<string,string>;
    map<Ps, ll> mp;
    rep(i,(1LL << n)){
        string temp, rest;
        rep(j,n){
            if((i >> j) & 1){
                temp += s[j];
            }
            else{
                rest += s[j];
            }
        }
        // debug(temp);debug(rest);
        mp[{temp, rest}]++;
    }
    ll ans = 0;
    rep(i, 1LL << n){
        string temp, rest;
        rep(j,n){
            if((i >> j) & 1)temp += s[n+j];
            else rest += s[n+j];
        }
        if(mp.find({temp, rest}) != mp.end()){
            ans += mp[{temp, rest}];
            // debug(temp);debug(rest);
        }
    }
    cout << ans << endl;
}