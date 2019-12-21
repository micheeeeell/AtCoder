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
#define mp make_pair
#define debug(x) cerr << #x << ": " << (x) << "\n";
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
const ll INF = LLONG_MAX/4;
const ll MOD = 1e9+7;
const int n_max = 1e5+10;
ll modinv(ll a, ll m){
    ll b = m, u = 1, v = 0;
    while(b){
        ll t = a/b;
        a -= t * b; swap(a,b);
        u -= t * v; swap(u,v);
    }
    u %= m;
    if(u < 0) u += m;
    return u;

}
int main(){
    ll A,B,C; cin >> A >> B >> C;
    ll t = C*(A-B)+A*B;
    t %= MOD;
    while(t < 0)t += MOD;
    ll rev = modinv(t, MOD);
    ll rt = C*(B-A) % MOD;
    while(rt < 0)rt += MOD;

    ll ct = B*(C-A) % MOD;
    while(ct < 0)ct += MOD;
    ll r = rt * rev % MOD;
    ll c = ct * rev % MOD;
    cout << r << ' ' << c << endl;
}