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

int main(){
    ll n,k; cin >> n >> k;
    vector<ll> d(10,0);
    rep(i,k) {
        ll a;cin >> a;
        d[a] = 1;
    }

    auto check = [&](ll x){
        while(x){
            if(d[x % 10])return false;
            x /= 10;
        }
        return true;
    };

    for(ll i = n;i < 1e6;i++){
        if(check(i)){
            cout << i << endl;
            return 0;
        }
    }

    return 0;

}