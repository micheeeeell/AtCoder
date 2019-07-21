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
    int n,w_max; cin >> n >> w_max;
    vector<int> v(n),w(n);
    rep(i,n) cin >> v[i] >> w[i];
    int dp[110][10100] = {};
    rep(i,n+1){
        if(!i)continue;
        rep(j,w_max+1){
            if(j >= w[i-1])dp[i][j] = max(dp[i-1][j], dp[i][j-w[i-1]] + v[i-1]);
            else dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[n][w_max] << endl;
    return 0;

}