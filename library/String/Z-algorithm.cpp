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

// S と S[i:|S|-1] の最長共通接頭辞の長さ

// a a a b a a a a b
// 9 2 1 0 3 4 2 1 0

vector<ll> Z_algo(string &s){
    int len = s.size();
    vector<ll> res(len);
    res[0] = len;
    int i = 1, j = 0;
    while(i < len){
        while(i+j < len && s[j] == s[i+j]) ++j;
        res[i] = j;
        if(j == 0) { ++i; continue;}
        int k = 1;
        while(i+k < len && k+res[k] < j) {
            res[i+k] = res[k], ++k;
        }
        i += k; j -= k;
    }
    return res;
}

int main(){
    string s = "aaabaaaabaaaaab";
    vector<ll> a = Z_algo(s);
    rep(i,a.size())cout << a[i] << " ";
    cout << endl;
    return 0;
}