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
    string s;cin >> s;
    bool ok = true;
    string t = s;
    reverse(all(t));
    ll n = s.size();
    rep(i,n)if(s[i] != t[i])ok = false;
    string front = s.substr(0,(n-1)/2);
    string front_r = front;
    reverse(all(front_r));
    rep(i,front.size())if(front[i] != front_r[i])ok = false;
    string back = s.substr(((n+3)/2) - 1, (n-1)/2);
    string back_r = back;
    reverse(all(back_r));
    rep(i,back.size())if(back[i] != back_r[i])ok = false;

    cout << (ok ? "Yes" : "No") << endl;
}