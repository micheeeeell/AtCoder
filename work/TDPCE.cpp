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
    int d; cin >> d;
    string s;cin >> s;
    int len = s.size();
    // ll dp[10010][100][2] = {};
    int n[len+1];
    n[0] = 0;
    rep(i,len){
        n[i+1] = s[i] - '0';
    }
    vector<vector<vector<int>>> dp(10010,vector<vector<int>>(110,vector<int>(2,0)));
     \
    dp[0][0][0] = 1;
    rep(i,len+1){
        if(i == 0)continue;
        // int stemp = s[i-1] - '0';
        rep(small,2){
            rep(k,d){
                if(small){
                    rep(j,10) dp[i][(k+j)%d][small] = (dp[i][(k+j)%d][small] + dp[i-1][k][small]) % N;
                }
                else{
                    rep(j,n[i]){
                        dp[i][(k+j)%d][1] = (dp[i][(k+j)%d][1] + dp[i-1][k][0]) % N;
                    }
                    dp[i][(k+n[i])%d][0] =(dp[i][(k+n[i])%d][0] + dp[i-1][k][0]) % N;
                }
            }
        }
    }
    cout << (dp[len][0][0] + dp[len][0][1] - 1) % N << endl;
    return 0;
}