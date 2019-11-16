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
    ll n,c; cin >> n >> c;
    ll t_max = 1e5 + 10;
    vvl vec(c,vl(t_max,0));
    rep(i,n){
        ll s,t; cin >> s >> t;
        ll ct; cin >> ct;
        s--;t--;ct--;
        vec[ct][s]++;
        vec[ct][t+1]--;
    }
    rep(i,c)rep(j,t_max-1){
        vec[i][j+1] += vec[i][j]; 
    }
    ll res = 0;
    rep(j,t_max){
        ll temp = 0;
        rep(i,c){
            if(vec[i][j])temp++;
        }
        res = max(res, temp);
    }
    cout << res << endl;
}