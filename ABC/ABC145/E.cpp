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



// class menu{ll s, ll e, ll val}

int main(){
    ll n,t; cin >> n >> t;
    // vector<ll> a(n),b(n);
    vector<Pll> ab(n);
    vvl dp(2, vector<ll>(t+10,0));
    vector<vector<vector<bool>>> ok(2,vector<vector<bool>>(t+10,vector<bool>(n,false)));
    rep(i,n){
        // cin >> a[i] >> b[i];
        ll a,b; cin >> a >> b;
        ab[i] = Pll(a, b);
    }
    sort(all(ab));
    ll res = 0;
    rep(i,n){
        rep(j,t+1){
            if(j < ab[i].first){
                dp[(i+1)%2][j] = dp[i%2][j];
                ok[(i+1)%2][j] = ok[i%2][j];
            }
            else {
                if(dp[i%2][j] < dp[i%2][j-ab[i].first] + ab[i].second){
                    dp[(i+1)%2][j] = dp[i%2][j-ab[i].first] + ab[i].second;
                    ok[(i+1)%2][j] = ok[i%2][j-ab[i].first];
                    ok[(i+1)%2][j][i] = true;
                }
                else{
                    dp[(i+1)%2][j] = dp[i%2][j];
                    ok[(i+1)%2][j] = ok[i%2][j];
                }
                // dp[i+1][j] = max(dp[i][j],dp[i][j-a[i]] + b[i]);
            }
        }
        rep(k,n){
            if(ok[(i+1)%2][t-1][k])continue;
            res = max(res,dp[(i+1)%2][t-1] + ab[k].second);
        }
    }
    // print(dp);
    // ll res = dp[n%2][t-1];
    // // print(res);
    // rep(i,n){
    //     cout << int(ok[n%2][t-1][i]) << " ";
    // }
    // // cout << endl;
    // rep(i,n){
    //     if(ok[n%2][t-1][i])continue;
    //     res = max(res,dp[n%2][t-1] + b[i]);
    // }
    cout << res << endl;
}