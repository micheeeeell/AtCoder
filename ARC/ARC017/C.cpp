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
    ll n,x; cin >> n >> x;
    vector<ll> w(n);
    rep(i,n) cin >> w[i];
    ll f = n / 2, b = n - f;
    vector<ll> front(f), back(b);
    rep(i,f)front[i] = w[i];
    rep(i,b)back[i] = w[f + i];

    vector<ll> front_all, back_all;
    rep(i,(1LL << f)){
        ll temp = 0;
        rep(j,f){
            if((i >> j) & 1)temp += front[j];
        }
        front_all.emplace_back(temp);
    }
    rep(i, (1LL << b)){
        ll temp = 0;
        rep(j,b){
            if((i >> j) & 1)temp += back[j];
        }
        back_all.emplace_back(temp);
    }
    sort(all(back_all));

    // print(front);
    // print(front_all);
    // print(back);
    // print(back_all);

    ll ans = 0;
    for(auto i : front_all){
        ll t = upper_bound(all(back_all), x - i) - lower_bound(all(back_all), x - i);
        ans += t;
        // debug(i);debug(t);
    }

    cout << ans << endl;
}