// #include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<bitset>
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
    ll m,k; cin >> m >> k;
    if(m == 1 && k == 1){cout << -1 << endl;return 0;}
    if((1LL << m) <=  k){cout << -1 << endl;return 0;}
    vector<ll> ret((1LL << (m+1)),0);
    if(k == 0){
        ll cnt = 0;
        for(ll i = (1 << m)-1; 0 <= i; i--){
            ret[cnt] = i;
            cnt++;
        }
        rep(i,(1LL << m)){
            ret[cnt] = i;
            cnt++;
        }
    }
    else{
        vector<Pll> pairs;
        bitset<10000000> bs(0);
        rep(i,(1LL << m)){
            if(bs[i] == 0){
                pairs.emplace_back(Pll(i,i^k));
            }
            bs[i] = 1;bs[i^k] = 1;
        }
        ll cnt = 0, cnt_p = 0;
        while(cnt < (1LL << (m+1))){
            ll a = pairs[cnt_p].first, b = pairs[cnt_p].second;
            ll c = pairs[cnt_p+1].first, d = pairs[cnt_p+1].second;
            cnt_p +=2;
            ret[cnt] = ret[cnt+5] = b;
            ret[cnt+1] = ret[cnt+4] = a;
            ret[cnt+2] = ret[cnt+7] = c;
            ret[cnt+3] = ret[cnt+6] = d;
            cnt += 8;
        }
    }

    print(ret);
}