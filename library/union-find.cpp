#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#define rep(i,x) for(int i = 0; i < x; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> ivec;
const ll N = 1e9+7;

int par[N];
int rank[N];

//n要素で親を初期化、par[x]はxの親を表す
void init(int n){
    rep(i,n){
        par[i] = 1;
        rank[i] = 0;
    }
}

//木の根を求める
int find(int x){
    if(par[x] == x) return x;
    else return par[x] = find(par[x]);
}

//xとyの属する集合を併合
void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    else{
        par[y] = x;
        if(rank[x] == rank[y]) rank[x]++;
    }
}

//xとyが同じ集合に属するか否か
bool same(int x, int y){
    return find(x) == find(y);
}
