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
    ll r;
    while((r = a%b)){
        a = b;
        b = r;
    }
    return b;
}


int main(){
    ll n,m; cin >> n >> m;
    string s;cin >> s;
    string t;cin >> t;
    ll g = euclid_gcd(n,m);
    string s_c, t_c;
    for(int i = 0; i < n; i += n/g)s_c += s[i];
    for(int i = 0; i < m; i += m/g)t_c += t[i];
    debug(s_c);debug(t_c);
    cout << (s_c == t_c ? n*(m/g) : -1) << endl;
}