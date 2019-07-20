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
    ll n,k; cin >> n >> k;
    vector<ll> a(n);
    rep(i,n)cin >> a[i];
    ll a_sum[n] = {};
    rep(i,n){
        if(!i){
            a_sum[i] = a[i];
            continue;
        }
        a_sum[i] = a_sum[i-1] + a[i];
    }
    if(k == a_sum[n-1]){
        cout << 1 << endl;
        return 0;
    }
    // ll dp[2020][2020] = {};
    // long double rate[2020][2020] = {};
    vector<vector<ll> > dp(2020,vector<ll>(2020,0));
    vector<vector<long double> > rate(2020,vector<long double>(2020,0));
    rep(i,n+1){
        if(!i)continue;
        rep(j,i + 1){
            if(!j) continue;
            if(!dp[i-1][j]) {
                if(ceil(rate[i-1][j-1] * a[i-1]) != floor(rate[i-1][j-1] * a[i-1])){
                    dp[i][j] = dp[i-1][j-1] + ceil(rate[i-1][j-1] * a[i-1]);
                }
                else{
                    dp[i][j] = dp[i-1][j-1] + rate[i-1][j-1] * a[i-1] + 1;
                }
            }
            else{
                ll tmp;
                if(ceil(rate[i-1][j-1] * a[i-1]) != floor(rate[i-1][j-1] * a[i-1])){
                    tmp = dp[i-1][j-1] + ceil(rate[i-1][j-1] * a[i-1]);
                }
                else{
                    tmp = dp[i-1][j-1] + rate[i-1][j-1] * a[i-1] + 1;
                }
                dp[i][j] = min(dp[i-1][j],tmp);

            }
            long double dp_temp = dp[i][j];
            long double a_sum_temp = a_sum[i-1];
            rate[i][j] = dp_temp / a_sum_temp;
        }
    }

    // rep(i,n+1){
    //     rep(j,n+1){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // rep(i,n+1){
    //     rep(j,n+1){
    //         cout << rate[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int ans = 0;
    for(int i = n; 0 <= i; i--){
        if(dp[n][i] <= k){
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;

}