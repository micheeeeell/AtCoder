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

ll XOR(ll x){
    if(x % 4 == 3)return 0;
    ll temp = (x/4)*4;
    ll res = 0;
    rep(i,(x-temp+1)) res ^= (temp+i);
    return res;
}

int main(){
    // cout << XOR(14) << endl;
    ll a,b; cin >> a >> b;
    cout << (XOR(a-1) ^ XOR(b)) << endl;
    return 0;
}
