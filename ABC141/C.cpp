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
    ll n,k; cin >> n >> k;
    ll q; cin >> q;
    vector<ll> a(q);
    rep(i,q) cin >> a[i];
    vector<ll> point(n,0);
    vector<bool> res(n);
    rep(i,q){
        point[a[i]-1]++;
    }
    ll hituyou = 1 - (k-q);
    rep(i,n){
        if(point[i] >= hituyou)res[i] = true;
        else res[i] = false;
    }
    rep(i,n)cout << (res[i] ? "Yes" : "No") << "\n";

    return 0;
}