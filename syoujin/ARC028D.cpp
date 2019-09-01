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
const int n_max = 2020;
const int m_max = 2020;
int main(){
    int n,m,q;cin >> n >> m >> q;
    vi a(n);
    rep(i,n){
        cin >> a[i];
    }
    vector<P> query(q);
    rep(i,q){
        int a,b;
        cin >> a >> b;
        query[i] = P(a,b);
    }
    // ll dp[n_max][m_max] = {}, dp2[n_max][m_max] = {};
    vector<vector<ll>> dp(n_max,vector<ll>(m_max,0));
    vector<vector<ll>> dp2(n_max,vector<ll>(m_max,0));
    dp[0][0] = 1;dp2[0][0] = 1;
    rep(i,n+1){
        if(!i)continue;
        rep(j,m+1){
            if(j == 0){
                dp[i][j] = 1;
                continue;
            }
            if(j-1-a[i-1] >= 0){
                dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1-a[i-1]]+MOD;
            }
            else dp[i][j] = dp[i][j-1] + dp[i-1][j];
            dp[i][j] %= MOD;
        }
    }
    //dp2 = dp;
    rep(i,n){
        rep(j,m+1){
            if(j == 0){
                dp2[i][j] = 1;
                continue;
            }
            if(j-1-a[i] >= 0){
                dp2[i][j] = dp[n][j] - dp[n][j-1] + dp2[i][j-1-a[i]]+MOD;
            }
            else dp2[i][j] = dp[n][j] - dp[n][j-1]+MOD;
            dp2[i][j] %= MOD;
        }
    }
    // rep(i,n+1){
    //     rep(j,m+1) cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    // cout << endl;
    // rep(i,n+1){
    //     rep(j,m+1) cout << dp2[i][j] << " ";
    //     cout << endl;
    // }
    rep(i,q){
        int k = query[i].first,x = query[i].second;
        k--;
        cout << dp2[k][m-x] << endl;
    }
    return 0;
}