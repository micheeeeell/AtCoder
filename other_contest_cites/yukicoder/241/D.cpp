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
    ll n,q; cin >> n >> q;
    vector<ll> a(n),b(n);
    vector<Pll> ab(n);
    rep(i,n){
        ll a,b; cin >> a >> b;
        ab[i] = {a,b};
    }
    sort(all(ab));
    rep(i,n){
        a[i] = ab[i].first;
        b[i] = ab[i].second;
    }
    // rep(i,n)cin >> a[i] >> b[i];
    vector<ll> sum_ab(n+1), sum_b(n+1);
    rep(i,n){
        sum_ab[i+1] = sum_ab[i] + a[i] * b[i];
        sum_b[i+1] = sum_b[i] + b[i];
    }
    vector<ll> x(q);
    rep(i,q) cin >> x[i];
    rep(i,q){
        ll id = lower_bound(all(a), x[i]) - a.begin();
        // debug(id);
        ll ans = 0;
        ans -= sum_ab[id] - sum_ab[0];
        ans += sum_ab[n] - sum_ab[id];
        ans += x[i] * (sum_b[id] - sum_b[0]);
        ans -= x[i] * (sum_b[n] - sum_b[id]);
        cout << ans << "\n";
    }
}