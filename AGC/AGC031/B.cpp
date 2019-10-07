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
const int n_max = 1e5+10;
void add (ll &a, ll &b){
    a += b;
    if(a >= MOD) a-= MOD;
}
int main(){
    int n; cin >> n;
    vector<ll> c(n);
    rep(i,n) cin >> c[i];
    vector<ll> dp(220000, 0);
    vector<int> place[210000];
    rep(i,n){
        place[c[i]].push_back(i);
    }
    dp[0] = 1;
    rep(i,n+1){
        if(!i)continue;
        
        add(dp[i], dp[i-1]);

        int color = c[i-1];
        int it = lower_bound(place[color].begin(), place[color].end(), i-1) - place[color].begin();
        if(it > 0){
            int j = place[color][it-1];
            if((i-1) - j > 1)add(dp[i], dp[j+1]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}