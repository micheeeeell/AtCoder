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

ll solve(ll n, ll x, vector<ll> p, vector<ll> sz){
    assert(x <= sz[n]);
    if(x == 0)return 0;
    if(sz[n]-1 <= x)return p[n];
    if(n == 0)return p[n];
    if(x <= 1 + sz[n-1])return solve(n-1, x-1, p, sz);
    if(x == sz[n-1] + 2)return p[n-1] + 1;
    else return p[n-1] + 1 + solve(n-1, x-(sz[n-1]+2), p, sz);
}

int main(){
    ll n,x; cin >> n >> x;
    vector<ll> p(n+1), sz(n+1);
    p[0] = 1;sz[0] = 1;
    rep(i,n+1){
        if(!i)continue;
        p[i] = p[i-1] * 2 + 1;
        sz[i] = sz[i-1] * 2 + 3;
    }

    cout << solve(n,x,p,sz) << endl;
