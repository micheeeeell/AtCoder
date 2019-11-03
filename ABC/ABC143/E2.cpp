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
    ll n,m,l;cin >> n >> m >> l;
    ll INF = 1e10+10;
    vector<vector<ll>> graph(n,vector<ll>(n,INF));
    rep(i,m){
        ll a,b,c;cin >> a >> b >> c;
        a--;b--;
        graph[a][b] = c;
        graph[b][a] = c;
    }
    ll q; cin >> q;
    vector<P> st(q);
    rep(i,q){
        int s,t; cin >> s >> t;
        s--;t--;
        st[i] = P(s,t);
    }
    // ワーシャルフロイド
    rep(i,n)graph[i][i] = 0;
    rep(k,n){
        rep(i,n){
            rep(j,n){
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[j][k]);
            }
        }
    }

    // print(graph);
    vector<vector<ll>> res(n,vector<ll>(n,INF));
    rep(i,n)rep(j,n){
        if(graph[i][j] <= l)res[i][j] = 1;
    }
    rep(i,n)res[i][i] = 0;
    rep(k,n)rep(i,n)rep(j,n)res[i][j] = min(res[i][j], res[i][k] + res[k][j]);

    rep(i,q){
        cout << (res[st[i].first][st[i].second] == INF ? -1 : res[st[i].first][st[i].second] - 1) << endl;
    }
    return 0;
}