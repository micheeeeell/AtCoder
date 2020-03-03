#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define rrep(i,x) for(ll i = (ll)(x)-1;0 <= i; i--)
#define reps(i,x) for(ll i = 1; i < (ll)(x)+1; i++)
#define rreps(i,x) for(ll i = (ll)(x); 1 <= i; i--)
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

struct UnionFind{
private:
    vector<int> par;
    vector<int> rank;
    vector<int> sz;

public:
    //n要素で親を初期化、par[x]はxの親を表す
    UnionFind(int n){
        par.resize(n,0);
        rank.resize(n,0);
        sz.resize(n,1);
        rep(i,n){
            par[i] = i;
        }
    }

    //木の根を求める
    int root(int x){
        if(par[x] == x) return x;
        else return par[x] = root(par[x]);
    }

    //xとyの属する集合を併合
    void unite(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y) return;
        else{
            par[y] = x;
            sz[x] += sz[y];
            if(rank[x] == rank[y]) rank[x]++;
        }
    }

    //xとyが同じ集合に属するか否か
    bool same(int x, int y){
        return root(x) == root(y);
    }

    //xが属する集合のサイズを返す
    int size(int x){
        return sz[root(x)];
    }

    // 集合の数を返す
    int num_of_s(){
        set<int> st;
        rep(i,par.size()) st.insert(root(i));
        return st.size();
    }
};



int main(){
    ll n,m; cin >> n >> m;
    vector<ll> a(n);
    ll sum = 0;
    rep(i,n) {
        cin >> a[i];
        sum += a[i];
    }
    UnionFind uf(n);
    rep(i,m){
        ll x,y; cin >> x >> y;
        uf.unite(x, y);
    }

    ll num = uf.num_of_s();

    if((num - 1) * 2 > n){
        cout << "Impossible" << endl;
        return 0;
    }

    if(num == 1){
        cout << 0 << endl;
        return 0;
    }

    vector<vector<ll>> graph(n);
    rep(i,n){
        graph[uf.root(i)].emplace_back(a[i]);
    }
    vector<ll> rest;
    rep(i,n){
        if(graph[i].size() <= 1)continue;
        sort(all(graph[i]), greater<ll>());
        rep(j,graph[i].size() - 1)rest.emplace_back(graph[i][j]);
    }

    sort(all(rest), greater<ll>());
    rep(i,n - (num - 1) * 2)sum -= rest[i];

    cout << sum << endl;
}