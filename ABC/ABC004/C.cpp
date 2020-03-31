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

void print(vector<ll> vec){
    for(auto i : vec)cout << i;
    cout << endl;
}

int main(){
    ll n; cin >> n;
    ll r = (n / 5) % 6;
    vector<ll> ans(6);
    rep(i,6)ans[i] = ((r + i) % 6) + 1;
    n %= 5;
    ll i = 0;
    while (n)
    {
        swap(ans[i], ans[i+1]);
        i++;
        n--;
    }
    
    print(ans);
}