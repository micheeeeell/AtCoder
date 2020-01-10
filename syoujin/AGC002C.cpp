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

template<class T, class U>
void print(pair<T,U> p){
    cout << p.first << " " << p.second << "\n";
}
int main(){
    ll n,l; cin >> n >> l;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> ans;
    bool ok = false;
    ll last = 0;
    rep(i,n-1)if(a[i] + a[i+1] >= l){
        ok = true;
        last = i;
    }
    rep(i,last)ans.emplace_back(i+1);
    for(int i = n-2;last < i; i--)ans.emplace_back(i+1);
    ans.emplace_back(last+1);
    debug(last);
    if(ok){
        cout << "Possible" << endl;
        print(ans);
    }
    else cout << "Impossible" << endl;
}