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
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll n,m,c; cin >> n >> m >> c;
    vector<ll> b(m);
    rep(i,m) cin >> b[i];
    vvl a(n,vector<ll>(m,0));
    rep(i,n)rep(j,m){
        cin >> a[i][j];
    }

    ll res = 0;
    rep(i,n){
        ll temp = 0;
        rep(j,m)temp += b[j] * a[i][j];
        temp += c;
        if(0 < temp)res++;
    }
    cout << res << endl;
}