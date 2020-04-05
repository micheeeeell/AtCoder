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
#define int ll

signed main(){
    ll n,q; cin >> n >> q;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> s(q);
    rep(i,q) cin >> s[i];
    vector ag(n, 0LL);
    ag[0] = a[0];
    reps(i,n-1)ag[i] = gcd(ag[i-1], a[i]);
    rep(i,q){
        ll ok = -1, ng = n;
        if(ll tmp = gcd(ag[n-1], s[i]);tmp != 1){
            cout << tmp << "\n";
            continue;
        }
        while(abs(ok - ng) > 1){
            ll x = (ok + ng) / 2;
            if(gcd(ag[x], s[i]) == 1)ng = x;
            else ok = x;
        }

        cout << ng + 1 << "\n";
    }
    return 0;
}