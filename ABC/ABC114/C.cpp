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

// template <class T>
vector<ll> res;
vector<int> number = {3,5,7};
void dfs(ll n, ll x){
    if(n < x)return;
    res.push_back(x);
    for(auto i : number){
        dfs(n, x*10+i);
    }
}

int main(){
    ll n; cin >> n;

    auto num = [](ll x, int digit) -> int{
        ll t1 = x/pow(10,digit-1);
        ll t2 = (x/pow(10,digit));
        // print(t1,t2);
        return t1 - t2 * 10;
    };
    auto check = [&](ll x) -> bool{
        int digit = 0;
        while(x/pow(10,digit) >= 1)digit++;
        bool ok = true;
        int count[3] = {};
        rep(i,digit){
            int temp = num(x,i+1);
            if(temp == 3)count[0]++;
            if(temp == 5)count[1]++;
            if(temp == 7)count[2]++;
        }
        rep(i,3)if(count[i] == 0)ok = false;
        return ok;
    };
    // cout << num(n,2) << endl;
    // cout << check(n) << endl;
    dfs(n,0);
    ll ans = 0;
    for(auto i : res){
        if(check(i))++ans;
    }
    cout << ans << endl;
    return 0;
}