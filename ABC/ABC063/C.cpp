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
    vector<ll> s(n);
    rep(i,n) cin >> s[i];
    vector<ll> dp(11000, 0);
    dp[0] = 1;
    rep(i,n){
        for(int j = 10999; 0 <= j; j--){
            if(j - s[i] >= 0 && dp[j - s[i]])dp[j] = 1;
        }
    }

    ll max_ = 0;
    rep(i,11000)if(i % 10 != 0 && dp[i])chmax(max_, i);
    cout << max_ << endl;
}