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
const ll N = 1e5+7;
const int n_max = 1e9;



int main(){
    ll s; cin >> s;

    ll x2 = 1e9, y2 = 1;
    ll y3,x3;
    // y3 = (s / x2) + 1;
    // if(1e9 < y3)y3= 1e9;
    y3 = ceil(ld(s) / ld(x2)); 
    x3 = y3 * x2 - s;
    cout << "0 0 1000000000 1 " << x3  << ' ' << y3 << endl;
    // cout << endl;
    return 0;

}