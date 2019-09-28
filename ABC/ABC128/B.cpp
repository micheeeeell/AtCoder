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

int main(){
    int n; cin >> n;
    vector<pair<pair<string, int>, int>> rest;
    rep(i,n){
        string s;cin >> s;
        int p; cin >> p;
        pair<pair<string, int>, int> temp = make_pair(make_pair(s,-p),i+1);
        rest.push_back(temp);
    }
    sort(rest.begin(), rest.end());
    for(auto i : rest)cout << i.second << endl;
    return 0;
}