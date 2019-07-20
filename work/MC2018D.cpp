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
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
const ll N = 1e9+7;
const int n_max = 1e5+10;

int main(){
    int n,m,l,x;cin >> n >> m >> l >> x;
    vector<int> a(n);
    rep(i,n)cin >> a[i];
    // ll dp[10100][1010] = {};
    vvi dp(10100, vector<int>(1010,0));
    dp[0][0] = 1;
    rep(i,n){
        rep(j,m){
            if(dp[i][j]){
                dp[i+1][j] = dp[i][j];
                if(dp[i+1][(j+a[i]) % m])dp[i+1][(j+a[i]) % m] = min(dp[i][j] + (j+a[i]) / m, dp[i][(j+a[i]) % m]);
                else dp[i+1][(j+a[i]) % m] = dp[i][j] + (j+a[i]) / m;
            }
        }
    }
    // rep(i,n){
    //     rep(j,m){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    if(dp[n][l] != 0 && dp[n][l] < x) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}