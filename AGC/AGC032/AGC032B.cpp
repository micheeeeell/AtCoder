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
    ll n; cin >> n;
    vector<ll> pairs(n);
    if(n%2 == 0){
        rep(i,n)pairs[i] = n-i-1;
    }
    else{
        rep(i,n)pairs[i] = n-i-2;
    }

    vector<P> res; 

    rep(i,n){
        rep(j,n){
            // if(i == j)continue;
            if(i >= j)continue;
            if(pairs[i] == j)continue;
            //cout << i+1 << " " << j+1 << endl;
            res.push_back(P(i+1,j+1));
        }
    }

    cout << res.size() << endl;
    for(auto i : res)cout << i.first << " " << i.second << endl;
    return 0;
}