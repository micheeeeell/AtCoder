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
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> cnt(3,0);
    rep(i,n){
        if(a[i] % 4 == 0)cnt[2]++;
        else if(a[i] % 2 == 0)cnt[1]++;
        else cnt[0]++;
    }
    bool ok = true;
    if(cnt[2] >= cnt[0])ok = true;
    else if(cnt[2] == cnt[0]-1 && cnt[1] == 0)ok = true;
    else ok = false;

    cout << (ok ? "Yes" : "No") << endl;
}