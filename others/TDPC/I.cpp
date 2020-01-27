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
const int n_max = 330;

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

vector< vector <ll>> memo(n_max, vector<ll>(n_max,-1));
ll solve(string &s, int l, int r) {   
    if(memo[l][r] != -1)return memo[l][r];
    if(r - l < 3)return memo[l][r] = 0;
    ll res = 0;
    rep(i,4){
        if(solve(s, l+i, r-3+i) != r-l-3)continue;
        string t = s.substr(l, i) + s.substr(r-3+i, 3-i);
        if(t == "iwi")return memo[l][r] = r-l;
    }
    rep(i,r-l-1){
        chmax(res, solve(s, l, l+i+1) + solve(s, l+i+1, r));
    }

    return memo[l][r] = res;
}

int main(){
    string s;cin >> s;
    ll n = s.size();

    cout << solve(s,0,n)/3 << endl;
}