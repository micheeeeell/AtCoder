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
const ll N = 1e9+7;
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
    int n; cin >> n;
    string s;cin >> s;
    vector<int> left,right;
    vector<int> lr(2*n);
    ll ans = 0;
    bool ok = true;

    ll dp[n+1];
    dp[0] = 1;
    rep(i,n+1){
        if(!i)continue;
        dp[i] =dp[i-1] * i;
        dp[i] %= N;
    }
    //前半
    rep(i,n){
        if(i == 0 && s[i] == 'W'){
            ans = 0;
            ok = false;
            break;
        }
        if( (i%2 && s[i] == 'W') || (!(i%2) && s[i] == 'B')){
            left.push_back(i);
            lr[i] = 0;
        }
        if( (i%2 && s[i] == 'B') || (!(i%2) && s[i] == 'W')){
            right.push_back(i);
            lr[i] = 1;
        } 
    }
    //後半
    rep(i,n){
        int temp = i + n;
        if(temp == 2*n-1 && s[temp] == 'W'){
            ans = 0;
            ok = false;
            break;
        }
        if( (temp%2 && s[temp] == 'W') || (!(temp%2) && s[temp] == 'B')){
            left.push_back(temp);
            lr[temp] = 0;
        }
        if( (temp%2 && s[temp] == 'B') || (!(temp%2) && s[temp] == 'W')){
            right.push_back(temp);
            lr[temp] = 1;
        } 
    }
    if(left.size() != right.size())ok = false;
    // print(right);print(left);
    // print(lr);
    int right_i[2*n] = {},left_i[2*n] = {};
    ll choose = 1;
    rep(i,2*n){
        if(i == 2*n-1)continue;
        if(!lr[i]){
            left_i[i+1] = left_i[i] + 1;
            right_i[i+1] = right_i[i];
        }
        else{
            left_i[i+1] = left_i[i];
            right_i[i+1] = right_i[i] + 1;
            choose *= (left_i[i] - right_i[i]);
            choose %= N;
        }
    }

    if(choose < 0)ok = false;

    cout << (ok ? choose * dp[n] % N : 0) << endl;
    return 0;
}