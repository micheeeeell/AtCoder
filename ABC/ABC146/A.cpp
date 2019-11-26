#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(int i = 0; i < (int)(x); i++)
#define pb push_back
#define mp make_pair
#define debug(x) cerr << #x << ": " << (x) << "\n";
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
const ll MOD = 1e9+7;
const int n_max = 1e5+10;
// SUN,MON,TUE,WED,THU,FRI,SAT

int main(){
    string s;cin >> s;
    int ans = 0;
    if(s == "SUN")ans = 7;
    else if(s == "SAT")ans = 1;
    else if(s == "FRI")ans = 2;
    else if(s == "THU")ans = 3;
    else if(s == "WED")ans = 4;
    else if(s == "TUE")ans = 5;
    else if(s == "MON")ans = 6;
    cout << ans << endl;

}