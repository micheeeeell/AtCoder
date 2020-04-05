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
    vector a(3, 0LL);
    rep(i,3)cin >> a[i];
    vector<ll> l(a[0]), m(a[1]), r(a[2]);
    vector vec(a[0]+a[1]+a[2], 0LL);
    iota(all(vec), 0);
    ll ans = 0;
    do{
        bool ok = true;
        rep(i, a[0])l[i] = vec[i];
        rep(j, a[1])m[j] = vec[a[0] + j];
        rep(k, a[2])r[k] = vec[a[0]+a[1] + k];


        rep(i,a[0]-1)ok &= l[i+1] < l[i];
        rep(j,a[1]-1)ok &= m[j+1] < m[j];
        rep(k,a[2]-1)ok &= r[k+1] < r[k];

        rep(j,a[1])ok &= l[j] > m[j];
        rep(k, a[2])ok &= m[k] > r[k];

        // print(l);
        // print(m);
        // print(r);
        // debug(ok);
        // print();
        ans += ok;
    }while(next_permutation(all(vec)));

    cout << ans << endl;
}