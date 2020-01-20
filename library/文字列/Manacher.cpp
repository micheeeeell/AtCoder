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
const ll INF = numeric_limits<ll>::max()/4;
const int n_max = 1e5+10;

// 文字 i を中心とする最長の回文の半径
// a b a a a b a b a
// 1 2 1 4 1 2 3 2 1
// 普通のManacherをやると奇数長の回文しか検出できませんが、「a$b$a$a$b」
// みたいにダミー文字を間に挟むと偶数長のものも検出できるようにできます。

vector<ll> Manacher(string &s){
    int i = 0, j = 0;
    vector<ll> R(s.size());
    while (i < s.size()) {
        while (i-j >= 0 && i+j < s.size() && s[i-j] == s[i+j]) ++j;
        R[i] = j;
        int k = 1;
        while (i-k >= 0 && i+k < s.size() && k+R[i-k] < j) R[i+k] = R[i-k], ++k;
        i += k; j -= k;
    }
    return R;
}

int main(){
    string s = "abaaababa";
    vector<ll> vec = Manacher(s);
    for(auto j : vec) cout << j << " ";
    cout << "\n";
}