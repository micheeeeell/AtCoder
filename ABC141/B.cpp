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
    int len = s.size();
    bool ok = true;
    rep(i,len){
        int temp = i+1;
        if(temp%2){
            if(s[i] == 'L')ok = false;
        }
        else{
            if(s[i] == 'R')ok = false;
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}