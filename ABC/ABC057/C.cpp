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
const int n_max = 1e5+10;



// xの桁数を返す関数
int digit_max(ll x){
    int dig = 0;
    while(x > 0){
        dig++;
        x /= 10;
    }
    return dig;
}


template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

int main(){
    ll n; cin >> n;
    auto f = [&](ll x, ll y) -> ll{
        return max(digit_max(x), digit_max(y));
    };
    ll ans = INF;
    rep(i,sqrt(n)+1){
        if(i <= 0)continue;
        if(n % i == 0)chmin(ans, f(i,n/i));
    }
    cout << ans << endl;
}