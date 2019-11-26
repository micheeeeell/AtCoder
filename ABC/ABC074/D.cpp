#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(int i = 0; i < (int)(x); i++)
#define pb push_back
#define mp make_pair
#define debug(x) cerr << #x << ": " << (x) << "\n";
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
const ll MOD = 1e9+7;
const int n_max = 1e5+10;

int main(){
    ll n; cin >> n;
    vvl a(n,vl(n));
    rep(i,n)rep(j,n)cin >> a[i][j];

    bool ok = true;
    ll res = 0;
    rep(i,n)rep(j,n){
        if(a[i][j] != a[j][i])ok = false;
    }

    rep(k,n){
        rep(i,n){
            rep(j,n){
                if(a[i][j] > a[i][k] + a[k][j]){
                    ok = false;
                }
            }
        }
    }

    rep(i,n)rep(j,n){
        bool temp = true;
        if(i <= j)continue;
        rep(k,n){
            if(i == k || j == k)continue;
            if(a[i][j] == a[i][k] + a[j][k])temp = false;
        }
        if(temp)res += a[i][j];
    }

    cout << (ok ? res : -1) << endl;


}