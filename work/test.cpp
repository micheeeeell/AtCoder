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

void swap(int *x, int *y){
    int temp = 0;
    temp = *x;
    *x = *y;
    *y = temp;
    return ;
}

void swapa(int* a, int i, int j){
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
    return ;
}
int main(){
    // UnionFind uf(5);
    // uf.unite(0,1);
    // uf.unite(4,2);
    // rep(i,5){
    //     cout << uf.size(i) << endl;
    // }
    // int x = 10, y = 1;
    // swap(&x, &y);
    // cout << x  << ' ' <<  y << endl;
    // int a[10] = {2,3,4,5,7,4,2,5,1,3};
    // swapa(a,0,9);
    // rep(i,10) cout << a[i] << " "; 
    // cout << endl;
    cout << 114 % 13 << endl;
    return 0;
    
}
