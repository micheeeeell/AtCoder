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

void Case(int x){
    cout << "Case #" << x + 1 << ": ";
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll t; cin >> t;
    rep(q,t){
        ll n; cin >> n;
        using Plll = pair<Pll, ll>;
        vector<Plll> vec(n);
        rep(i,n){
            cin >> vec[i].first.first >> vec[i].first.second;
            vec[i].second = i;
        }
        sort(all(vec));
        string ans(n, '.');
        // rep(i,n)ans += '.';
        bool ok = true;
        ll c_last = -1, j_last = -1; 
        rep(i,n){
            auto w = vec[i].first;
            if(c_last <= w.first){
                ans[vec[i].second] = 'C';
                c_last = w.second;
            }
            else if(j_last <= w.first){
                ans[vec[i].second] = 'J';
                j_last = w.second;
            }
            else {
                ok = false;
                break;
            }
        }
        Case(q);
        cout << (ok ? ans : "IMPOSSIBLE") << endl;
    }
}

