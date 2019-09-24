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
        cout << a.first << " " << a.second;
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
    ll n; cin >> n;
    vector<ll> v(n);
    rep(i,n) cin >> v[i];
    unordered_map<ll,ll> mp_odd, mp_even;
    rep(i,n){
        if(i%2){
            mp_odd[v[i]]++;
        }
        else mp_even[v[i]]++;
    }
    auto comp = [](const auto a, const auto b) -> bool{
        return a.second > b.second;
    };
    vector<Pll> even(2),odd(2);
    partial_sort_copy(mp_even.begin(), mp_even.end(),even.begin(),even.end(),comp);
    partial_sort_copy(mp_odd.begin(), mp_odd.end(),odd.begin(),odd.end(),comp);
    // print(even);
    // print(odd);
    ll ans = 0;
    if(even[0].first != odd[0].first){
        ans = n - (even[0].second + odd[0].second);
    }
    else{
        ans = n-max(even[0].second + odd[1].second, even[1].second + odd[0].second);
    }
    cout << ans << endl;
    return 0;
}   