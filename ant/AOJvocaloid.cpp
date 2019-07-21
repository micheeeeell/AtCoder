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
    int n; cin >> n;
    vector<int> l(n),r(n),p(n);
    int point[400] = {},dp[400] = {};
    rep(i,n) {
        cin >> l[i] >> r[i] >> p[i];
        for(int j = l[i]; j <= r[i]; j++){
            point[j] = max(point[j], p[i]);
        }
    }
    // vector<int> dif(n);
    // rep(i,n) dif[i] = l[i] - s[i] + 1;
    int m; cin >> m;
    vector<int> w(m);
    rep(i,m) {
        cin >> w[i];
    }
    dp[0] = 0;
    rep(i,400){
        for(int j = i; j < 400; j++){
            dp[j] = max(dp[j], dp[j-i] + point[i]);
        }
    }

    vector<int> ans;
    rep(i,m){
        if(!dp[w[i]]){
            cout << -1 << endl;
            return 0;
        }
        else{
            ans.pb(dp[w[i]]);
        }
    }
    rep(i,m){
        cout << ans[i] << endl;
    }
    return 0;

    // bool dp_s[400][400] = {}, dp_l[400][400] = {};
    // dp_s[0][0] = 1;dp_l[0][0] = 1;
    // rep(i,n+1){
    //     if(!i)continue;
    //     rep(j,400){
    //         for(int k = 0;k * s[i-1] <= 400;k++) {
    //             dp_s[i][j] |= dp_s[i-1][j- k * s[i-1]];
    //         }
    //         for(int k = 0;k * l[i-1] <= 400;k++) {
    //             dp_l[i][j] |= dp_l[i-1][j- k * l[i-1]];
    //         }
    //     }
    // }
    // int dp_total[400][400] = {};
    // rep(i,n+1){
    //     // bool ok = false;
    //     if(!i)continue;
    //     rep(j,400){
    //         dp_total[i][0] = 1;
    //         if(j) dp_total[i][j] = dp_total[i][j-1] + dp_s[i][j] - dp_l[i][j-1];
    //     }
    // }

    // rep(i,m){
    //     if(dp[n][w[i]]) cout << dp[n][w[i]] << endl;
    //     else cout << -1 << endl;
    // }


    return 0;

}