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
const int n_max = 2e5+10;

int main(){
    ll n; cin >> n;
    vector<ll> cnt(n,0);
    rep(i,n){
        ll a; cin >> a;
        a--;
        cnt[a]++;
    }
    ll x = 0, y = 0;
    rep(i,n){
        if(cnt[i] == 0)x = i+1;
        if(cnt[i] == 2)y = i+1;
    }
    if(x == 0) cout << "Correct" << endl;
    else cout << y << " " << x << endl; 
    
}