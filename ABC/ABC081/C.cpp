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
    vector<ll> a(n), cnt(n+1,0);
    rep(i,n){
        cin >> a[i];
        cnt[a[i]]++;
    }
    vector<ll> num;
    rep(i,n+1)if(cnt[i] > 0)num.emplace_back(cnt[i]);
    sort(all(num),greater<ll>());
    ll ans = 0;
    for(int i = num.size(); k < i; i--){
        ans += num[i-1];
    }
    cout << ans << endl;
}