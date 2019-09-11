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
    ll n; cin >> n;
    vector<ll> t(n);
    rep(i,n) cin >> t[i];
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<int> tok(n,0), aok(n,0);
    tok[0] = 1;aok[n-1] = 1;
    for(int i = 1;i < n;i++){
        if(t[i] > t[i-1])tok[i] = 1;
        else tok[i] = 0;
    }
    for(int i = n-2;0 <= i;i--){
        if(a[i] > a[i+1])aok[i] = 1;
        else aok[i] = 0;
    }
    ll res = 1;
    bool ok = true;
    rep(i,n){
        if(tok[i] && aok[i] && a[i] != t[i])ok = false;
        if(tok[i] && t[i] > a[i])ok = false;
        if(aok[i] && t[i] < a[i])ok = false;
        if(!tok[i] && !aok[i]) res = (res * min(a[i],t[i]))%MOD;
    }

    // print(tok);
    // print(aok);
    res %= MOD;
    cout << (ok ? res : 0) << endl;
    return 0;
}