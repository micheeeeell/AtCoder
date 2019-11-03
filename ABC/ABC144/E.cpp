#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(int i = 0; i < x; i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
const ll MOD = 1e9+7;
const int n_max = 1e5+10;

ll solve(vector<ll> a, vector<ll> f, ll n, ll k, ll l, ll r){
    if(r-l == 1){
        ll x = l;
        ll temp_sum = 0;
        rep(i,n){
            if(!f[i])continue;
            ll temp = x/f[i];
            if(temp < a[i])temp_sum += a[i] - temp;
        }
        if(k < temp_sum) return r;
        else return l;
    }
    ll x = (l + r) / 2;
    ll temp_sum = 0;
    rep(i,n){
        if(!f[i])continue;
        ll temp = x/f[i];
        if(temp < a[i])temp_sum += a[i] - temp;
    }
    if(k < temp_sum) return solve(a,f,n,k,x,r);
    else return solve(a,f,n,k,l,x);
}
int main(){
    ll n,k; cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> f(n);
    rep(i,n) cin >> f[i];
    sort(a.begin(), a.end());
    sort(f.begin(), f.end(), greater<ll>());
    ll mm = 0;
    rep(i,n)mm = max(mm, a[i] * f[i]);
    cout << solve(a,f,n,k,0,mm) << endl;
    return 0;
}