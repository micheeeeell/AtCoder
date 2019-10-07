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
    string s;cin >> s;
    int n = s.size();
    vector<vector<ll>> dp(n+1, vector<ll>(4,0));
    for(int i = n; 0 <= i; --i){
        for(int j = 3; 0 <= j; --j){
            if(i == n){
                dp[i][j] = (j == 3 ? 1 : 0);
            }
            else{
                dp[i][j] += dp[i+1][j] * (s[i] == '?' ? 3 : 1);
                if(j < 3 && (s[i] == '?' || s[i] == "ABC"[j])){
                    dp[i][j] += dp[i+1][j+1];
                }
            }
            dp[i][j] %= MOD;
        }
    }

    // rep(i,n+1){
    //     rep(j,4)print(i,j,dp[i][j]); 
    // }
    cout << dp[0][0] << endl;
}