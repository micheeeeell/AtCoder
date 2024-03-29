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
    ll n; cin >> n;
    vector<ll> a(n+1), cost(n+1, INF);
    rep(i,n) cin >> a[i];

    a[n] = a[n-1];
    cost[n] = cost[n-1] = 0;
    rrep(i,n-1){
        ll one = abs(a[i] - a[i+1]) + cost[i+1];
        ll two = abs(a[i] - a[i+2]) + cost[i+2];
        
        cost[i] = min(one, two);
    }

    cout << cost[0] << endl;
}