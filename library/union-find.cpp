#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define rep(i,x) for(int i = 0; i < x; i++)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
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
        
        if(rank[x] < rank[y]){
            swap(x,y);
        }
        
        par[y] = x;
        sz[x] += sz[y];
        if(rank[x] == rank[y]) rank[x]++; 
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
    int n,m; cin >> n >> m;
    UnionFind uf(n);
    rep(i,m){
        int a,b;cin >> a >> b;
        a--;b--;
        uf.unite(a,b);
    }
    set<int> st;
    rep(i,n) st.insert(uf.root(i));
    cout << st.size()-1 << endl;
    return 0;
}