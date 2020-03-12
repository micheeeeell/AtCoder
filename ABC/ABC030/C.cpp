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
    ll n,m; cin >> n >> m;
    ll x,y; cin >> x >> y;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> b(m);
    rep(i,m) cin >> b[i];

    auto low = [&](ll x, vector<ll> &vec){
        ll ok = vec.size();
        ll ng = -1;
        while(abs(ok - ng) > 1){
            ll id = (ok + ng) / 2;
            if(vec[id] >= x)ok = id;
            else ng = id;
        }
        return ok;
    };
    ll time = 0;
    bool ok = true;
    ll ans = 0;
    while(true){
        auto itr = lower_bound(all(a), time);
        if(itr == a.end())ok = false;
        time = *itr + x;
        itr = lower_bound(all(b), time);
        if(itr == b.end())ok = false;
        time = *itr + y;
        if(ok)ans++;
        else break;
    }

    cout << ans << endl;
}