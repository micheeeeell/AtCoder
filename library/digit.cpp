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

// xの桁数を返す関数
int digit_max(ll x){
    int dig = 0;
    while(x/pow(10,dig) >= 1)dig++;
    return dig;
}

// xのdigit桁目を返す関数
// 下から順にone-based（感覚に即しているはず）
int digit_num(ll x, int digit){
    assert(digit_max(x) >= digit);
    ll t1 = x/pow(10,digit-1);
    ll t2 = (x/pow(10,digit));
    // print(t1,t2);
    return t1 - t2 * 10;
}

int main(){
    ll n; cin >> n;
    ll digit; cin >> digit;
    cout << digit_num(n,digit) << endl;
    return 0;
}