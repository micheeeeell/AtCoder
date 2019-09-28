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

template <class T, class U>
ll euclid_gcd(T a, U b){
    if(a < b)return euclid_gcd(b,a);
    ll r;
    while((r = a%b)){
        a = b;
        b = r;
    }
    return b;
}


int main(){
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<int> res(n), l(n), r(n);
    rep(i,n){
        if(!i){l[i] = a[i];continue;}
        l[i] = euclid_gcd(l[i-1],a[i]);
    }
    for(int i = n-1; 0 <= i; i--){
        if(i == n-1){r[i] = a[i];continue;}
        r[i] = euclid_gcd(r[i+1], a[i]);
    }
    rep(i,n){
        if(!i){
            res[i] = r[i+1];
            continue;
        }
        if(i == n-1){
            res[i] = l[i-1];
            continue;
        }
        res[i] = euclid_gcd(l[i-1], r[i+1]);
    }
    cout << *max_element(res.begin(), res.end()) << endl;
    return 0;
}