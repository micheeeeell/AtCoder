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
    ll n,d,k; cin >> n >> d >> k;
    vector<ll> l(d), r(d);
    rep(i,d)cin >> l[i] >> r[i];
    rep(i,k){
        ll s,t; cin >> s >> t;
        bool go_right = s < t;
        rep(j,d){
            if(s < l[j] || r[j] < s)continue;
            if(go_right){
                s = r[j];
                if(s >= t){cout << j+1 << "\n";break;}
            }
            else {
                s = l[j];
                if(s <= t){cout << j+1 << "\n";break;}
            }
        }
    }
}