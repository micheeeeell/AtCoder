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
    ll a,b; cin >> a >> b;
    vector<ll> a_p, b_p;
    a_p.push_back(1);b_p.push_back(1);
    ll a_tmp = a, b_tmp = b;
    rep(i,sqrt(a)+1){
        if(i <= 1)continue;
        bool ok = false;
        while(a_tmp % i == 0){
            a_tmp /= i;
            ok = true;
            // if(a_tmp == 0)break;
        }
        if(ok)a_p.push_back(i);
        // if(a_tmp == 0)break;
    }
    if(a_tmp != 1)a_p.push_back(a_tmp);

    // print(a_p);
    // rep(i,sqrt(b)+1){
    //     if(i <= 1)continue;
    //     bool ok = false;
    //     while(b_tmp % i == 0){
    //         b_tmp %= i;
    //         ok = true;
    //     }
    //     if(ok)b_p.push_back(i);
    // }
    ll res = 0;
    for(auto i : a_p){
        if(b % i == 0)res++;
    }
    cout << res << endl;
    return 0;
}