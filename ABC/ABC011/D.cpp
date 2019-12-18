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
const int n_max = 1010;

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
    // combinationの確率計算(前処理)
    vector<vector<ld>> com(n_max, vector<ld>(n_max,0));
    com[0][0] = ld(1);
    rep(i,n_max-1){
        rep(j,i+2){
            if(j != 0)com[i+1][j] = (com[i][j-1] + com[i][j]) / 2;
            else com[i+1][j] = com[i][j] / 2;
        }
    }
    // print(com);

    ll n,d; cin >> n >> d;
    ll x,y; cin >> x >> y;
    if(x%d != 0 || y%d != 0){
        cout << 0 << endl;
        return 0;
    }
    x /= d; y /= d;


    ld ret = 0;
    rep(i,n+1){
        if(i < abs(x))continue;
        if(n-i < abs(y))continue;
        if((abs(x)+i) % 2 != 0)continue;
        ll right = (abs(x) + i)/2;
        if((abs(y) + n - i) % 2 != 0)continue;
        ll up = (abs(y) + n - i) / 2;
        ret += com[n][i] * com[i][right] * com[n-i][up];
    }
    cout << fixed << setprecision(15);
    cout << ret << endl;
    return 0;
}