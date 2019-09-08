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

void print() {
    cout << endl;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
    cout << head;
    if (sizeof...(tail) != 0) cout << ' ';
    print(forward<Tail>(tail)...);
}

template <class T>
void print(vector<T> &vec) {
    for (auto& a : vec) {
        cout << a;
        if (&a != &vec.back()) cout << ' ';
    }
    cout << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
    for (auto& vec : df) {
        print(vec);
    }
}


int memo[10][3][10] = {};
int dfs(int x, int ok, int max_n, int len){
    // assert(max_n < len);
    // print(x,ok,max_n,len);
    // ll return 0;
    int start = max_n-len+1;
    if(len == 1 && ok <= 1)return 1;
    // if(memo[x][ok][max_n])return memo[x][ok][max_n];
    if(ok == 2)return dfs(x,0,max_n,len) + dfs(x,1,max_n,len);
    if(x == start && ok == 0)return dfs(x + 1,2,max_n, len-1);
    if(x == start && ok == 1)return dfs(x + 1,0,max_n, len-1);
    if(x == max_n && ok == 0)return dfs(max_n-1,2,max_n-1, len-1);
    if(x == max_n && ok == 1)return dfs(max_n-1,0,max_n-1, len-1);
    if(ok == 1)return dfs(x+1,0,max_n, max_n - x) * dfs(x-1,0,x-1, x-start);
    else return dfs(x+1,2,max_n,max_n-x) * dfs(x-1,2,x-1,x-start);

    // memo[x][ok][max_n] = res;
    // return res;
}

int main(){
    ll h,w; cin >> h >> w;
    ll k; cin >> k;
    if(w == 1){
        print(1);
        return 0;
    }
    w--;k--;
    // int dp[10][h] = {};
    // vector<vector<ll>> dp(10,vector<ll>(h+10));
    // cout << dfs(0,0,1) << endl;
    ll dp[w+10][h+10] = {};
    dp[0][0] = 1;
    rep(j,h+1){
        // cout << "test" << endl;
        if(!j)continue;
        rep(i,w+1){
            // cout << 1 << endl;
            if(i == 0)dp[i][j] = (dp[i][j-1] * dfs(0,0,w-1,w) + dp[i+1][j-1] * dfs(0,1,w-1,w))%MOD;
            else if(i == w)dp[i][j] = (dp[i][j-1] * dfs(i-1,0,w-1,w) + dp[i-1][j-1] * dfs(i-1,1,w-1,w))%MOD;
            else{
                // print(i,j,dp[i][j]);
                dp[i][j] += (dp[i-1][j-1] * dfs(i-1,1,w-1,w))%MOD;
                // print(i,j,dp[i][j]);
                dp[i][j] += (dp[i][j-1] * dfs(i-1,0,i,i) * dfs(i,0,w-1,w-i))%MOD;
                // print(i,j,dp[i][j]);
                dp[i][j] += (dp[i+1][j-1] * dfs(i,1,w-1,w))%MOD;
                // print(i,j,dp[i][j]);
            }
            // cout << 1 << endl;
            dp[i][j] %= MOD;
        }
    }
    // print(dfs(7,1,7,4));

    // rep(j,h+1){
    //     rep(i,w+1)cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    cout << dp[k][h] << endl;


    return 0;
}