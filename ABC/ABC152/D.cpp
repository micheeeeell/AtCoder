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
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ll ed = i%10;
        ll st = digit_num(i,digit_max(i));
        if(ed == 0)continue;
        ll temp = 0;
        rep(i,10){
            if(i+2 > digit_max(n))break;
            if(i+2 < digit_max(n))temp += pow(10,i);
            else{
                if(digit_num(n,digit_max(n)) > ed)temp += pow(10,i);
                else if(digit_num(n,digit_max(n)) == ed){
                    // debug("test");
                    temp += (n-ed*pow(10,i+1)-st)/10 + 1;
                }
            }
        }
        if(st == ed)temp++;
        // debug(i);debug(st);debug(ed);
        // debug(temp);
        ans += temp;
    }
    cout << ans << endl;
}