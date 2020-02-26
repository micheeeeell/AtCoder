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
    ll n,a,b; cin >> n >> a >> b;
    if(a + b - 1 > n || a * b < n){
        cout << -1 << endl;
        return 0;
    }
    if(a == 1 || b == 1){
        vector<ll> ans(n);
        iota(all(ans), 1);
        if(b == 1){
            print(ans); 
            return 0;
        }
        reverse(all(ans));
        print(ans);
        return 0;
    }
    
    ll k = (n - b) / (a - 1);
    // if(a * k > n)k--;
    ll r = (n - b + 1) - k * (a - 1);
    debug(k);debug(r);
    vector<ll> ans;
    ll max_ = n;
    rep(i,k){
        for(int j = max_ - a + 1; j <= max_; j++)ans.emplace_back(j);
        max_ -= a;
    }
    if(max_ == 0){
        print(ans);
        return 0;
    }
    for(int i = max_ - r + 1; i <= max_; i++)ans.emplace_back(i);
    max_ -= r;

    debug(max_);

    while(max_){
        ans.emplace_back(max_);   
        max_--;
    }

    print(ans);
}