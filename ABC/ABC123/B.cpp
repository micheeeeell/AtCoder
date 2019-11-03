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

// template<typename T>
// void print(T &arr){
//     ll sz = sizeof(arr)/sizeof(arr[0]);
//     for(int i = 0;i < sz-1;i++){cout << arr[i] << ' ';}
//     cout << arr[sz-1] << endl;
// }

int main(){
    vector<int> price(5);
    rep(i,5)cin >> price[i];
    int res = INT_MAX;
    sort(price.begin(), price.end());
    do{
        int temp = 0;
        rep(i,4){
            temp += price[i];
            temp = ceil(temp / 10.0) * 10;
            // print(price[i], temp);
        }
        temp += price[4];
        // print(price);
        // print(temp);
        res = min(res, temp);
    }while(next_permutation(price.begin(), price.end()));
    cout << res << endl;
    return 0;
}