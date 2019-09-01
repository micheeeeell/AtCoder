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
    int n; cin >> n;
    vector<int> c(n);
    rep(i,n) cin >> c[i];
    vector<int> LIS(n, INT_MAX);
    ll INF = INT_MAX;
    rep(i,n){
        auto itr = lower_bound(LIS.begin(), LIS.end(), c[i]);
        *itr = c[i];
    }
    int lis_len = (lower_bound(LIS.begin(), LIS.end(),INF) - LIS.begin());
    cout << n - lis_len << endl;
    return 0;
}