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


template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

int main(){
    ll n; cin >> n;
    vector<ll> a(n);
    ll ma = 0;
    rep(i,n) {cin >> a[i];chmax(ma,a[i]);}
    ll cnt = 0;
    bool ok = true;
    rep(i,n){
        if(a[i] == ma)cnt++;
        if(a[i] < ma-1)ok = false;
    }
    if(ma == n-1){
        if(cnt != n && cnt != 2)ok = false;
    }
    else if(n / ma == 1){
        if(n-cnt < ma-(n%ma) || ma-1 < n-cnt)ok = false;
    }
    else{
        if(ma-1 < n-cnt)ok = false;
    }

    cout << (ok ? "Yes" : "No") << endl;

}