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
    string s,t; cin >> s >> t;
    ll q; cin >> q;
    vector<ll> ssum(s.size() + 1), tsum(t.size() + 1);
    rep(i,s.size())ssum[i+1] = ssum[i] + (s[i] == 'A' ? 1 : 2);
    rep(i,t.size())tsum[i+1] = tsum[i] + (t[i] == 'A' ? 1 : 2);
    rep(i,q){
        ll a,b; cin >> a >> b;
        a--;
        ll c,d; cin >> c >> d;
        c--;
        if((ssum[b] - ssum[a]) % 3 == (tsum[d] - tsum[c]) % 3){
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
    }
}