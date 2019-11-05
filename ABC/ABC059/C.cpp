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

ll solve(int n,vector<ll> vec, int a = 1){
    ll sm = 0;
    ll res = 0;
    rep(i,n){
        sm += vec[i];
        if(sm == 0 || a != sm / abs(sm)){
            res += abs(sm - a);
            sm = a;
        }
        a *= (-1);
    }
    return res;
}
int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n)cin >> a[i];
    cout << min(solve(n,a,1), solve(n,a,-1)) << endl;
    return 0;
}