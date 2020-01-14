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
    ll n,k; cin >> n >> k;
    vector<Pll> ab(n);
    vector<ll> num(n,0);
    rep(i,n){
        ll a,b; cin >> a >> b;
        ab[i] = Pll(a,b);
    }
    sort(all(ab));
    num[0] = ab[0].second;
    rep(i,n-1)num[i+1] = num[i] + ab[i+1].second;
    ll idx = lower_bound(all(num), k) - num.begin();
    cout << ab[idx].first << endl;
}