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
typedef vector<int> ivec;
const ll N = 1e9+7;

int main(){
    int n,m; cin >> n >> m;
    vector<int> uv[n * 3];
    rep(i,m){
        int u,v;cin >> u >> v;
        u--;v--;
        rep(j,3){
            if(j != 2)uv[u*3+j].pb(v*3+j+1);
            else uv[u*3+j].pb(v*3+0);
        }
    }
    int s,t; cin >> s >> t;
    s--;t--;

    int dis[n*3];
    fill(dis,dis+n*3,N);
    queue<int> que;
    que.push(s*3);
    dis[s*3] = 0;
    bool ok = false;
    while(que.size()){
        int p = que.front();que.pop();
        if(p == t*3){
            ok = true;
            break;
        }
        for(auto j : uv[p]){
            if(dis[j] == N){
                dis[j] = dis[p] + 1;
                que.push(j);
            }
        }
    }
    if(ok) cout << dis[t*3]/3 << endl;
    else cout << -1 << endl;
    return 0;
}