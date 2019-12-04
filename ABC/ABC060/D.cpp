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

// template<typename T>
// void print(T &arr){
//     ll sz = sizeof(arr)/sizeof(arr[0]);
//     for(int i = 0;i < sz-1;i++){cout << arr[i] << ' ';}
//     cout << arr[sz-1] << endl;
// }


int main(){
    // std::ifstream in("antigreedy0.in");
    // std::cin.rdbuf(in.rdbuf());
    
    ll N,W; cin >> N >> W;
    vector<ll> w(N),v(N);
    vector<vector<vector<ll>>> dp(2,vector<vector<ll>>(N+1,vector<ll>(330,0)));   
    // vector<vector<vector<ll>>> dp(2,vector<vector<ll>>(N+1,vector<ll>(30,0)));   
    rep(i,N)cin >> w[i] >> v[i];
    ll base = w[0];
    rep(i,N)w[i] -= base;
    rep(i,N){
        rep(j,N){
            if(i < j)continue;
            rep(k,330){
                dp[(i+1)%2][j][k] = max(dp[(i+1)%2][j][k],dp[i%2][j][k]);
                if(w[i] <= k && (j+1)*base + k <= W){
                    dp[(i+1)%2][j+1][k] = max(dp[(i+1)%2][j+1][k],dp[i%2][j][k-w[i]] + v[i]);
                }
            }
        }
        // print(i);
        // print(dp[(i+1)%2]);
    }

    ll res = 0;
    rep(j,N+1){
        res = max(res, dp[N%2][j][max(0LL,min(W - (j)*base, 300LL))]);
    }
    cout << res << endl;
}