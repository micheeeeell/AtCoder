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

int main(){
    ll n,k; cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> sum(n+1, 0);
    rep(i,n)sum[i+1] = sum[i] + a[i];
    const int max_ = 61;
    vector<vector<bitset<max_>>> store(2);
    vector<bitset<max_>> clear;
    rep(i,n){
        for(int j = i + 1; j < n+1; j++){
            bitset<max_> bs(sum[j] - sum[i]);
            store[0].emplace_back(bs);
        }
    }
    ll ans = 0;
    rrep(i, max_){
        for(auto bs : store[i & 1]){
            if(bs[i])store[(i & 1) ^ 1].emplace_back(bs);
        }

        if(store[(i & 1) ^ 1].size() < k){
            store[(i & 1) ^ 1] = store[i & 1];
        }
        else {
            ans += pow(2, i);
        }
        store[i & 1] = clear;
    }

    cout << ans << endl;
}