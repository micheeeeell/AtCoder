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
    ll n; cin >> n;
    vector<ll> a(n), b(n), c(n);
    rep(i,n)cin >> a[i];
    rep(i,n)cin >> b[i];
    rep(i,n)cin >> c[i];
    sort(all(a));
    sort(all(b));
    sort(all(c));
    ll ans = 0;
    vector<ll> sum_b(n+1,0), num_b(n);
    rep(i,n){
        ll num = c.end() - upper_bound(all(c), b[i]);
        num_b[i] = num;
    }
    rep(i,n)sum_b[i+1] = sum_b[i] + num_b[i];
    rep(i,n){
        ll idx = upper_bound(all(b), a[i]) - b.begin();
        ans += sum_b[n] - sum_b[idx];
    }
    cout << ans << endl;
}