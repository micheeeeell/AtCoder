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



void dfs(int x,vector<vector<ll>> &graph, vector<ll> &vec, int count = 0){
    vec[x] = count;
    for(auto next : graph[x]){
        if(vec[next] == INT_MAX) dfs(next, graph, vec, count+1);
    }
}

int main(){
    int n; cin >> n;
    vector<vector<ll>> gr(n, vector<ll>());
    vector<ll> rank_f(n, INT_MAX);
    vector<ll> rank_s(n, INT_MAX);
    rep(i,n-1){
        ll a,b; cin >> a >> b;
        a--;b--;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    dfs(0, gr, rank_f);
    dfs(n-1, gr, rank_s);

    ll scnt = 0;
    ll fcnt = 0;
    rep(i,n){
        // if(rank_f[i] == rank_s[i])continue;
        if(rank_f[i] > rank_s[i])scnt++;
        else fcnt++;
    }

    // print(rank_f);
    // print(rank_s);

    cout << (fcnt > scnt ? "Fennec" : "Snuke") << endl;
    return 0;

}