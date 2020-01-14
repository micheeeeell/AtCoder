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
    ll a,b,c; cin >> a >> b >> c;
    ll sum = a + b + c;
    ll cnt = 0;
    if(a % 2 == 0 && a == b && b == c){cout << -1 << endl;return 0;}
    auto update = [&](){
        if(a % 2 || b % 2 || c % 2)return false;
        a = (sum - a) / 2;
        b = (sum - b) / 2;
        c = (sum - c) / 2;
        return true;
    };

    while (update())
    {
        cnt++;
    }
    

    cout << cnt << endl;
}