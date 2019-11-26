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

template<typename T>
void print(T &arr){
    ll sz = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0;i < sz-1;i++){cout << arr[i] << ' ';}
    cout << arr[sz-1] << endl;
}

int main(){
    ll n,k; cin >> n >> k;
    vector<ll> a(n);
    unordered_map<ll,ll> ump;
    rep(i,n){
        cin >> a[i];
        a[i]--;
    }
    vector<ll> sum(n+1,0);
    rep(i,n){
        sum[i+1] = (sum[i] + a[i]) % k;
    }
    // print(sum);
    // rep(i,n)sum[i]--;
    rep(i,min(n,k-1)){
        ump[sum[i+1]]++;
    }
    ll res = 0;
    rep(i,n){
        res += ump[sum[i]];
        if(i+k <= n)ump[sum[i+k]]++;
        ump[sum[i+1]]--;
        // print(i,res);
    }
    cout << res << endl;
}