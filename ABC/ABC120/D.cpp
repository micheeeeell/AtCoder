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


struct UnionFind{
private:
    vector<ll> par;
    vector<ll> rank;
    vector<ll> sz;

public:
    //n要素で親を初期化、par[x]はxの親を表す
    UnionFind(ll n){
        par.resize(n,0);
        rank.resize(n,0);
        sz.resize(n,1);
        rep(i,n){
            par[i] = i;
        }
    }

    //木の根を求める
    ll root(ll x){
        if(par[x] == x) return x;
        else return par[x] = root(par[x]);
    }

    //xとyの属する集合を併合
    void unite(ll x, ll y){
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
    bool same(ll x, ll y){
        return root(x) == root(y);
    }

    //xが属する集合のサイズを返す
    ll size(ll x){
        return sz[root(x)];
    }
};


int main(){
    ll n,m; cin >> n >> m;
    vector<P> bridge(m);
    rep(i,m){
        ll a,b; cin >> a >> b;
        a--;b--;
        bridge[i] = P(a,b);
    }
    UnionFind uf(n);
    ll ans = n * (n-1) / 2;
    vector<ll> ans_v;
    for(ll i = m-1;0 <= i;i--){
        ans_v.push_back(ans);
        ll a = bridge[i].first, b = bridge[i].second;
        if(!uf.same(a,b))ans -= (uf.size(a) * uf.size(b));
        uf.unite(a,b);
    }
    while(ans_v.size()){
        ll temp = ans_v.back();ans_v.pop_back();
        cout << temp << "\n";
    }
    return 0;
}
