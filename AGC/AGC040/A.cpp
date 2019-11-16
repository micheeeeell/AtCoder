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
    string s;cin >> s;
    ll n = s.size() + 1;
    ll INF = INT_MAX;
    vector<ll> a(n, -INF);
    vector<ll> btm;
    rep(i,n-2){
        if(i == 0 && s[i] == '<')btm.push_back(i);
        if(s[i] == '>' && s[i+1] == '<')btm.push_back(i+1);
        if(i == n-3 && s[i+1] == '>')btm.push_back(i+2);
    }
    if(n == 2){
        if(s[0] == '>')btm.push_back(1);
        else btm.push_back(0);
    }
    for(auto i : btm)a[i] = 0;
    // 左に更新
    for(auto i : btm){
        ll temp = 1;
        while(i - temp >= 0 && s[i-temp] == '>'){
            a[i-temp] = temp;
            temp++;
        }
    }
    // 右に更新
    for(auto i : btm){
        ll temp = 1;
        while(i + temp <= n-1 && s[i+temp-1] == '<'){
            a[i+temp] = max(a[i+temp],temp);
            temp++;
        }
    }
    // print(btm);
    // print(a);
    ll res = 0;
    rep(i,n){
        res += a[i];
        assert(a[i] != -INF);
    }
    cout << res << endl;
}