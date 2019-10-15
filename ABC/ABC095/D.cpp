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
    ll n,c; cin >> n >> c;
    vector<ll> x(n), v(n);
    vector<ll> sum_right(n+1), sum_left(n+1);
    rep(i,n){
        cin >> x[i] >> v[i];
        sum_right[i+1] = sum_right[i] + x[i];
    }


    // 往復しない
    ll res = 0;
    rep(i,n){
        res = max(sum_right[i] - x[i], res);
        res = max(sum_right[n] - sum_right[n-i-1] - x[n-i-1], res);
    }

    // 往復する
    vector<ll> f(n), f_max(n);
    ll tmp_max = 0;
    rep(i,n){
        ll tmp = sum_right[i+1] - sum_right[0] - x[i];
        tmp_max = max(tmp_max, tmp);
        f_max[i] = tmp_max;
    }

    rep(i,n){
        
    }
}