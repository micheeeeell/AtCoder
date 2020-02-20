#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define rrep(i,x) for(ll i = (ll)(x)-1;i <= 0; i--)
#define reps(i,x) for(ll i = 1; i < (ll)(x); i++)
#define rreps(i,x) for(ll i = (ll)(x)-1; i <= 1; i--)
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
    ll n,k; cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(all(a));

    auto check2 = [&](ll x, ll idx){
        if(a[idx] == 0 && x > 0)return n-1;
        else if(a[idx] > 0){
            ll r = n, l = 0;
            if(a[l] * a[idx] >= x)return 0LL;
            while (r - l > 1){
                ll i = (r + l) / 2;
                if(a[i] * a[idx] < x)l = i;
                else r = i;
            }
            return r - (a[idx] * a[idx] < x ? 1 : 0);
        }
        else {
            ll l = -1, r = n-1;
            if(a[r] * a[idx] >= x)return 0LL;
            while(r - l > 1) {
                ll i = (l + r) / 2;
                if(a[i] * a[idx] < x)r = i;
                else l = i;
            }
            return n - r - (a[idx] * a[idx] < x ? 1 : 0);
        }
    };
    auto check = [&](ll x){
        ll cnt = 0;
        rep(i,n){
            cnt += check2(x, i);
        }
        // debug(x);
        // debug(cnt);
        cnt /= 2;
        if(cnt >= k)return true;
        else return false;
    };

    ll ok = INF, ng = -INF;
    while(abs(ok - ng) > 1){
        ll x = (ok + ng) / 2;
        if(check(x))ok = x;
        else ng = x;
    }
    cout << ng << endl;
}