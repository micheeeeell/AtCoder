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

template<typename T>
void print(T &arr){
    ll sz = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0;i < sz-1;i++){cout << arr[i] << ' ';}
    cout << arr[sz-1] << endl;
}

int main(){
    ll n,m; cin >> n >> m;
    vector<ll> price(m);
    vector<int> c_bit(m);
    rep(i,m){
        ll a,b; cin >> a >> b;
        price[i] = a;
        int temp = 0;
        rep(j,b){
            int c;cin >> c;
            c--;
            temp += (1 << c);
        }
        c_bit[i] = temp;
    }
    // print(c_bit);
    ll INF = INT_MAX;
    vector<vector<ll>> dp(1010,vector<ll>(5000,INF));
    dp[0][0] = 0;
    rep(i,m){
        // if(!i)continue;
        rep(j,(1 << n)){
            if(dp[i][j] == INF)continue;
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            dp[i+1][(j | c_bit[i])] = min(min(dp[i][j | c_bit[i]],dp[i+1][j | c_bit[i]]), dp[i][j] + price[i]);
            // print(i,j,j | c_bit[i], dp[i][j | c_bit[i]], dp[i][j] + price[i], dp[i+1][(j | c_bit[i])]);
        }
    }
    // rep(i,m+1){
    //     rep(j,20)cout << (dp[i][j] == INF ? -1 : dp[i][j]) << " ";
    //     cout << endl;
    // }
    cout << (dp[m][(1 << n)-1] == INF ? -1 : dp[m][(1 << n)-1]) << endl;
}