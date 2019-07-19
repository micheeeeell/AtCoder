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
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
const ll N = 1e9+7;
const int n_max = 1e5+10;

struct UnionFind{
private:
    vector<int> par;
    vector<int> rank;

public:
    //n要素で親を初期化、par[x]はxの親を表す
    UnionFind(int n){
        par.resize(n,0);
        rank.resize(n,0);
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
            if(rank[x] == rank[y]) rank[x]++;
        }
    }

    //xとyが同じ集合に属するか否か
    bool same(int x, int y){
        return root(x) == root(y);
    }

};

int main(){
    int n,k,l;cin >> n >> k >> l;
    UnionFind road(n);
    UnionFind train(n);
    UnionFind train_road(n);
    // vvi root(n,vector<int>(n,0));
    rep(i,k){
        int p,q;cin >> p >> q;
        p--;q--;
        road.unite(p,q);
    }
    rep(i,l){
        int r,s;cin >> r >> s;
        r--;s--;
        // if(road.same(r,s))train_road.unite(r,s);
        train.unite(r,s);
    }
    // int root[n] = {};
    // int ans[n] = {};
    // rep(i,n){
    //     int temp = train_road.root(i);
    //     root[temp]++;
    // }
    // rep(i,n){
    //     int temp = train_road.root(i);
    //     ans[i] = root[temp];
    //     cout << ans[i] <<"\n";
    // }
    // int ans[n] = {};
    // rep(i,n){
    //     rep(j,n){
    //         if(road.same(i,j) && train.same(i,j)) ans[i]++;
    //     }
    //     cout << ans[i] << "\n";
    // }
    map<P,int> rtmap;
    rep(i,n){
        rtmap[P(road.root(i),train.root(i))]++;
    }
    rep(i,n){
        cout << rtmap[P(road.root(i),train.root(i))] << "\n";
    }
    return 0;
    

}
