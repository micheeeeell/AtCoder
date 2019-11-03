#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(int i = 0; i < x; i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
const ll MOD = 1e9+7;
const int n_max = 1e5+10;

int main(){
    int n; cin >> n;
    string s1;cin >> s1;
    string s2;cin >> s2;
    vector<ll> dp(n+5);
    vector<int> typ(n+1);
    typ[0] = 0;
    rep(i,n){
        if(s1[i] == s2[i])typ[i+1] = 1;
        else if(i > 0 && s1[i-1] == s1[i])typ[i+1] = 3;
        else typ[i+1] = 2;
    }
    dp[0] = 1;
    rep(i,n+1){
        if(typ[i] == 0){
            if(typ[i+1] == 1)dp[i+1] = dp[i] * 3;
            else dp[i+1] = dp[i] * 6;
        }
        else if(typ[i] == 1){
            if(typ[i+1] == 1)dp[i+1] = dp[i] * 2;
            if(typ[i+1] == 2)dp[i+1] = dp[i] * 2;
        }
        else if(typ[i] == 2)dp[i+1] = dp[i];
        else if(typ[i] == 3){
            if(typ[i+1] == 1)dp[i+1] = dp[i];
            if(typ[i+1] == 2)dp[i+1] = dp[i] * 3;
        }
        dp[i] %= MOD;
        // cout << dp[i] << endl;
    }
    cout << dp[n] << endl;
    return 0;
}