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
    ll q; cin >> q;
    vector<ll> a(q), b(q);
    rep(i,q)cin >> a[i] >> b[i];
    rep(i,q){
        if(a[i] == b[i]){
            cout << a[i] + b[i] - 2 << "\n";
            continue;
        }
        if(abs(a[i] - b[i]) == 1){
            cout << a[i] + b[i] - 3 << "\n";
            continue;
        }

        ll c = sqrt(a[i] * b[i]);
        if(c * c == a[i] * b[i])c--;
        if(c * (c+1) < a[i] * b[i]){
            cout << 2 * c - 1 << "\n";
        }
        else{
            cout << 2 * c - 2 << "\n";
        }
    }
}