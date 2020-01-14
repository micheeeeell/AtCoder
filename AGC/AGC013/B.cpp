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
void print(deque<T> &vec) {
    for (auto& a : vec) {
        cout << a+1;
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
    ll n,m; cin >> n >> m;
    vector<vector<ll>> graph(n);
    rep(i,m) {
        ll a,b;cin >> a >> b;
        a--;b--;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    bitset<n_max> bs(0);
    deque<ll> ans;
    ans.emplace_back(0);
    ans.emplace_back(graph[0][0]);
    bs[0] = 1;
    bs[ans[1]] = 1;
    auto check = [&](){
        ll start = ans.front();
        ll end = ans.back();
        for(auto to : graph[start])if(bs[to] == 0){
            ans.emplace_front(to);
            bs[to] = 1;
            return false;
        }
        for(auto to : graph[end])if(bs[to] == 0){
            ans.emplace_back(to);
            bs[to] = 1;
            return false;
        }
        return true;
    };
    while(!check()){};
    print(ans.size());
    print(ans);
}