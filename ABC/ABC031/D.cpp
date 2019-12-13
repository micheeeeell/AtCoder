#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define pb push_back
#define eb emplace_back
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
    ll k,n; cin >> k >> n;
    vector<string> v(n), w(n);
    rep(i,n){
        cin >> v[i];
        cin >> w[i];
    }
    auto al = [&](ll x) -> vector<ll>{
        vector<ll> res(10,0);
        int cnt = 0;
        // int b = 3;
        while(0 < x){
            res[cnt] = x%3;
            x /= 3;
            cnt++;
        }
        rep(i,10)res[i]++;
        return res;
    };

    // vector<ll> t = al(31);
    // print(t);
    map<ll,string> m,clear;
    rep(i,pow(3,k)){
        vector<ll> t = al(i);
        bool ok = true;
        rep(j,n){
            int cnt = 0;
            for(auto ii : v[j]){
                int temp = ii - '1';
                cnt += t[temp];
            }
            if(cnt != w[j].size()){ok = false;break;}
            cnt = 0;
            for(auto ii : v[j]){
                int temp = ii - '1';
                string str = w[j].substr(cnt, t[temp]);
                if(m.find(temp) == m.end())m[temp] = str;
                else{
                    if(m[temp] != str){ok = false;break;} 
                }
                cnt += t[temp];
            }
            if(!ok)break;
        }
        if(ok)break;
        m = clear;
    }
    for(auto itr = m.begin(); itr != m.end();itr++){
        cout << (*itr).second << endl;
    }
}