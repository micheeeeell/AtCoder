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

ll modinv(ll a, ll m){
    ll b = m, u = 1, v = 0;
    while(b){
        ll t = a/b;
        a -= t * b; swap(a,b);
        u -= t * v; swap(u,v);
    }
    u %= m;
    if(u < 0) u += m;
    return u;

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



int main(){
    ll n; cin >> n;
    ll k = 1;
    rep(i,n-1)k = (k * (i+1)) % MOD;

    vector<ll> dp(n+10,0);
    dp[0] = 1;
    rep(i,n)dp[i+1] = dp[i] * (i+1) % MOD;

    vector<ll> dp2(n+10);
    dp2[0] = 0;
    rep(i,n+1){
        dp2[i+1] = (dp2[i] * (i+1)) % MOD + (dp[i+1]*modinv((i+1), MOD)) % MOD;
        dp2[i+1] %= MOD;
    }
    // print(dp2);


    vector<ll> d(n-1), sum(n,0);
    rep(i,n-1)d[i] = (k * modinv((i+1),MOD)) % MOD;
    rep(i,n-1)sum[i+1] = (sum[i] + d[i]) % MOD;
    ll ans = 0;
    debug(dp[n-1]);
    debug(k);
    rep(i,n-1){
        ll temp1 = sum[i+1] - sum[0];
        ll temp2 = dp2[i+1];
        temp2 *= (dp[n-1] * modinv(dp[i+1], MOD)) % MOD;
        temp2 %= MOD;
        if(temp1 != temp2){
            debug(i);
            debug(temp1);
            debug(temp2);
        }
    }
}