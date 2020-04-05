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
    vector<ll> par(n);
    vector<ll> in(n);
    rep(i,n-1){
        ll a; cin >> a;
        a--;
        par[i+1] = a;
        in[a]++;
    }
    // print(par);
    vector<vector<ll>> stack(2);
    bitset<n_max> bs(0);
    rep(i,n)if(in[i] == 0){
        stack[0].emplace_back(i);
        bs[par[i]] = 1;
    }
    // print(stack[0]);
    ll cnt = 0, c = 0;
    ll all = n;
    while(all){
        bs &= 0;
        c = cnt & 1;
        // all -= stack[c].size();
        for(auto i : stack[c]){
            ll j = par[i];
            if(bs[j]){
                stack[c ^ 1].emplace_back(i);
                continue;
            }
            bs[j] = 1;
            in[j]--;
            if(in[j] == 0){
                stack[c ^ 1].emplace_back(j);
                // bs[par[j]] = 1;
            }
            all--;
        }

        // print(stack[c]);
        // debug(all);
        cnt++;stack[c].clear();
    }
    cout << cnt - 1 << endl;
}