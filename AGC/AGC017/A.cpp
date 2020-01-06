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


const int MAX = 51;
vector<vector<ll>> COM(MAX+1,vector<ll>(MAX+1,0));
void COMinit(){
    COM[0][0] = 1;
    rep(i,MAX){
        rep(j,MAX){
            if(i == 0 || j == 0)COM[i][j] = 1;
            else COM[i][j] = COM[i][j-1] + COM[i-1][j];
        }
    }
}
ll com(ll n, ll k){
    return COM[n-k][k];
}
ll pow(ll a, ll b){
    ll ret = 1;
    rep(i,b)ret *= a;
    return ret;
}
int main(){
    ll n,p; cin >> n >> p;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> re(2,0);
    rep(i,n)re[a[i]%2]++;
    ll ans = 0;
    COMinit();
    // print(COM);
    if(p == 0){
        ll odd = 0, even = 0;
        rep(i,re[1]/2+1)odd += com(re[1],i*2);
        even = pow(2,re[0]);
        ans = odd * even;
    }
    else{
        ll odd = 0, even = 0;
        even = pow(2,re[0]);
        for(int i = 1;i < re[1]; i += 2)odd += com(re[1],i);
        ans = even * odd;
    }
    cout << ans << endl;
}