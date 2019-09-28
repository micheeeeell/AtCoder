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
    ll n,m; cin >> n >> m;
    vector<vector<int>> s(m,vector<int>(n,0));
    vector<int> p(m);
    rep(i,m){
        ll k; cin >> k;
        rep(j,k){
            int temp;cin >> temp;
            temp--;
            s[i][temp] = 1;
        }
    }
    rep(i,m)cin >> p[i];
    auto check = [&](ll x, int y) -> bool{
        bool ok = true;
        int count = 0;
        rep(i,n){
            ll temp = x >> i;
            if(s[y][i])if(temp & 1)count++;
        }
        if(count%2 != p[y])ok = false;
        stringstream ss;
        ss << bitset<10>(x);
        string str = ss.str();
        // if(ok)print("ok",str,y);
        return ok;
    };

    ll res = 0;
    rep(i,(1 << n)){
        bool ok = true;
        rep(j,m){
            if(!check(i,j))ok = false;
            // ok = check(i,j);
        }
        if(ok)res++;
    }

    cout << res << endl;
    return 0;
}