#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define pb push_back
#define eb emplace_back
#define debug(x) cerr << #x << ": " << (x) << "\n";
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
const ll INF = numeric_limits<ll>::max()/4;
const int n_max = 16;

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

vector<ld> memo((1LL << n_max), -1);
ld solve(int mask){
    if(memo[mask] != -1)return memo[mask];
    if(__builtin_popcount(mask) == n_max)return memo[mask] = 0;
    ld res = 0;
    for(int i = 1; i <= 14; i++){
        ld temp = 0, 
    }
}


int main(){
    ll n; cin >> n;
    int mask = 0;
    rep(i,n){
        int x; cin >> x;
        mask |= (1 << x);
    }
}