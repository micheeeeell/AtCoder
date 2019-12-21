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

void print() {
    cout << endl;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
    cout << head;
    if (sizeof...(tail) != 0) cout << ' ';
    print(forward<Tail>(tail)...);
}

template <class T>
void print(vector<T> &vec) {
    for (auto& a : vec) {
        cout << a;
        if (&a != &vec.back()) cout << ' ';
    }
    cout << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
    for (auto& vec : df) {
        print(vec);
    }
}

template<typename T>
void print(T &arr){
    ll sz = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0;i < sz-1;i++){cout << arr[i] << ' ';}
    cout << arr[sz-1] << endl;
}

int main(){
    ll n; cin >> n;
    vector<ll> dp(11,0);
    dp[0] = 0;
    rep(i,10){
        dp[i+1] = dp[i]*10 + pow(10,i);
    }
    // print(dp);
    ll ret = 0;
    ll dig = digit_max(n);
    for(int i = dig; 0 < i;i--){
        ll temp = digit_num(n,i);
        if(temp > 1){
            ret += temp * dp[i-1];
            ret += pow(10,i-1);
        }
        else if(temp == 1){
            ret += temp * dp[i-1];
            ll t = n/pow(10,i-1);
            // debug(t);
            ret += (n - t * pow(10,i-1)) + 1;
        }
        // debug(i);
        // debug(temp);
        // debug(ret);
    }

    cout << ret << endl;
}