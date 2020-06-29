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
    for(int i = 2; i * i <= x; i++){
        while(x % i == 0){
            e[i]++;
            x /= i;
        }
    }
    if(x != 1)e[x]++;
    return e;
}

// 最小公倍数を因数分解された形で持つ
// 入力のmap_を適宜更新していく
void lcm_map(ll x, map<ll,ll> &map_){
    for(ll i = 2; i * i <= x; i++){
        if(i <= 1)continue;
        ll cnt = 0;
        while(x % i == 0){
            cnt++;
            if(map_[i] < cnt)map_[i] = cnt;
            x /= i;
        }
    }
    if(x != 1)if(map_[x] < 1)map_[x]++;
    // return map_;
}

// xと元の数をかけた時の値を因数分解された形で更新する
void prime_map(ll x, map<ll,ll> &map_){
    for(ll i = 2; i * i <= x; i++){
        while(x % i == 0){
            map_[i]++;
            x /= i;
        }
    }
    if(x != 1)map_[x]++;
    // return map_;
}

// エラストテネスの篩
const ll N = 1e6+10;
bitset<N> is_prime(0);
void build_sieve(){
    is_prime = ~is_prime;
    is_prime[0] = is_prime[1] = 0;
    for(ll i = 2; i < N; ++i)if(is_prime[i]){
        for(ll j = 2*i; j < N; j+=i)is_prime[j] = 0;
    }
}

int main(){
    ll n; cin >> n;
    map<ll, int> e = prime(n);
    for(auto itr = e.begin(); itr != e.end();itr++){
        // print((*itr).first, (*itr).second);
        cout << (*itr).first << ' ' << (*itr).second << endl;
    }

    build_sieve();
    // rep(i,n)cout << is_prime[i] << " ";
    // cout << endl;
    return 0;
}