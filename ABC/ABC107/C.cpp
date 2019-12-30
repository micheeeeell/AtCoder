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
const ll INF = numeric_limits<ll>::max()/4;
const ll MOD = 1e9+7;
const int n_max = 1e5+10;


template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

int main(){
    ll n,k; cin >> n >> k;
    vector<ll> x(n);
    // ll minus = 0, plus = 0;
    rep(i,n) {
        cin >> x[i];
        // if(x[i] < 0)minus++;
        // else plus++;
    }
    ll ret = INF;
    rep(i,n-k+1){
        ll temp = 0;
        if(x[i] * x[i+k-1] > 0)temp = max(abs(x[i]), abs(x[i+k-1]));
        else {
            temp = min(abs(x[i]), abs(x[i+k-1])) + abs(x[i] - x[i+k-1]);
        }
        chmin(ret, temp);
    }

    cout << ret << endl;
}