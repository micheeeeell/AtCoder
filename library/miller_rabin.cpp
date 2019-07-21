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
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
const ll N = 1e9+7;
const int n_max = 1e5+10;

ll hs_pow(ll x, ll n){
    ll ret = 1;
    while(0 < n){
        if((n % 2) == 0){
            x *= x;
            n >>= 1;
        }
        else{
            ret *= x;
            n--;
        }
        // cout << ret  << ' ' << n  << ' ' << x << endl;
    }
    return ret;
}

bool is_prime(ll n){
    if(n == 2) return true;
    if(!(n % 2)) return false;
    if(n == 1 || n & 1 == 0) return false;

    ll d = (n -1) >> 1;
    while(d & 1 == 0) d >>= 1;

    random_device rnd;
    mt19937_64 mt(rnd());
    uniform_int_distribution<> rand(0,n-1);

    rep(i,100){
        ll a = rand(mt);
        ll t = d;
        ll y = hs_pow(a,t) % n;
        cout << a  << ' ' << t  << ' ' << y << endl;

        while(t != (n-1) && y != 1 && y != n-1){
            y = (y * y) % n;
            t <<= 1;
        }
        if(y != n-1 && t & 1 == 0) return false;
    }
    return true;

}

int main(){
    ll n;cin >> n;
    cout << is_prime(n) << endl;
    // cout << is_prime(hs_pow(2,89)) << endl;
    return 0;
}