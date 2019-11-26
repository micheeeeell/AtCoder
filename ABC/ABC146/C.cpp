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
const ll MOD = 1e9+7;
const int n_max = 1e5+10;

ll dim(ll n){
    ll res = 0;
    // ll temp = 0;
    while(n > 0){
        res++;
        n /= 10;
    }
    return res;
}

ll solve(ll x,ll a, ll b,ll l = 1, ll r = 1e9){
    if(r-l == 1){
        if(r*a+dim(r)*b < x)return r;
        else if(x<l * a+dim(l)*b){
           return 0;
        }
        else return l;
    }
    ll res;
    ll temp = (l+r)/2;
    if(x < temp*a + dim(temp)*b){
        res = solve(x,a,b,l,temp);
    }
    else if(x > temp*a + dim(temp)*b){
        res = solve(x,a,b,temp,r);
    }
    else res = temp;
    return res;
}

int main(){
    ll a,b,x; cin >> a >> b >> x;
    // cout << dim(10);
    cout << solve(x,a,b) << endl;
}