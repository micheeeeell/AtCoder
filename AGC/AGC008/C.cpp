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
    ll i,o,t; cin >> i >> o >> t;
    ll j,l,s; cin >> j >> l >> s;
    ll z; cin >> z;
    ll ans = 0;
    ans += o * 2;
    if((i & 1) + (j & 1) + (l & 1) >= 2){
        if(i && j && l){
            i--;j--;l--;
            ans += 6;
        }
    }
    ans += (i / 2) * 4;
    ans += (j / 2) * 4;
    ans += (l / 2) * 4;

    cout << ans / 2 << endl;
}