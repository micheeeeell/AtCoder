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
    int q; cin >> q;
    string x[q],y[q];
    rep(i,q){
        cin >> x[i] >> y[i];
    }
    int ans[q];
    rep(i,q){
        int dp[1010][1010] = {};
        int xlen = x[i].size();
        int ylen = y[i].size();
        // cout << x[i] << ' ' << xlen << ' ' << y[i] << ' ' << ylen << endl;
        dp[0][0] = 0;
        rep(j,xlen+1){
            if(!j)continue;
            rep(k,ylen+1){
                if(!k)continue;
                if(x[i][j-1] == y[i][k-1]) {
                    dp[j][k] = dp[j-1][k-1] + 1;
                    // cout << i  << ' ' << j  << ' ' << k << ' ' <<  dp[j][k] << endl;
                }
                else{
                    dp[j][k] = max(dp[j-1][k],max(dp[j][k-1],dp[j-1][k-1]));
                }
            }
        }
        ans[i] = dp[xlen][ylen];
    }

    rep(i,q) cout << ans[i] << endl;
    return 0;
}