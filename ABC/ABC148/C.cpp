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
const ll INF = LLONG_MAX/4;
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
    ll a,b; cin >> a >> b;
    ll g = euclid_gcd(a,b);
    cout << (a/g) * (b/g) * g << endl;
}