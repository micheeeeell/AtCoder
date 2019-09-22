#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#define rep(i,x) for(int i = 0; i < x; i++)
typedef long long ll;
using namespace std;
const ll N = 1e9+7;

int main(){
    int n,l; cin >> n >> l;
    ll sum = 0;
    rep(i,n){
        sum += i;
    }
    sum += l*n;
    ll ans = sum;
    if(l >= 0) ans -= l;
    else if(l < 0 && l + n <= 0) ans -= l + n-1;
    cout << ans << endl;
}