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
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    vector<Pll> a(n);
    rep(i,n){
        ll t; cin >> t;
        a[i] = {t, i};
    }
    sort(all(a));
    set<ll> st;
    ll ans = 0;
    rep(i,n){
        auto p = st.insert(a[i].second);
        ll l, r;
        if(p.first == st.begin()){
            l = 0;
        }
        else{
            l = *(--p.first) + 1;
            p.first++;
        }
        if(p.first == --st.end())r = n-1;
        else r = *(++p.first) - 1;
        ans += a[i].first * (a[i].second - l + 1) * (r - a[i].second + 1);
        // debug(l);debug(r);debug(ans);
    }

    cout << ans << endl;
}