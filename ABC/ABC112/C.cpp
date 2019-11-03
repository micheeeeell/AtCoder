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
    int n; cin >> n;
    ll INF = INT_MAX;
    vector<vector<ll>> cood(101, vector<ll>(101,INF));
    vector<pair<ll,pair<int,int>>> hxy(n);
    rep(i,n){
        int x,y; cin >> x >> y;
        ll h; cin >> h;
        hxy[i] = make_pair(h, make_pair(x,y));
    }
    sort(hxy.begin(), hxy.end(),
    [](auto const &a, auto const &b) -> bool{
        return a.first > b.first; 
    }
    );
    rep(i,n){
        int x = hxy[i].second.first, y = hxy[i].second.second;
        ll h = hxy[i].first;
        if(h == 0){
            rep(jx,101)rep(jy,101){
                if(cood[jx][jy] == -1)continue;
                if(cood[jx][jy] == INF)continue;
                else if(cood[jx][jy] - abs(jx - x) - abs(jy - y) > 0){
                    cood[jx][jy] = -1;
                }
            }  
        }
        else{
            rep(jx,101)rep(jy,101){
                if(cood[jx][jy] == -1)continue;
                ll temp = h + abs(jx - x) + abs(jy - y);
                if(cood[jx][jy] == INF)cood[jx][jy] = temp;
                else if(cood[jx][jy] != temp)cood[jx][jy] = -1;
            }
        }
    }
    // vector<ll> res;
    rep(ix,101)rep(iy,101){
        if(cood[ix][iy] != -1 && cood[ix][iy] != INF){
            print(ix,iy,cood[ix][iy]);
        }
    }
    // for(auto i : res)cout << i << endl;
    return 0;
}