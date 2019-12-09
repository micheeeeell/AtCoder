#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(int i = 0; i < (int)(x); i++)
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
const int n_max = 1e5+10;

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

// template<typename T>
// void print(T &arr){
//     ll sz = sizeof(arr)/sizeof(arr[0]);
//     for(int i = 0;i < sz-1;i++){cout << arr[i] << ' ';}
//     cout << arr[sz-1] << endl;
// }


int main(){
    ll n,k; cin >> n >> k;
    vector<ll> a;
    rep(i,n){
        ll temp;cin >> temp;
        if(k <= temp)continue;
        a.emplace_back(temp);
    }
    // vector<vector<ll>> dp(2,vector<ll>(2 * k+100, 0));
    // ll kmax = 2*k+100;
    ll sz = a.size();
    if(sz == 0){cout << 0 << endl;return 0;}
    bool dp[sz+1][k];
    rep(i,sz+1)fill(dp[i], dp[i]+k, false);
    dp[0][0] = true;
    rep(i,sz){
        rep(j,k){
            dp[i+1][j] = dp[i][j];
            if(a[i] <= j)dp[i+1][j] |= dp[i][j-a[i]];
        }
        
    }
    // bool dp2[sz][kmax];
    
    // rep(i,sz){
    //     rep(j,kmax){
    //         dp2[i][j] = dp[sz%2][j];
    //         if(a[i] <= j){
    //             if(dp[sz%2][j] && dp[sz%2][j-a[i]])dp2[i][j] = false;
    //         }
    //     }
    // }

    // ll cnt = 0;
    // rep(i,sz){
    //     bool temp = false;
    //     rep(j,a[i])temp |= dp2[i][k-j-1];
    //     if(temp)cnt++;
    //     debug(a[i]);
    //     rep(j,50)cerr << dp2[i][j] << " ";
    //     print();
    // }
    
    
    // cout << sz - cnt << endl;

    bool dp2[sz+1][k];
    rep(i,sz+1)fill(dp2[i],dp2[i] + k, false);
    dp2[sz][0] = 1;
    for(int i = sz; 0 < i; i--){
        rep(j,k){
            dp2[i-1][j] = dp2[i][j];
            if(a[i-1] <= j)dp2[i-1][j] |= dp2[i][j-a[i-1]];
        }
    }
    // 上からと下からをO(K)でマージする方法がわからん

    // 必要ならtrueを返す
    auto check = [&](int index) -> bool{
        bool d[sz][k];
        rep(i,sz)fill(d[i], d[i] + k, false);
        bool res = false;
        d[0][0] = 1;
        int cnt = 0;
        rep(i,sz-1){
            if(cnt == index){
                i--;
                cnt++;
                continue;
            }
            rep(j,k){
                d[i+1][j] = d[i][j];
                if(a[cnt] <= j)d[i+1][j] |= d[i][j-a[cnt]];
            }
            cnt++;
        }
        rep(i,a[index])res |= d[sz-1][k-i-1];
        return res;
    };
    sort(all(a));
    int ok = sz-1;
    int ng = 0;
    if(!check(ok)){
        cout << ok+1 << endl;
        return 0;
    }
    else if(check(ng)){
        cout << ng << endl;
        return 0;
    }
    while(abs(ok - ng) > 1){
        int x = (ok + ng)/2;
        if(check(x))ok = x;
        else ng = x;
        debug(ok);
        debug(ng);
    }
    cout << ng+1 << endl;
    return 0;
}