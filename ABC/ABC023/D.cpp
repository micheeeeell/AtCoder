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
const ll INF = LLONG_MAX/4;
const ll MOD = 1e9+7;
const int n_max = 1e5+10;


int main(){
    ll n; cin >> n;
    vector<ll> h(n), s(n);
    rep(i,n)cin >> h[i] >> s[i];

    auto check = [&](ll x){
        bool ok = true;
        // vector<ll> time(n);
        priority_queue<ll> time;
        rep(i,n){
            if(x < h[i]){ok = false;break;}
            time.push((x - h[i]) / s[i]);
        }
        for(int i = n-1; 0 <= i; i--){
            if(!time.size())break;
            ll t = time.top();time.pop();
            if(t < i)ok = false;
        }
        return ok;
    };

    ll ok = 1e15;
    ll ng = 0;
    assert(check(ok));
    while(abs(ok - ng) > 1){
        ll x = (ok + ng)/2;
        if(check(x))ok = x;
        else ng = x;
    }
    cout << ok << endl;
}