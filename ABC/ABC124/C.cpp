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

int main(){
    string s;cin >> s;
    int n = s.size();
    string judge[2];
    judge[0].push_back('0');judge[1].push_back('1');
    rep(i,n){
        if(!i)continue;
        rep(j,2){
            if(judge[j][i-1] == '0')judge[j].push_back('1');
            else judge[j].push_back('0');
        }
    }
    int ans = n+10;
    rep(i,2){
        int temp = 0;
        rep(j,n){
            if(s[j] != judge[i][j])temp++;
        }
        ans = min(ans, temp);
    }
    cout << ans << endl;
    return 0;
}