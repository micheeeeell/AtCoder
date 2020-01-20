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

//   a a b a a b a a a
// _ 0 1 0 1 2 3 4 5 2
// 文字列S[0,i-1]の接頭辞と接尾辞が最大何文字一致しているか
vector<ll> MP(string &s){
    vector<ll> res(s.size()+1);
    res[0] = -1;
    int j = -1;
    rep(i,s.size()){
        while(j >= 0 && s[i] != s[j]) j = res[j];
        j++;
        res[i+1] = j;
    }
    return res;
}

int main(){
    string s = "aabaabaaa";

    vector<ll> vec = MP(s);
    for(auto j : vec)cout << j << " ";
    cout << "\n";
}