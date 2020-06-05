#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define rrep(i,x) for(ll i = (ll)(x)-1;0 <= i; i--)
#define reps(i,x) for(ll i = 1; i < (ll)(x)+1; i++)
#define rreps(i,x) for(ll i = (ll)(x); 1 <= i; i--)
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
const int n_max = 1e5+10;
#define int ll



// const int INF = INT_MAX;
// int dp[n_max] = {};

// Longest Increase S..?
//狭義のLIS(同じ数は一度だけ)
vector<ll> N_LIS(vector<int> a){
    vector<ll> dp(n_max, INF);
    // fill(all(dp), INF);
    int n = a.size();
    for(int i = 0; i < n; i++){
        *lower_bound(all(dp), a[i]) = a[i];
    }
    cout << lower_bound(all(dp), INF) - dp.begin() << endl;
    return dp;
}

//広義のLIS（同じ数は何度でも）
vector<ll> B_LIS(vector<int> a){
    vector<ll> dp(n_max, INF);
    // fill(all(dp), INF);
    int n = a.size();
    for(int i = 0; i < n; i++){
        *upper_bound(all(dp), a[i]) = a[i];
    }
    cout << upper_bound(all(dp), INF) - dp.begin() << endl;
    return dp;
}

// Longest Decrease S..?
//狭義のLDS
vector<ll> N_LDS(vector<int> a){
    // fill(dp, dp + n_max, INF);
    reverse(all(a));
    return N_LIS(a);
}

//広義のLDS
vector<ll> B_LDS(vector<int> a){
    reverse(all(a));
    return B_LIS(a);
}


signed main(){
    int n;cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    B_LDS(a);
    return 0;   
}