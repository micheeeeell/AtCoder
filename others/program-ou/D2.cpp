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




int main(){
    int n,m; cin >> n >> m;
    vector<vector<Pll>> graph(n);
    ll INF = INT_MAX;
    vector<ll> dp(n,INF);
    rep(i,m){
        ll l,r; cin >> l >> r;
        ll c; cin >> c;
        l--;r--;
        graph[l].emplace_back(Pll(r,c));
    }
    dp[0] = 0;
    // ll mi = INF;
    bool ok = true;
    priority_queue<Pll, vector<Pll>, greater<Pll> > pq;
    rep(i,n){
        Pll temp = Pll(INF, -1);
        if(pq.size() > 0)temp = pq.top();
        while(temp.second < i && pq.size() > 0){
            pq.pop();
            temp = pq.top();
        }
        // print(i,temp.first,temp.second);
        // print(dp);
        if(i == 0 || temp.second >= i)dp[i] = temp.first;
        else{
            ok = false;
            break;
        }
        if(i == 0)dp[i] = 0;
        for(auto j : graph[i]){
            // dp[j.first] = min(dp[j.first], dp[i] + j.second);
            pq.push(Pll(dp[i] + j.second,j.first));
        }
    }
    // print(dp);
    cout << (ok ? dp[n-1] : -1) << endl;
}