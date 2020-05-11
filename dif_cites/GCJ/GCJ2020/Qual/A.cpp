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
const int n_max = 110;

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
    ll t; cin >> t;
    ll n;
    vector<ll> cnt(n_max), clear(n_max);
    rep(k, t)
    {
        cin >> n;
        vector<vector<ll>> graph(n, vector<ll>(n));
        rep(i,n)rep(j,n)cin >> graph[i][j];
        ll trace = 0;
        rep(i,n)trace += graph[i][i];
        ll r = 0;
        rep(i,n){
            rep(j,n){
                if(cnt[graph[i][j]]){
                    r++;
                    break;
                }
                cnt[graph[i][j]] = 1;
            }
            cnt = clear;
        }
        ll c = 0;
        rep(j,n){
            rep(i,n){
                if(cnt[graph[i][j]]){
                    c++;
                    break;
                }
                cnt[graph[i][j]] = 1;
            }
            cnt = clear;
        }
        cout << "Case #" << k + 1 << ": ";
        print(trace, r, c);
    }
}