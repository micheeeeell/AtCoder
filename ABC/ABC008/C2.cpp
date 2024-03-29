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

// パスカルの三角形で求める方法
// 時間計算量はO(MAX^2)
const int MAX = 101;
vector<vector<ll>> com(MAX+1,vector<ll>(MAX+1,0));
void COMinit(){
    com[0][0] = 1;
    rep(i,MAX){
        rep(j,MAX){
            if(i == 0 || j == 0)com[i][j] = 1;
            else com[i][j] = com[i][j-1] + com[i-1][j];
        }
    }
}
ll COM(ll n, ll k){
    return com[n-k][k];
}

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
    vector<ll> c(n);
    rep(i,n) cin >> c[i];
    vector<ll> count(n);
    rep(i,n){
        rep(j,n){
            if(i == j)continue;
            if(c[i] % c[j] == 0)count[i]++;
        }
    }

    // print(count);

    ld ans = 0;
    ld s;
    rep(i,n){
        s = count[i];
        if(count[i] & 1){
            ans += 0.5;
        }
        else{
            ans += ld(s+2) / ld(2 * s + 2);
        }
    }

    cout << fixed << setprecision(15) << ans << endl;
}