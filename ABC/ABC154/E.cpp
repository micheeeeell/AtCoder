#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define rrep(i,x) for(ll i = (ll)(x)-1;0 <= i; i--)
#define reps(i,x) for(ll i = 1; i < (ll)(x)+1; i++)
#define rreps(i,x) for(ll i = (ll)(x); 1 <= i; i--)
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

template<class T, class U>
void print(pair<T,U> &p){
    print(p.first, p.second);
}

int main(){
    string s;cin >> s;
    ll k; cin >> k;
    ll n = s.size();

    vvvl dp(n+1, vvl(5, vl(2, 0)));
    dp[0][0][0] = 1;
    rep(i,n){
        ll t = s[i] - '0';
        rep(j,4){
            reps(l, 9)dp[i+1][j+1][1] += dp[i][j][1];
            dp[i+1][j][1] += dp[i][j][1];
            reps(l, t-1)dp[i+1][j+1][1] += dp[i][j][0];
            if(t != 0){
                dp[i+1][j+1][0] += dp[i][j][0];
                dp[i+1][j][1] += dp[i][j][0];
            }
            else dp[i+1][j][0] += dp[i][j][0];
        }
        // print(dp[i]);
        // print();
    }

    // print(dp[n]);

    cout << dp[n][k][0] + dp[n][k][1] << endl;

}