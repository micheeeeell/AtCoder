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
    ll n,c; cin >> n >> c;
    vector<ll> x(n), v(n), sum(n+1,0);
    rep(i,n) cin >> x[i] >> v[i];
    for(int i = 1; i <= n;++i){
        sum[i] = sum[i-1] + v[i-1];
    }
    vector<ll> sum_right_max(n), sum_left_max(n);
    ll tmp_right_max = 0, tmp_left_max = 0;
    rep(i,n){
        tmp_right_max = max(tmp_right_max, sum[i+1] - x[i]);
        sum_right_max[i] = tmp_right_max;
        tmp_left_max = max(tmp_left_max, sum[n] - sum[n-i-1] - (c-x[n-i-1]));
        sum_left_max[n-i-1] = tmp_left_max;
    }

    ll res = 0;
    //  先に右に行く，右側固定 
    rep(i,n){
        // 折り返さない
        res = max(res, sum[i+1] - x[i]);
        // 折り返す
        if(i < n-1)res = max(res, sum[i+1] - 2*x[i] + sum_left_max[i+1]);
    }
    //  先に左に行く，左側固定 
    rep(i,n){
        // 折り返さない
        res = max(res, sum[n] - sum[i] - (c-x[i]));
        // 折り返す
        if(0 < i)res = max(res, sum[n] - sum[i] - 2*(c - x[i]) + sum_right_max[i-1]);
    }
    // print("sum");
    // print(sum);
    // print("sum_right");
    // print(sum_right_max);
    // print("sum_left");
    // print(sum_left_max);
    cout << res << endl;
    return 0;
}