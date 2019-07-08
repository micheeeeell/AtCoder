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
    // int two = 1;
    // rep(i,s.size()) two *= 2;
    ll len = s.size();
    ll ans = 0;
    rep(i,(1 << (len-1))){
       ll cur = 0;
       ll sum = 0;
       cur += s[0]-'0';
       rep(j,len-1){
           ll d = s[j+1]-'0';
           if(1 & (i >> j)){
               sum += cur;
               cur = d;
            //    cout << 1 << ' ' << cur << ' ' << sum << endl;
           }
           else{
               cur = cur * 10 + d;
            //    cout << 0 << ' ' << cur << ' ' << sum << endl;
           }
       }
       sum += cur;
       ans += sum;
    }

    cout << ans << endl;
}