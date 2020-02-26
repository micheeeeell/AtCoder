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

void print() {
    cout << endl;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
    cout << head;
    if (sizeof...(tail) != 0) cout << ' ';
    print(forward<Tail>(tail)...);
}

template <class T>
void print(vector<T> &vec) {
    for (auto& a : vec) {
        cout << a;
        if (&a != &vec.back()) cout << ' ';
    }
    cout << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
    for (auto& vec : df) {
        print(vec);
    }
}

template<class T, class U>
void print(pair<T,U> &p){
    print(p.first, p.second);
}

int main(){
    ll n,q; cin >> n >> q;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> x(q);
    rep(i,q) cin >> x[i];
    auto up = [&](ll x){
        ll ok = n, ng = -1;
        while(abs(ok - ng) > 1){
            ll m = (ok + ng) / 2;
            if(a[m] > x)ok = m;
            else ng = m;
        }
        return ok;
    };
    auto low = [&](ll x){
        ll ok = n, ng = -1;
        while(abs(ok - ng) > 1){
            ll m = (ok + ng) / 2;
            if(a[m] >= x)ok = m;
            else ng = m;
        }
        return ok;
    };
    vector<ll> odd(n+1, 0), even(n+1, 0), sum(n+1,0);
    rep(i,n){
        if(i & 1){
            odd[i+1] = odd[i] + a[i];
            even[i+1] = even[i];
        }
        else{
            odd[i+1] = odd[i];
            even[i+1] = even[i] + a[i];
        }
        sum[i+1] = sum[i] + a[i];
    }
    // print(sum);print(odd);print(even);

    rep(i,q){
        ll ok = 0, ng = 1e9 + 10;
        while(abs(ok - ng) > 1){
            ll med = (ok + ng) / 2;
            ll r = up(x[i] + med), l = low(x[i] - med);
            if(r - l <= n - r)ok = med;
            else ng = med;
        }
        ll r = up(x[i] + ok);
        // debug(x[i]);debug(ok);debug(r);
        ll ans = sum[n] - sum[r];
        if(n & 1){
            if(2 * r >= n)ans += even[2*r - n];
        }
        else{
            if(2 * r >= n)ans += odd[2*r-n];
        }
        cout << ans << "\n";
    }
}