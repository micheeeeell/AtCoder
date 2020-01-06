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


int main(){
    string a;cin >> a;
    ll len = a.size();
    // vector<ll> cnt(len,0);
    map<char,ll> mp;
    ll res = 0;
    mp[a[0]]++;
    for(int i = 1;i < len;i++){
        if(mp[a[i]] == 0){
            mp[a[i]]++;
            res += i;
        }
        else{
            res += i-mp[a[i]];
            mp[a[i]]++;
        }
        // print(a[i], mp[a[i]], res);
    }
    res++;
    cout << res << endl;
    return 0;
}