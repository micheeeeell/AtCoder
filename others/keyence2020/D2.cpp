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
const ll INF = numeric_limits<ll>::max()/4;
const int n_max = 1e5+10;

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

void print() {
    cout << endl;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
    cout << head;
    if (sizeof...(tail) != 0) cout << ' ';
    print(forward<Tail>(tail)...);
}

template<typename T, typename U>
void print(pair<T,U> &p){
    print(p.first, p.second);
}
template <class T>
void print(vector<T> &vec) {
    for (auto& a : vec) {
        print(a);
    }
    cout << endl;
}


int main(){
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> b(n);
    rep(i,n) cin >> b[i];

    ll ans = INF;
    rep(i,(1LL << n)){
        vector<Pll> odd, even;
        rep(j,n){
            if((i >> j) & 1){
                if(j & 1)odd.emplace_back(a[j],j);
                else odd.emplace_back(b[j],j);
            }
            else {
                if(j & 1)even.emplace_back(b[j],j);
                else even.emplace_back(a[j],j);
            }
        }
        if(odd.size() != n/2 && even.size() != (n+2-1)/2)continue;
        sort(all(even));
        sort(all(odd));
        vector<Pll> vec;
        rep(i,even.size()){
            vec.emplace_back(even[i]);
            if(i < odd.size())vec.emplace_back(odd[i]);
        }
        bool ok = true;
        rep(i,n-1)if(vec[i].first > vec[i+1].first){ok = false;continue;}
        if(!ok)continue;

        ll t = 0;
        rep(i,n)rep(j,n){
            if(i >= j)continue;
            if(vec[i].second > vec[j].second)++t;
        }
        // if(chmin(ans,t)){
        //     debug(i);
        //     print(odd);
        //     print(even);
        //     print(vec);
        // }
        chmin(ans,t);
    }

    cout << (ans == INF ? -1 : ans) << endl;
}