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
    vector<ll> p(n);
    rep(i,n) cin >> p[i];
    ll temp = 0;
    ll res = 0;
    rep(i,n){
        if(p[i] == i+1){
            temp++;
        }
        else{
            res += (temp+1)/2;
            temp = 0;
        }
        if(i == n-1)res += (temp+1)/2;
    }
    cout << res << endl;

}