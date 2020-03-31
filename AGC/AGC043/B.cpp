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
const int n_max = 1e6+10;

vector<ll> fact(n_max+1,0);
void build(){
    // vector<ll> temp(n_max);
    for(ll i = 2; i < n_max; i *= 2){
        for(ll j = 1; i * j < n_max; j++){
            fact[i * j]++;
        }
    }
    rep(i,n_max)fact[i+1] += fact[i];
}
void print(vector<ll> vec, int n){
    rep(i,n)cout << vec[i] << " ";
    cout << endl;
}
bool is_odd(int n, int k){
    return (fact[n] - fact[k] - fact[n-k]) == 0;
};
int main(){
    ll n; cin >> n;
    string s;cin >> s;
    build();
    // print(fact, 10);
    bool two = false;
    ll ans = 0;
    rep(i,n){
        ll t = s[i] - '0';
        if(t == 2)two = true;
        ans += (t & 1) * is_odd(n-1,i);
        ans &= 1;
        // debug(i);debug(ans);
    }

    if(ans == 1){
        cout << ans << endl;
        return 0;
    }
    if(two){
        cout << 0 << endl;
        return 0;
    }

    ans = 0;
    vector<ll> vec(n-1);
    rep(i,n-1){
        vec[i] = abs(s[i] - s[i+1]);
        vec[i] /= 2;
    }
    rep(i,n-1){
        ans += vec[i] * is_odd(n-2, i);
        ans &= 1;
    }

    cout << ans * 2 << endl;
}