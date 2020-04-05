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
#define int ll 

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


signed main(){
    int n; cin >> n;
    vector<int> vec;
    vec.emplace_back(n);
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            vec.emplace_back(i);
            if(i * i != n)vec.emplace_back(n / i);
        }
    }

    // print(vec);

    auto f = [](int x, int a){
        // a % x == 0
        while(a % x == 0)a /= x;
        a %= x;
        return a;
    };

    int ans = 0;
    for(auto i : vec){
        if(f(i, n) == 1)ans++;
    }

    n--;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            if(i * i == n)ans += 1;
            else ans += 2;
        }
    }
    // n-1を足す
    if(n != 1)ans++;

    cout << ans << endl;
}