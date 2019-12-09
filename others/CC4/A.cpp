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
    int n,b1; cin >> n >> b1;
    int b2,b3; cin >> b2 >> b3;
    vvi l(n,vi(n,0));
    vvi r(n,vi(n,0));
    rep(i,n)rep(j,n){
        cin >> l[i][j];
    }
    rep(i,n)rep(j,n){
        cin >> r[i][j];
    }
    vvi ans(n,vi(n,0));
    int temp[3] = {};
    rep(i,n)rep(j,n){
        if(l[i][j] == r[i][j])ans[i][j] = l[i][j];

    }
}