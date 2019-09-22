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
const ll N = 1e9+7;
const int n_max = 1e5+10;

int main(){
    string s;cin >> s;
    int len = s.size();
    vector<int> sint(len);
    rep(i,len){
        int temp = s[i] - '0';
        sint[i] = temp;//'?'の時は15
    }
    // cout << '?' - '0' << endl;
    int dp[len+1][13] = {};//is small, length, あまり
    // dp[0][0] = 1;
    rep(i,len){
        if(!i){
            if(sint[i] > 9){
                rep(k,10){
                    dp[i+1][k] = 1;
                }
            }
            else dp[i+1][sint[i]] = 1;
            continue;
        }
        rep(j,13){
            if(sint[i] > 9){
                rep(k,10){
                    dp[i+1][(j * 10+k)%13] = (dp[i+1][(j * 10+k)%13] + dp[i][j]) %N;
                }
            }
            else{
                // cout << i << ' ' << j  << ' ' <<  (j*10+sint[i])%13  << ' ' << dp[i][j]  << ' ' << dp[i+1][(j*10+sint[i]) % 13]<< endl;
                dp[i+1][(j*10+sint[i])%13] = (dp[i+1][(j * 10+sint[i])%13] + dp[i][j]) %N;
            }
            // cout << i << ' ' << j  << ' ' <<  (j*10+sint[i])%13  << ' ' << dp[i][j]  << ' ' << dp[i+1][(j*10+sint[i]) % 13]<< endl;
        }
    }
    // if(!small){
    //     int temp = min(9,sint[i]);
    //     rep(k,temp){
    //         dp[i+1][(j * 10+k)%13] = (dp[i+1][(j * 10+k)/13] + dp[i][0][j]) %N;
    //     }
    //     dp[i+1][(j*10+temp)%13] = (dp[i+1][(j*10+temp)%13] + dp[i][0][j]) % N;
    // }
    // else{
    //     rep(k,10){
    //         dp[i+1][(j * 10+k)%13] = (dp[i+1][(j * 10+k)/13] + dp[i][1][j]) %N;
    //     }
    // }
    // rep(i,len+1){
    //     rep(j,13){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << (dp[len][5]) % N << endl;
    return 0;
}