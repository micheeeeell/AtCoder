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
    int n; cin >> n;
    auto is_prime = [](ll x) -> bool{
        bool ok = true;
        rep(i,sqrt(x+1)){
            if(i <= 1)continue;
            if(x%i == 0){ok = false;break;}
        }
        return ok;
    };

    int count = 0;
    vector<ll> res;
    ll temp_prime = 31;
    // res.push_back(temp_prime);
    while (count < n){
        // if(temp_prime == 1)continue;
        while(!is_prime(temp_prime))temp_prime += 30;
        res.push_back(temp_prime);
        ++count;
        temp_prime += 30;
    }

    print(res);
    return 0;

    // // 乱択で検証
    // vector<int> rand(5);
    // random_device rnd;
    // bool ok = true;
    // rep(i,100){
    //     int sum = 0;
    //     rep(j,5){
    //         int temp = rnd() % n;
    //         rand[j] = res[temp];
    //         sum += rand[j];
    //     }
    //     if(is_prime(sum)){
    //         ok = false;
    //         print(rand);
    //     }
    // }
    // print(ok);

}