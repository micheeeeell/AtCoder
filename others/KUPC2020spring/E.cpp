#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define rrep(i,x) for(ll i = (ll)(x)-1;0 <= i; i--)
#define reps(i,x) for(ll i = 1; i < (ll)(x)+1; i++)
#define rreps(i,x) for(ll i = (ll)(x); 1 <= i; i--)
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

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

int main(){
    ll n; cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    bool is_one = false;
    ll min = INF;
    rep(i,n) {
        cin >> a[i];
        sum += a[i];
        if(a[i] == 1)is_one = true;
        chmin(min, a[i]);
    }

    bool first = true;
    if(n % 2 == 1){
        if(sum % 2 == 0)first = false;
    }
    else {
        if(sum % 2 == 0 && is_one == false && min % 2 == 0)first = false;
    }

    cout << (first ? "First" : "Second") << endl;
    
}