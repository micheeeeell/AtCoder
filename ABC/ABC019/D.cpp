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
    // cin.tie(0);
    // ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    // vector<vector<ll>> dist(2,vector<ll>(n,0));
    auto qwe = [](ll a, ll b){
        cout << "? " << a << " " << b << "\n";
    };
    auto ans = [](ll dist){
        cout << "! " << dist << endl;
    };

    Pll dist = {-1,0};
    rep(i,n-1){
        Pll temp;
        qwe(1,i+2);
        cin >> temp.second;
        temp.first = i+2;
        if(dist.second < temp.second)dist = temp;
    }
    ll ret = 0;
    rep(i,n){
        if(i+1 == dist.first)continue;
        qwe(dist.first,i+1);
        ll temp;
        cin >> temp;
        ret = max(ret, temp);
    }
    ans(ret);
    return 0;
}