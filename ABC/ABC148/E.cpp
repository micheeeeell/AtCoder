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


// xの桁数を返す関数
int digit_max(ll x){
    int dig = 0;
    while(x/pow(10,dig) >= 1)dig++;
    return dig;
}

// xのdigit桁目を返す関数
// 下から順にone-based（感覚に即しているはず）
int digit_num(ll x, int digit){
    assert(digit_max(x) >= digit);
    ll t1 = x/pow(10,digit-1);
    ll t2 = (x/pow(10,digit));
    // print(t1,t2);
    return t1 - t2 * 10;
}

int main(){
    ll n; cin >> n;
    ll ret = 0;
    if(n%2){cout << 0 << endl; return 0;}
    n /= 2;
    ll d = digit_max(n);
    ll s = 5;
    while(0 < n){
        ret += n/s;
        n /= s;
    }
    cout << ret << endl;
}