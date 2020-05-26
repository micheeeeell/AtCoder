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
    ll n,d; cin >> n >> d;
    using vvvvd = vector< vector< vector< vector< double >>>>;
    using vvvd = vector< vector< vector< double >>>;
    using vvd = vector< vector< double >>;
    using vd = vector< double >;

    vector<ll> p(3,0);
    while(d % 2 == 0){
        p[0]++;
        d /= 2;
    }
    while(d % 3 == 0){
        p[1]++;
        d /= 3;
    }
    while(d % 5 == 0){
        p[2]++;
        d /= 5;
    }
    if(d != 1){cout << 0 << endl; return 0; }

    vvvvd dp(2, vvvd(p[0]+1, vvd(p[1]+1, vd(p[2]+1, 0.0))));
    vvvd clear(p[0]+1, vvd(p[1]+1, vd(p[2]+1, 0.0)));
    int dtw[] = {0,1,0,2,0,1};
    int dth[] = {0,0,1,0,0,1};
    int dfi[] = {0,0,0,0,1,0};
    dp[0][0][0][0] = 1.0;
    rep(l,n){
        rep(i,p[0]+1)rep(j,p[1]+1)rep(k,p[2]+1){
            rep(m,6){
                int ni = min(p[0], i + dtw[m]);
                int nj = min(p[1], j + dth[m]);
                int nk = min(p[2], k + dfi[m]);

                dp[(l+1) & 1][ni][nj][nk] += dp[l & 1][i][j][k] / 6.0;
            }
        }
        dp[l & 1] = clear;
    }
    // print(p);
    // double ans = 0;
    // ans = 1.0 - ans;
    
    cout << fixed << setprecision(15);
    cout << dp[n & 1][p[0]][p[1]][p[2]] << endl;
}