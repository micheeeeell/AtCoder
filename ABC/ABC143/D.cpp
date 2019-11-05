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
    vector<ll> l(n);
    rep(i,n) cin >> l[i];
    sort(l.begin(), l.end());
    ll res = 0;
    rep(i,n)rep(j,n){
        if(i >= j)continue;
        ll a = l[i], b = l[j];
        // ll it = lower_bound(l.begin(), l.end(),a+b) - upper_bound(l.begin(), l.end(), b-a);
        ll low = upper_bound(l.begin(), l.end(),b-a) - l.begin();
        ll high = lower_bound(l.begin(), l.end(), a+b) - l.begin();
        ll it = high - low;
        if(b-a < a)it--;
        if(b-a < b)it--;
        // print(a,b,it, low, high);
        res += it;
    }
    cout << res / 3 << endl;
    return 0;
}