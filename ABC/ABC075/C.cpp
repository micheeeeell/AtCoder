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
const int n_max = 55;

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

bitset<n_max> bs(0);
ll n;
void dfs(vvl &graph, ll pos, ll pre = -1){
    bs[pos] = 1;
    rep(i,n){
        if(graph[pos][i] == 1 && i != pre && bs[i] == 0)dfs(graph, i, pos);
    }
}

int main(){
    ll m; cin >> n >> m;
    vector<vector<ll>> graph(n,vector<ll>(n,0));
    vector<Pll> edge(m);
    rep(i,m) {
        ll a,b;cin >> a >> b;
        a--;b--;
        graph[a][b] = graph[b][a] = 1;
        edge[i] = {a,b};
    }

    // print(graph);
    
    ll ans = 0;
    rep(i,m){
        bs &= 0;
        graph[edge[i].first][edge[i].second] = 0;
        graph[edge[i].second][edge[i].first] = 0;
        dfs(graph, 0);
        // debug(bs);
        if(bs.count() != n)ans++;
        graph[edge[i].first][edge[i].second] = 1;
        graph[edge[i].second][edge[i].first] = 1;
    }
    cout << ans << endl;
}