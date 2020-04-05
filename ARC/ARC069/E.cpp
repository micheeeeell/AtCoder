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
    ll n; cin >> n;
    vector<Pll> a(n);
    ll sum = 0;
    rep(i,n){
        ll x; cin >> x;
        a[i] = {x, i};
        sum += x;
    }

    vector<ll> ans(n);

    sort(all(a), greater<Pll>());
    // for(auto p : a)print(p);
    auto p = a[0];
    ll cnt = 1;
    while(p.second != 0){
        while(p.first == a[cnt].first && cnt < n){
            p.second = min(a[cnt++].second, p.second);
        }
        if(cnt == n)continue;
        if(p.second == 0)continue;
        ans[p.second] += cnt * (p.first - a[cnt].first);
        sum -= cnt * (p.first - a[cnt].first);
        // print(p);
        p.first = a[cnt].first;
        // print(p);
        // debug(cnt);
        // print();
    }
    ans[0] += sum;
    print(ans);
}