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


const ll N = 1e9+7;
const ll M = 2*1e5+5;
ll dp[M], invdp[M], inv[M];


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

void expo(){
    dp[0] = 1;
    invdp[0] = 1;
    inv[0] = 1;
    rep(i,M){
        dp[i+1] = dp[i] * (i + 1) % N;
        inv[i+1] = N - inv[N%(i+1)] * (N/(i+1)) % N;
        invdp[i+1] = modinv(dp[i+1], N);
    }
}


ll conv(ll x, ll y){
    ll ans;
    if(y > 0) ans = dp[x] * (invdp[y] * invdp[x-y] %N) % N;
    else ans = 1;
    // cout << dp[x] << " " << invdp[y] << " " << invdp[x-y] << " " << ans << endl;
    return ans;
}


void print() {
    cout << endl;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
    cout << head;
    if (sizeof...(tail) != 0) cout << ' ';
    print(forward<Tail>(tail)...);
}

template <class T>
void print(vector<T> &vec) {
    for (auto& a : vec) {
        cout << a;
        if (&a != &vec.back()) cout << ' ';
    }
    cout << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
    for (auto& vec : df) {
        print(vec);
    }
}

template<typename T>
void print(T &arr){
    ll sz = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0;i < sz-1;i++){cout << arr[i] << ' ';}
    cout << arr[sz-1] << endl;
}


int main(){
    ll n,m; cin >> n >> m;
    map<ll,ll> e;
    ll temp = m;
    rep(i,sqrt(m)+1){
        if(i <= 1)continue;
        while(temp % i == 0){
            e[i]++;
            temp /= i;
        }
    }
    if(temp != 1)e[temp]++;
    // for(auto itr = e.begin(); itr != e.end();itr++){
    //     print((*itr).first, (*itr).second);
    // }

    expo();

    ll ans = 1;
    for(auto itr = e.begin(); itr != e.end();itr++){
        // print((*itr).first, (*itr).second);
        ans = (ans * conv((*itr).second+n-1,(*itr).second)) % MOD;
    }

    cout << ans << endl;
    return 0;
}