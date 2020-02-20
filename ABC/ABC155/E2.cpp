#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define rrep(i,x) for(ll i = (ll)(x)-1;i <= 0; i--)
#define reps(i,x) for(ll i = 1; i < (ll)(x); i++)
#define rreps(i,x) for(ll i = (ll)(x)-1; i <= 1; i--)
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
const int n_max = 1e5+10;

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}
void print() {
    cout << endl;
}

int main(){
    string s;cin >> s;
    ll n = s.size();
    vector<vector<ll>> dp(2, vector<ll>(n+1,INF));
    dp[0][0] = 0;
    rep(i,n){
        ll t = s[i] - '0';
        chmin(dp[0][i+1], dp[0][i] + t);
        chmin(dp[1][i+1], dp[0][i] + 10 - t);
        chmin(dp[1][i+1], dp[1][i] + 9 - t);
        chmin(dp[0][i+1], dp[1][i] + t + 1);
    }

    cout << min(dp[0][n], dp[1][n]+1) << endl;
}