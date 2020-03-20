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
    ll n; cin >> n;
    vector<ll> a(3);
    rep(i,3)cin >> a[i];
    bool ok = true;
    ll cnt = 0;
    rep(i,3)if(n == a[i])ok = false;
    auto check = [&](int x){
        rep(i,3)if(x == a[i])return false;
        return true;
    };
    while(n > 0 && ok){
        if(check(n-3))n -= 3;
        else if(check(n-2))n -= 2;
        else if(check(n-1))n -= 1;
        else ok = false;
        cnt++;
    }

    cout << ((ok && cnt <= 100) ? "YES" : "NO") << endl;
}