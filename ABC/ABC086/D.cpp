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
    ll n,k; cin >> n >> k;
    // vector<vector<string>> mp(k,vector<string>(2*k));
    vector<vector<ll>> b_mp(2*k,vector<ll>(2*k,0)), w_mp(2*k,vector<ll>(2*k,0));
    rep(i,n){
        ll x,y; cin >> x >> y;
        string s;cin >> s;
        // x--;y--;
        x %= 2*k;y %= 2*k;
        // mp[x][y] = s;
        if(s == "B")b_mp[x][y] += 1;
        else w_mp[x][y] += 1;
    }
    vector<vector<ll>> b_acc(2*k+1,vector<ll>(2*k+1,0)), w_acc(2*k+1,vector<ll>(2*k+1,0));

    for(int i = 1;i < 2*k+1;i++){
        for(int j = 1;j < 2*k+1;j++){
            b_acc[i][j] = b_acc[i][j-1] + b_acc[i-1][j] - b_acc[i-1][j-1] + b_mp[i-1][j-1];
            w_acc[i][j] = w_acc[i][j-1] + w_acc[i-1][j] - w_acc[i-1][j-1] + w_mp[i-1][j-1];
        }
    }
    // print();
    // print(w_acc);
    // print();
    // print(b_acc);
    ll res = 0;

    auto w_a = [&](int xs, int ys, int xe, int ye){
        ll res = 0;
        res = w_acc[xe][ye] - w_acc[xe][ys] - w_acc[xs][ye] + w_acc[xs][ys];
        return res;
    };
    auto b_a = [&](int xs, int ys, int xe, int ye){
        ll res = 0;
        res = b_acc[xe][ye] - b_acc[xe][ys] - b_acc[xs][ye] + b_acc[xs][ys];
        return res;
    };

    rep(i,k+1){
        rep(j,k+1){
            ll w = 0, b = 0;
            w += w_a(i,j,0,0);
            w += w_a(i,2*k,0,j+k);
            // w += w_acc[i+k][j+k] - w_acc[i][j];
            w += w_a(i+k,j+k,i,j);
            // w += w_acc[2*k][j] - w_acc[i+k][0];
            w += w_a(2*k,j,i+k,0);
            // w += w_acc[2*k][2*k] - w_acc[i+k][j+k];
            w += w_a(2*k,2*k,i+k,j+k);

            // b += b_acc[i][j+k] - b_acc[0][j];
            b += b_a(i,j+k,0,j);
            // b += b_acc[i+k][j] - b_acc[i][0];
            b += b_a(i+k,j,i,0);
            // b += b_acc[i+k][2*k] - b_acc[i][j+k];
            b += b_a(i+k,2*k,i,j+k);
            // b += b_acc[2*k][j+k] - b_acc[i+k][j];
            b += b_a(2*k,j+k,i+k,j);

            // print(i,j,w,b);
            res = max(res, b+w);

            w = 0;
            b = 0;
            b += b_a(i,j,0,0);
            b += b_a(i,2*k,0,j+k);
            b += b_a(i+k,j+k,i,j);
            b += b_a(2*k,j,i+k,0);
            b += b_a(2*k,2*k,i+k,j+k);

            w += w_a(i,j+k,0,j);
            w += w_a(i+k,j,i,0);
            w += w_a(i+k,2*k,i,j+k);
            w += w_a(2*k,j+k,i+k,j);

            // print(i,j,w,b);
            res = max(res, b+w);

        }
    }
    cout << res << endl;
}