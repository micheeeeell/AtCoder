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

template<class T, class U>
void print(pair<T,U> p){
    cout << p.first << " " << p.second << "\n";
}

int main(){
    string s;cin >> s;
    ll n = s.size();
    if(s[n-1] == '1' || s[0] == '0'){
        cout << -1 << endl;
        return 0;
    }
    bool ok = true;
    vector<Pll> ans(n-1);
    queue<ll> q;
    ll cnt = 0;
    rep(i,n/2){
        if(s[i] != s[n-i-2]){ok = false;break;}
        if(s[i] == '0')q.push(i+1);
        else{
            while(q.size()){
                ll t = q.front();q.pop();
                ans[cnt] = {i+1,t};
                cnt++;
            }
            q.push(i+1);
        }
    }
    while(q.size()){
        ll t = q.front();q.pop();
        ans[cnt] = {n/2+1,t};
        cnt++;
    }
    for(int i = n/2 + 2; i <= n; i++){
        ans[cnt] = {n/2+1, i};
        cnt++;
    }
    if(ok){
        rep(i,n-1)print(ans[i]);
    }
    else{print(-1);}
}