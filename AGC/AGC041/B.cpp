#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define pb push_back
#define eb emplace_back
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
const ll MOD = 1e9+7;
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


int main(){
    ll n,m; cin >> n >> m;
    ll v,p; cin >> v >> p;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(all(a),greater<ll>());
    // print(a);
    auto check = [&](int ind){
        bool ret = true;
        // vector<ll> plus(n,0);
        ll cnt = 0;
        ll to = m+a[ind];
        // debug(ind);debug(to);debug(a[p-1]);
        if(to < a[p-1])return false;
        rep(i,n){
            if(i < p-1)cnt += m;
            else cnt += min(m,to - a[i]);
        }
        if(cnt < m*v)ret = false;
        return ret;
    };
    ll ok = 0;
    ll ng = n-1;
    assert(check(ok));
    if(check(ng)){
        cout << n << endl;
        return 0;
    }
    while(abs(ok - ng) > 1){
        ll x = (ok + ng) / 2;

        if(check(x))ok = x;
        else ng = x;
    }

    cout << ok+1 << endl;
}