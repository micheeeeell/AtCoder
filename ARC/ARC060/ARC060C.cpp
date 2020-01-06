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

template<typename T>
void print(T &arr){
    ll sz = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0;i < sz-1;i++){cout << arr[i] << ' ';}
    cout << arr[sz-1] << endl;
}


int main(){
    ll n,a; cin >> n >> a;
    vector<ll> x(n);
    rep(i,n) cin >> x[i];
    //i := i枚目
    // j := j枚使う
    // k := 合計値
    vvvl dp(n+1,vvl(n+1, vl(2600,0)));
    // rep(i,n+1) dp[i][0][0] = 1;
    dp[0][0][0] = 1;
    //配る
    rep(i,n){
        // if(!i)continue;
        rep(j,i+1){
            // if(!j)continue;;
            rep(k,2500){
                if(dp[i][j][k]){
                    dp[i+1][j+1][k+x[i]] += dp[i][j][k];
                    dp[i+1][j][k] += dp[i][j][k];
                }
            }
        }
    }

    // rep(i,6+1){
    //     rep(j,i+1){
    //         rep(k,30){
    //             print(i,j,k, dp[i][j][k]);
    //         }
    //     }
    // }

    ll res = 0;
    rep(j,n+1){
        if(!j)continue;
        res += dp[n][j][j*a];
    }
    cout << res << endl;
    return 0;
}