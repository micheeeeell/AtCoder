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
    vector<ll> jewel(n);
    rep(i,n)cin >> jewel[i];
    rep(i,n){
        ll temp;cin >> temp;
        jewel[i] -= temp;
    }
    ll res = 0;
    rep(i,n)if(jewel[i] > 0)res += jewel[i];
    cout << res << endl;
    return 0;
}