#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(int i = 0; i < x; i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
const ll MOD = 1e9+7;
const int n_max = 1e5+10;

// xを素因数分解する関数
// 連想配列で＜素因数，べき乗＞が帰る
// template<class T>
map<ll,int> prime(ll x){
    map<ll,int> e;
    rep(i,sqrt(x)+1){
        if(i <= 1)continue;
        while(x % i == 0){
            e[i]++;
            x /= i;
        }
    }
    if(x != 1)e[x]++;
    return e;
}

// エラストテネスの篩
const int N = 1e7+1;
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
    map<ll, int> e = prime(n);
    for(auto itr = e.begin(); itr != e.end();itr++){
        // print((*itr).first, (*itr).second);
        cout << (*itr).first << ' ' << (*itr).second << endl;
    }
    return 0;
}