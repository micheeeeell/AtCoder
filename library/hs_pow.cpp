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
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
const ll N = 1e9+7;
const int n_max = 1e5+10;

ll hs_pow(ll x, ll n){
    ll ret = 1;
    while(0 < n){
        if((n % 2) == 0){
            x *= x;
            n >>= 1;
        }
        else{
            ret *= x;
            n--;
        }
        cout << ret  << ' ' << n  << ' ' << x << endl;
    }
    return ret;
}

int main(){
    ll x,n;cin >> x >> n;
    cout << hs_pow(x,n) << endl;
    cout << LLONG_MAX << endl;
    return 0;
}