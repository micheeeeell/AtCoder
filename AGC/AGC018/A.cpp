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

template <class T, class U>
ll euclid_gcd(T a, U b){
    if(a < b)return euclid_gcd(b,a);
    if(a == 0 || b == 0)return 1;
    ll r;
    while((r = a%b)){
        a = b;
        b = r;
    }
    return b;
}
template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}
int main(){
    ll n,k; cin >> n >> k;
    vector<ll> a(n);
    ll ma = 0;
    rep(i,n) {cin >> a[i]; chmax(ma,a[i]);}

    ll g = euclid_gcd(a[0], a[1]);
    for(int i = 2; i < n; i++){
        g = euclid_gcd(g,a[i]);
        if(g == 1)break;
    }

    cout << ((k%g == 0) && (k <= ma) ? "POSSIBLE" : "IMPOSSIBLE") << endl;
}