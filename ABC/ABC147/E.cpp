#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define debug(x) cerr << #x << ": " << (x) << "\n";
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
const ll INF = LLONG_MAX/4;
const ll MOD = 1e9+7;
const int n_max = 1e5+10;

int main(){
    ll h,w; cin >> h >> w;
    vector<vector<ll>> a(h,vl(w)), b(h,vl(w));
    rep(i,h)rep(j,w)cin >> a[i][j];
    rep(i,h)rep(j,w)cin >> b[i][j];
    vvl sub(h,vl(w));
    rep(i,h)rep(j,w)sub[i][j] = abs(a[i][j] - b[i][j]);
    const int r_max = 13000;
    bitset<r_max> bs(0);
    vector<vector<bitset<r_max>>> dp(2,vector<bitset<r_max>>(w,bs));
    dp[0][0][sub[0][0]] = 1;
    rep(i,h)rep(j,w){
        rep(k,r_max){
            if(dp[i%2][j][k]){
                if(j+1 < w)dp[i%2][j+1][k + sub[i][j+1]] = 1;
                if(j+1 < w)dp[i%2][j+1][abs(k - sub[i][j+1])] = 1;
                if(i+1 < h)dp[(i+1)%2][j][k + sub[i+1][j]] = 1;
                if(i+1 < h)dp[(i+1)%2][j][abs(k - sub[i+1][j])] = 1;
            }
        }
        // debug(i);
        // debug(j);
        // debug(dp[i][j]);
       if(i < h-1 || j < w-1) dp[i%2][j] = bs;
    }


    ll res = r_max;
    rep(i,r_max){
        if(dp[(h-1)%2][w-1][i]){
            res = i;
            break;
        }
    }
    cout << res << endl;
}