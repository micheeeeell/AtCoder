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
const ll MOD = 1e9+7;
const int n_max = 1e5+10;

int main(){
    ll n,c,k; cin >> n >> c >> k;
    vector<ll> t(n);
    rep(i,n) cin >> t[i];
    sort(all(t));
    ll min_ = 0;
    ll cnt = 0;
    ll ans = 0;
    rep(i,n){
        if(t[min_]+k < t[i]){
            min_ = i;
            cnt = 0;
            ans++;
            // continue;
        }
        cnt++;
        if(cnt == c){
            min_ = i+1;
            cnt = 0;
            ans++;
        }
    }
    if(0 < cnt)++ans;
    cout << ans << endl;
}