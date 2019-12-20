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

template<class T>
void chmax(T &a, T &b){if(a < b)a = b;}
template<class T>
void chmin(T &a, T &b){if(a > b)a = b;}

int main(){
    ll r,g,b; cin >> r >> g >> b;
    auto pat = [](ll x, ll y){
        // x := 個数，y := 開始点からの距離
        return x * (x + 2 * y +1) / 2;
    };
    ll ret = INF;
    rep(i,601){
        ll temp = 0;
        ll x = i-300;
        if(x <= 0 && abs(x) < g)temp += pat(abs(x),0) + pat(g-abs(x)-1,0);
        else if(0 < x)temp += pat(g,x-1);
        else temp += pat(g,abs(x)-g);
        ll r_r = min(99+x, r/2);
        if(0 < r_r){
            temp += pat(r_r,0) + pat(r - r_r - 1,0);
        }
        else temp += pat(r, abs(r_r)-1);
        ll b_l = min(99-(x+g-1), b/2);
        if(0 < b_l)temp += pat(b_l,0) + pat(b - b_l - 1,0);
        else temp += pat(b, abs(b_l)-1);
        chmin(ret, temp);
    }
    cout << ret << endl;
}