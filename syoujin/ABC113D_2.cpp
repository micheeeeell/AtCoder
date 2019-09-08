#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(int i = 0; i < x; i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
const ll MOD = 1e9+7;
const int n_max = 1e5+10;

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
    ll h,w; cin >> h >> w;
    ll k; cin >> k;
    vector<vector<ll>> dp(h+3,vector<ll>(w+3,0));
    ll fib[10];
    fib[0] = 1;fib[1] = 2;
    for(int i = 2;i < 10;i++)fib[i] = fib[i-1] + fib[i-2];

    auto count = [&](int x){
        if(x < 0)return fib[0];
        else return fib[x];
    };
    dp[0][1] = 1;
    rep(i,h+1){
        if(i < 1)continue;
        rep(j,w+1){
            if(j == 0)continue;
            // if(i == 1)
            dp[i][j] += (dp[i-1][j-1] * count(j-3) * count(w-j-1))%MOD;
            dp[i][j] += (dp[i-1][j] * count(j-2) * count(w-j-1))%MOD;
            dp[i][j] += (dp[i-1][j+1] * count(j-2) * count(w-j-2)) % MOD;
            dp[i][j] %= MOD;
        }
    }

    // print(dp);
    cout << dp[h][k] << endl;
    return 0;
}