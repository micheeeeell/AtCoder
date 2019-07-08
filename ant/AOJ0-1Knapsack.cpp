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
    int n,w; cin >> n >> w;
    vector<P> vw(n);
    rep(i,n){
        int tv,tw;cin >> tv >> tw;
        vw[i] = P(tv,tw);
    }
    int dp[n+1][w+1] = {};
    // fill(dp[0],dp[0]+w,0);
    rep(i,n){
        rep(j,w+1){ 
            if(vw[i].second <= j) dp[i+1][j] = max(dp[i][j-vw[i].second]+vw[i].first,dp[i][j]);
            else dp[i+1][j] = dp[i][j];
            // cout << dp[i][j] << " ";
        }
        // cout << endl;
    }
    // rep(i,n+1){rep(j,w+1)cout << dp[i][j] << " "; cout << endl;}
    cout << dp[n][w] << endl;
    return 0;
}