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

int main(){
    ll n,T; cin >> n >> T;
    vector<ll> t(n);
    rep(i,n) cin >> t[i];
    ll ans = 0;
    ll st = t[0];
    rep(i,n){
        if(t[i] - st > T){
            ans += T;
            st = t[i];
        }
        else{
            ans += t[i] - st;
            st = t[i];
        }
    }
    ans += T;
    cout << ans << endl;
}