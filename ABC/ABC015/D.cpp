#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define rep(i,x) for(int i = 0; i < x; i++)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> ivec;
const ll N = 1e9+7;

int main(){
    int w; cin >> w;
    int n,k; cin >> n >> k;
    int a[n],b[n];
    rep(i,n){
        cin >> a[i] >> b[i];
    }
    // int dp[55][10010][55] = {};
    vector<vector<vector<int>>> dp(55,vector<vector<int>>(10010,vector<int>(55)));
    dp[0][0][0] = 0;
    rep(i,n+1){
        if(i == 0)continue;
        rep(j,10010){
            rep(l,i+1){
                if(l == 0)continue;
                if(j >= a[i-1])dp[i][j][l] = max(dp[i-1][j][l],dp[i-1][j-a[i-1]][l-1] + b[i-1]);
                else dp[i][j][l] = dp[i-1][j][l];

            }
        }
    }
    int ans = 0;
    rep(i,k+1)ans = max(ans,dp[n][w][i]);
    cout << ans << endl;
    // cout << dp[n][w][k] << endl;
    return 0;
}
