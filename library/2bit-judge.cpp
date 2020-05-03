#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#define rep(i,x) for(int i = 0; i < x; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> ivec;
const ll N = 1e9+7;
 
int main()
{
	int n = 5;
    // for(int i = 0; i < (1 << n);i++){
    //     rep(j,n){
    //         //下からiを判定(i=3 なら順に1，2が出力、i=7なら1，2，4)
    //         // cout << (i & (1 << j)) << endl;
    //         cout  << i  << ' ' << j << ' ' << ( i & (1 << j)) << endl;
    //     }
    // }
    for(int i = 0; i < (1 << n);i++){
        for(int j = n;j >= 0; j--){
            //下からiを判定(i=3 なら順に1，2が出力、i=7なら1，2，4)
            // cout << (i & (i >> j)) << endl;
            cout << i << ' ' << j << ' ' << (1 & (i >> j)) << endl;
            // cout  << i  << ' ' << j << ' ' << (1 << j) << endl;
        }
    }
    // maskの部分集合を全探索できる回し方
    for(ll i=mask; i >= 0; i = (i-1) & mask){}
}