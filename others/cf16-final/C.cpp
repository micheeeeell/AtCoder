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
};

int main(){
    ll n,m; cin >> n >> m;
    bitset<n_max> lang(0);
    vvl graph(n);

    UnionFind uf(m);

    rep(i,n){
        ll k; cin >> k;
        rep(j,k){
            ll l; cin >> l;
            l--;
            graph[i].emplace_back(l);
            lang[l] = 1;
        }
    }

    rep(i,n){
        rep(j,graph[i].size() - 1){
            uf.unite(graph[i][j], graph[i][j+1]);
        }
    }

    bool ok = true;
    ll par = -1;

    rep(i,m){
        if(lang[i]){
            if(par == -1){
                par = uf.root(i);
                continue;
            }
            if(par != uf.root(i)){
                ok = false;
                break;
            }
        }
    }

    cout << (ok ? "YES" : "NO") << endl;
}