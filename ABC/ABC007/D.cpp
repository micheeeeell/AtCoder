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
const ll INF = LLONG_MAX/4;
const ll MOD = 1e9+7;
const int n_max = 1e5+10;


int main(){
    ll al, bl;cin >> al >> bl;
    al--;
    string a,b;
    a = to_string(al);b = to_string(bl);
    auto fb = [&](string s){
        ll n = s.size();
        // dp[i][small][is_forbidden]
        vvvl dp(n+1,vvl(2,vl(2,0)));
        dp[0][0][0] = 1;
        rep(i,n){
            rep(small,2){
                if(!small){
                    ll t = s[i] - '0';
                    rep(j,t){
                        if(j != 4 && j != 9)dp[i+1][1][0] += dp[i][small][0];
                        else dp[i+1][1][1] += dp[i][small][0];
                        dp[i+1][1][1] += dp[i][small][1];
                    }
                    if(t != 4 && t != 9 && dp[i][small][0])dp[i+1][small][0] = dp[i][small][0];
                    else dp[i+1][small][1] = dp[i][small][0] + dp[i][small][1];
                }
                else{
                    rep(j,10){
                        if(j != 4 && j != 9)dp[i+1][1][0] += dp[i][small][0];
                        else dp[i+1][1][1] += dp[i][small][0];
                        dp[i+1][1][1] += dp[i][small][1];
                    }
                }
            }
        }
        // rep(i,2)rep(j,2)debug(dp[1][i][j]);
        // rep(i,2)rep(j,2)debug(dp[2][i][j]);
        return dp[n][0][1] + dp[n][1][1];
    };
    debug(fb(a));
    debug(fb(b));
    cout << (fb(b) - fb(a)) << endl;
}