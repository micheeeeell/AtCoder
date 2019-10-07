#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define repr(i,j,x) for(int i = j; i < x; i++)
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


int main(){
    int n; cin >> n;
    vector<ll> e(n+10,0);

    auto prime = [&](int x){
        bool ok = true;
        rep(i,x){
            if(i <= 1)continue;
            if(x%i == 0){ok = false;break;}
        }
        return ok;
    };
    repr(i,2,n+1){
        int cur = i;
        repr(j,2,i+1){
            if(!prime(j))continue;
            while(cur % j == 0){
                e[j]++;
                cur /= j;
            }
        }
    }

    // print(e);
    ll count = 0;
    rep(i,e.size()){
        if(!e[i])continue;
        rep(j,e.size()){
            if(!e[j])continue;
            if(i >= j)continue;
            rep(k,e.size()){
                if(!e[k])continue;
                if(j >= k)continue;
                if(e[i] >= 4 && e[j] >= 4 && e[k]>= 2)count++;
                if(e[i] >= 4 && e[j] >= 2 && e[k]>= 4)count++;
                if(e[i] >= 2 && e[j] >= 4 && e[k]>= 4)count++;
            }
        }
    }

    rep(i,e.size()){
        if(!e[i])continue;
        rep(j,e.size()){
            if(!e[j])continue;
            if(i >= j)continue;
            if(e[i] >= 24 && e[j] >= 2)count++;
            if(e[i] >= 2 && e[j] >= 24)count++;
            if(e[i] >= 14 && e[j] >= 4)count++;
            if(e[i] >= 4 && e[j] >= 14)count++;
        }
    }

    rep(i,e.size()){
        if(!e[i])continue;
        if(e[i] >= 74) count++;
    }

    cout << count << endl;
    return 0;
}