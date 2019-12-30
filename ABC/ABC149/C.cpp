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

// エラストテネスの篩
const int N = 1e6+1;
bool is_prime[N];
void build_sieve(){
    fill(is_prime, is_prime + N, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i < N; ++i)if(is_prime[i]){
        for(int j = 2*i; j < N; j+=i)is_prime[j] = false;
    }
}

int main(){
    ll n; cin >> n;
    build_sieve();
    while(is_prime[n] == 0)n++;
    cout << n << endl;
}