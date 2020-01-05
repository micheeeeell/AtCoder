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
const int n_max = 620;

int main(){
    ll n; cin >> n;
    string s[n*2];
    rep(i,n)cin >> s[i];
    rep(i,n)s[i] += s[i];
    rep(i,n)s[n+i] = s[i];
    // rep(i,2*n)cout << s[i] << "\n";
    bitset<n_max> bs(0);
    vector<Pll> test(2*n-1);
    rep(i,n) {
        ll sx = n-1-i, sy = 0;
        test[i] = {sx,sy};
    }
    rep(i,n-1){
        ll sx = 0, sy = i+1;
        test[i+n] = {sx,sy};
    }
    rep(i,2*n-1){
        ll sx = test[i].first;
        ll sy = test[i].second;
        string t[n];
        rep(j,n)t[j] = s[sx+j].substr(sy,n);
        bool ok = true;
        rep(j,n)rep(k,n){
            if(t[j][k] != t[k][j]){ok = false;}
        }
        bs[i] = ok;
    }
    ll ans = 0;
    rep(i,2*n-1){
        if(bs[i] == 1)ans += min(i+1,2*n-1-i);
    }
    cout << ans << endl;
}