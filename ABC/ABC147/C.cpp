#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(int i = 0; i < (int)(x); i++)
#define pb push_back
#define eb emplace_back
#define mp make_pair
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
const int n_max = 1e5+10;

int main(){
    ll n; cin >> n;
    vector<vector<Pll>> xy(n);
    rep(i,n){
        ll a; cin >> a;
        rep(j,a){
            ll x,y; cin >> x >> y;
            x--;
            xy[i].emplace_back(Pll(x,y));
        }
    }
    ll res = 0;
    rep(i,1LL << n){
        bool ok = true;
        bitset<30> bs(i);
        rep(j,n){
            if(i & (1LL << j)){
                for(auto k : xy[j]){
                    if(bs[k.first] != k.second)ok = false;
                }
            }
            // else{
            //     for(auto k : xy[j]){
            //         if(bs[k.first] == k.second)ok = false;
            //     }
            // }
        }
        ll t = bs.count();
        // debug(i);
        // debug(bs);
        // debug(t);
        if(ok){
            res = max(res, t);
            // debug(bs);
        }
    }

    cout << res << endl;
}