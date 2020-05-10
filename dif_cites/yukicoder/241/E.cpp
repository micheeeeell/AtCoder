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
const int n_max = 50;

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
    ll n,k; cin >> n >> k;
    vector<ll> p(n), p_rev(n+1);
    rep(i,n) {
        cin >> p[i];
        p_rev[p[i]] = i;
    }
    // print(p_rev);
    vector<vector<ll>> dp(n_max+1, vector<ll>(n)), dp2(n_max+1, vector<ll>(n));
    rep(i,n)dp[0][i] = p[i];

    // print(dp[0]);
    rep(j,n){
        dp[1][j] = dp[0][(p_rev[dp[0][j]] + dp[0][j]) % n];
        dp2[1][j] = p[j];
    }
    // print(dp[1]);
    reps(i,n_max-1){
        rep(j,n){
            dp[i+1][j] = dp[i][p_rev[dp[i][j]]];
            dp2[i+1][j] = dp2[i][j] + dp2[i][p_rev[dp[i][j]]];
            // print(i,j,p_rev[dp[i][j]], dp[i][j]);
        }
        // print(dp[i+1]);
        // print(dp2[i+1]);
        // print();
    }
    // debug("test");
    rep(i,n){
        ll pos = p[i];
        ll temp = k;
        ll ans = 0;
        rreps(j,n_max){
            if(temp >= pow(2,j-1)){
                ans += dp2[j][p_rev[pos]];
                pos = dp[j][p_rev[pos]];
                temp -= pow(2,j-1);
                // print(i,j,pos,ans);
            }
            // debug(pos);
        }

        cout << ans + i+1 << "\n";
    }
}