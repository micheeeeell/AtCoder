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
        if (&a != &vec.back()) cout << '\n';
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
    ll n,m,d; cin >> n >> m >> d;
    vector<ll> a(m);
    rep(i,m) cin >> a[i];
    ll LOG = 64 - __builtin_clzll(d);
    vector<vector<ll>> table(LOG, vector<ll>(n));
    debug(LOG);
    // 自身のidxで埋める
    std::iota(all(table[0]),0);
    for(int i = m-1; 0 <= i; i--){
        std::swap(table[0][a[i]-1], table[0][a[i]]);
    }
    // print(table[0]);
    rep(k,LOG-1){
        rep(i,n){
            table[k+1][i] = table[k][table[k][i]];
        }
    }
    vector<ll> ret(n);
    std::iota(all(ret),0);
    for(int i = LOG-1; 0 <= i; i--){
        if((d >> i) & 1){
            rep(j,n)ret[j] = table[i][ret[j]];
        }
    }
    rep(i,n)ret[i]++;
    print(ret);
}