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
    int n; cin >> n;
    int p[n];
    rep(i,n)cin >> p[i];
    int dp[105][10010] = {};
    dp[0][0] = 1;
    rep(i,n+1){
        if(i == 0)continue;
        rep(j,10000){
            if(dp[i-1][j]){
                dp[i][j] = 1;
                dp[i][j+p[i-1]] = 1;
                // cout << i  << ' ' << j  << ' ' << p[i] << endl;
            }
        }
    }
    int ans = 0;
    rep(i,10010)if(dp[n][i])ans++;
    cout << ans <<  endl;
    return 0;
}