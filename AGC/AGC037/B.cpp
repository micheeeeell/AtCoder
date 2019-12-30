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
const ll MOD = 998244353;
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
    ll n; cin >> n;
    string s;cin >> s;
    vector<ll> table(3*n,0);
    ll r = 0,g = 0,b = 0;
    rep(i,3*n){
        if(s[i] == 'R'){
            if(max({r,g,b}) == r)table[i] = 1;
            else if(r < g && r < b)table[i] = 3;
            else table[i] = 2;
            r++;
        }
        if(s[i] == 'G'){
            if(max({r,g,b}) == g)table[i] = 1;
            else if(g < r && g < b)table[i] = 3;
            else table[i] = 2;
            g++;
        }
        if(s[i] == 'B'){
            if(max({r,g,b}) == b)table[i] = 1;
            else if(b < r && b < g)table[i] = 3;
            else table[i] = 2;
            b++;
        }
    }
    vector<ll> dp(3,0);
    dp[0] = n;
    ll ret = 1;
    rep(i,3*n){
        // debug(i);
        // print(dp);
        ret *= dp[table[i]-1];
        ret %= MOD;
        dp[table[i]-1]--;
        if(table[i] < 3)dp[table[i]]++;
    }

    // print(table);

    cout << ret % MOD << endl;
}