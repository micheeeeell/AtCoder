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
const int n_max = 1e5+10;

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

int main(){
    ll n,m; cin >> n >> m;
    vector<string> s(m);
    vector<ll> c(m);
    vector<vector<ll>> dp(m+1,vector<ll>(1100,INF));
    rep(i,m){
        cin >> s[i] >> c[i];
    }
    dp[0][0] = 0;
    auto s2int = [&](string s){
        ll ret = 0;
        ll t = 1;
        rep(i,n){
            if(s[i] == 'Y')ret += t;
            t *= 2;
        }
        return ret;
    };
    // debug(s2int("NNN"));
    // debug(3|5);
    rep(i,m){
        rep(j,pow(2,n)){
            if(dp[i][j] != INF){
                // debug(i);debug(j);
                // debug(dp[i][j]);
                chmin(dp[i+1][j], dp[i][j]);
                dp[i+1][j|(s2int(s[i]))] = min(dp[i+1][j|(s2int(s[i]))], dp[i][j] + c[i]);
            }
        }
    }
    cout << (dp[m][pow(2,n)-1] == INF ? -1 : dp[m][pow(2,n)-1]) << endl;
}