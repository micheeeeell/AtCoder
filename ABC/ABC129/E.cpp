#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#define rep(i,x) for(int i = 0; i < x; i++)
typedef long long ll;
const ll N = 1e9 + 7;
using namespace std;

ll dp[100005][2] = {0};
int main(){
    string l;cin >> l;
    int L = l.size();
    dp[0][0] = 1;
    int small = 1;//small = 1 なら未満確定
    rep(i,L){
        rep(small,2){
            if(l[i] == '0') {
                if(small == 1){
                    dp[i+1][small] += dp[i][small]*3 % N;
                }
                else{
                    dp[i+1][small] += dp[i][small] % N;                
                    }
            }
            else{
                if(small == 1){
                    dp[i+1][small] += dp[i][small]*3 % N;
                    dp[i+1][small] += dp[i][0] % N;
                }
                else{
                    dp[i+1][small] += dp[i][small]*2 % N;
                }
            }
        }
    }
    int ans = (dp[L][1] + dp[L][0]) % N;
    cout << ans << endl;
}