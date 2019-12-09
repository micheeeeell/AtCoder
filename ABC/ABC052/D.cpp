#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(int i = 0; i < (int)(x); i++)
#define pb push_back
#define eb emplace_back
#define mp make_pair
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
const int n_max = 1e5+10;

int main(){
    ll n,a,b; cin >> n >> a >> b;
    vector<ll> x(n);
    rep(i,n) cin >> x[i];
    ll res = 0;
    rep(i,n-1){
        ll num = x[i+1] - x[i];
        if(num * a < b)res += num*a;
        else res += b;
    }
    cout << res << endl;
}