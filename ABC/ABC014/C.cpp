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
const int m_max = 1e6+10;

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}
int main(){
    ll n; cin >> n; 
    vector<ll> vec(m_max);
    rep(i,n){
        ll a,b; cin >> a >> b;
        b++;
        vec[a]++;
        vec[b]--;
    }
    rep(i,m_max-1)vec[i+1] += vec[i];

    ll ans = 0;
    rep(i,m_max)chmax(ans, vec[i]);

    auto print = [&](ll x){
        rep(i,x)cout << vec[i] << " ";
        cout << endl;
    };
    // print(10);
    cout << ans << endl;
}