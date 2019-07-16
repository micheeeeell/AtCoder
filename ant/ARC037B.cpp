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
// const ll N = 1e9+7;

const int N = 105,M = 1e5;
ivec uv[M];
int moved[M] = {};
bool ok = true;
int temp[2] = {N,N};
void dfs(int x,int y){
    moved[x] = 1;
    // temp[1] = x;
    rep(i,uv[x].size()){
        if(moved[uv[x][i]] == 0){
            // c++;
            // temp[0] = x;temp[1] = uv[x][i];
            dfs(uv[x][i],x);
        } 
        else if(y == uv[x][i]) {
            // ok = true;
            // return;
            continue;
        }
        else{
            ok = false;
            // return;
        }
    }
    // return;
}

int main(){
    int n,m; cin >> n >> m;   
    rep(i,m){
        int u,v;cin >> u >> v;
        uv[u-1].push_back(v-1);
        uv[v-1].push_back(u-1);
    }
    int count = 0;
    rep(i,n){
        if(moved[i] == 0){
            ok = true;
            // temp[0] = N;temp[1] = N;
            dfs(i,-1);
            if(ok) {
                count++;
                // cout << i << endl;
            }
        }
    }
    cout << count << endl;
    return 0;
}