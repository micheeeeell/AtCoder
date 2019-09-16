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
    ll n; cin >> n;
    string s;cin >> s;
    vector<int> num[26];
    rep(i,n){
        int temp = s[i]-'a';
        num[temp].push_back(i);
    }

    int res = 0;
    rep(i,n){
        int temp = s[i]-'a';
        rep(j,num[temp].size()){
            if(num[temp][j] <= i)continue;
            int k = 0;
            while(s[i+k] == s[num[temp][j]+k] && k < num[temp][j]-i){
                k++;
            }
            
            res = max(res, k);
        }
    }
    cout << res << endl;
    return 0;
}