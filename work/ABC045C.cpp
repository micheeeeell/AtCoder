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
int count = 0;


// int dfs(int i, bool use){
//     if(i == s.size()+1){
        
//     }
// }
int main(){
    string s; cin >> s;
    int two = 1;
    rep(i,s.size()) two *= 2;
    ll ans = 0;
    for (int i = 0; i < (1 << (s.size()-1));i++){
        // string temp = s;
        ll cur = 0,sum =0;
        rep(j,s.size()){
            if(j > 0 && (i & (1 << (j-1)))){
                sum += cur;
                cur = 0;
            }
            cur = cur * 10 + (s[j] - '0');
        }
        sum += cur;
        ans += sum;
    }

    cout << ans << endl;
}