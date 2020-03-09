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
    ll n,p; cin >> n >> p;
    string s;cin >> s;
    ll ans = 0;
    if(p == 2 || p == 5){
        rep(i,n){
            ll t = s[i] - '0';
            if(t % p == 0)ans += i+1;
        }

        cout << ans << endl;
        return 0;
    }

    vector<ll> ten(n,1);
    reps(i,n-1) ten[i] = ten[i-1] * 10 % p;
    map<ll,ll> map_;
    ll now = 0;
    map_[0] = 1;
    reverse(all(s));
    rep(i,n){
        ll t = s[i] - '0';
        now = (now + t * ten[i]) % p;
        ans += map_[now]++;
    }

    cout << ans << endl;
}