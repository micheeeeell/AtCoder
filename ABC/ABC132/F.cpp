#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define rep(i,x) for(int i = 0; i < x; i++)
#define orep(i,x) for(int i = 1; i < x; i++)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> ivec;
const ll N = 1e9+7;

void print() {
    cout << endl;
}

// template <class Head, class... Tail>
// void print(Head&& head, Tail&&... tail) {
//     cout << head;
//     if (sizeof...(tail) != 0) cout << " ";
//     print(forward<Tail>(tail)...);
// }

template <class T>
void print(vector<T> &vec) {
    for (auto& a : vec) {
        cout << a;
        if (&a != &vec.back()) cout << " ";
    }
    cout << endl;
}

template <class T>
void print(vector<T> &vec, ll k){
   ll n = vec.size();
   k = min(k, n);
   rep(i,k-1)cout << vec[i] << " ";
   cout << vec[k-1] << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
    for (auto& vec : df) {
        print(vec);
    }
}

template<class T, class U>
void print(pair<T,U> &p){
    cout << p.first << " " << p.second << "\n";
}

int main(){
    ll n,k; cin >> n >> k;
    vector<vector<ll>> dp(k+1,vector<ll>(n));
    rep(i,n)dp[1][i] = 1;
    // rep(i,k+1){rep(j,n)cout << dp[i][j];cout << endl;}
    for(ll i = 2;i < k+1; i++){
        orep(j,n+1){
            ll temp;
            if(j != 0)temp = n/j;
            else temp = n;
            // temp--;
            rep(l,temp){
                dp[i][j-1] += dp[i-1][l] % N;
            }
        }
    }
    ll ans = 0;

    print(dp);
    
    rep(i,n){
        ans += dp[k][i] % N;
        // cout << dp[k][i];
    }
    // cout << endl;
    cout << ans << endl;
    return 0;
}