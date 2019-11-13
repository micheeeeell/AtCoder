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
const ll MOD = 1e9+7;
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

ll guchoku(vector<ll>& vec, ll goal){
    ll n = vec.size();
    ll res = LLONG_MAX;
    
    rep(i,(1 << n)){
        ll temp = 0;
        rep(j,n){
            if((i >> j) & 1)temp += vec[j];
            else temp -= vec[j];
        }
        res = min(res, abs(goal-temp));
    }
    return res;
}

ll solve(vector<ll>& vec, ll goal){
    ll n = vec.size();

    sort(all(vec), greater<ll>());
    ll res = 0;
    rep(i,n){
        if(res > goal)res -= vec[i];
        else res += vec[i];
    }

    return min(abs(goal - res), abs(goal + res) );

}

ll dyp(vector<ll>& vec, ll goal){
    ll n = vec.size();
    ll MAX = 1e5 + 10;
    vvl dp(n+1,vl(2*MAX,0));
    dp[0][MAX] = 1;
    rep(i,n){
        rep(j,2*MAX){
            if(dp[i][j]){
                dp[i+1][j+vec[i]] = 1;
                dp[i+1][j-vec[i]] = 1;
                // dp[i+1][j] = 1;
            }
        }
    }
    ll res = LLONG_MAX;
    rep(i,MAX*2){
        // if(i == MAX)continue;
        if(dp[n][i])res = min(res, abs(goal-abs(i-MAX)));
    }
    return res;
}

int main(){
    random_device rand;
    rep(i,100){
        ll n = rand() % 10 + 1;
        vector<ll> vec(n);
        rep(i,n){
            vec[i] = rand() % 100;
        }
        ll goal = rand() % 100;

        ll g = guchoku(vec,goal);
        ll s = solve(vec,goal);
        ll d = dyp(vec,goal);

        if(g != d){
            cout << "g != d" << endl;
            print(vec);
            print(goal);
            print(g,d);
        }
    }
}