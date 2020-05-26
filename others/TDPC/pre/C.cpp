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
const int n_max = 1e5+10;

ld win(int p, int q, vector<ld> &rate){
    ld r1 = rate[p];
    ld r2 = rate[q];
    return 1.0 / (1.0 + pow(10, (r2-r1)/400.0));
}

vector<ld> solve(int l, int r, vector<ld>& rate) {
    if(r - l == 1)return {1.0};

    int m = (l + r)/2;
    auto left = solve(l,m,rate);
    auto right = solve(m,r,rate);

    ll len = (r - l)/2;
    vector<ld> res(len * 2, 0);
    rep(i,len)rep(j,len){
        res[i] += left[i] * right[j] * win(l+i,l+len+j, rate);
        res[i+len] += left[j] * right[i] * win(l+i+len, l+j, rate);
    }
    
    return res;
}

int main(){
    ll k; cin >> k;
    vector<ld> rate((1LL << k));
    rep(i,(1LL << k)) cin >> rate[i];
    vector<ld> ans = solve(0, (1LL<<k), rate);
    cout << fixed << setprecision(10);
    rep(i,(1LL << k)){
        cout << ans[i] << "\n";
    }
}