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
    ll n,m; cin >> n >> m;
    vector<ll> f(n), pre(n,-1), ind(m,-1);
    rep(i,n){
        cin >> f[i];
        f[i]--;
        // if(ind[f[i]] != -1)pre[i] = ind[f[i]];
        // ind[f[i]] = i;
    }
    // print(pre);
    vector<ll> dp(n+1), sum(n+2,0), col(m,0);
    dp[0] = 1;
    sum[1] = 1;
    // sum[2] = 2;
    ll left = 0;
    rep(i,n){
        col[f[i]]++;
        while(1 < col[f[i]]){
            col[f[left]]--;
            left++;
        }
        // debug(left);
        dp[i+1] = (sum[i+1] - sum[left]) % MOD;
        if(dp[i+1] < 0)dp[i+1] += MOD;
        sum[i+2] = (sum[i+1] + dp[i+1]) % MOD;
        // debug(dp[i+1]);
    }
    cout << dp[n] << endl;
}