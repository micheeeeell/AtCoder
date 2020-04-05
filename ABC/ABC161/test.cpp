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
const int n_max = 1e5+10;

ll solve(ll n){
    vector<ll> vec;
    vec.emplace_back(n);
    for(ll i = 2; i * i <= n; i++){
        if(n % i == 0){
            vec.emplace_back(i);
            if(i * i != n)vec.emplace_back(n / i);
        }
    }

    // print(vec);

    auto f = [](int x, int a){
        assert(a % x == 0);
        while(a % x == 0)a /= x;
        a %= x;
        return a;
    };

    ll ans = 0;
    for(auto i : vec){
        if(f(i, n) == 1)ans++;
    }
    n--;
    for(ll i = 2; i * i <= n; i++){
        if(n % i == 0){
            if(i * i == n)ans += 1;
            else ans += 2;
        }
    }
    // n-1を足す
    if(n != 1)ans++;
    // cout << ans << endl;
    return ans;
}

ll guchoku(ll n){
    ll ans = 0;
    for(ll i = 2;i <= n; i++){
        ll temp = n;
        while(temp % i == 0)temp /= i;
        temp %= i;
        if(temp == 1)ans++;
    }

    return ans;
}

int main(){
    rep(i,1000000){
        if(i <= 1)continue;
        debug(i);
        assert(solve(i) == guchoku(i));
    }
}