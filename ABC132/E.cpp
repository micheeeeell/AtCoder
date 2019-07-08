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
    bool uv[n][n] = {};
    rep(i,m){
        int u,v;cin >> u >> v;
        u--;v--;
        uv[u][v] = true;
    }
    int s,t; cin >> s >> t;
    s--;t--;
    bool uv3[n][n] = {};
    queue<P> que;
    rep(i,n){
        que.push(P(i,0));
        int dis[n] = {};
        // fill(dis,dis + n, N );
        while(que.size()){
            P p = que.front();que.pop();
            int loc = p.first,dis = p.second;
            // cout << "p" << ' ' << p  << ' ' << dis[p] << endl;;
            if(dis == 3){
                uv3[i][loc] = true;
                continue;
            }
            rep(j,n){
                if(uv[loc][j]){
                    if(dis < 4){
                        // dis[j] = dis[p] + 1;
                        // cout << "j" << ' ' << j  << ' ' << dis[j] << endl;;
                        que.push(P(j,dis+1));
                    }
                }
            }
            // for(auto itr = que.begin();itr != que.end();itr++){
            //     cout << *itr << ' ';
            // }cout << endl;
        }

    }
    // rep(i,n)rep(j,n)if(uv3[i][j])cout << "test" << ' ' <<  i  << ' ' << j << endl;
    int moved[n] = {};
    fill(moved,moved + n, N);
    queue<int> que3;
    que3.push(s);
    moved[s] = 0;
    bool ok = false;
    while(que3.size()){
        int p = que3.front();que3.pop();
        if(p == t) {
            ok = true;
            break;
        }
        rep(j,n){
            if(uv3[p][j]){
                if(moved[j] == N){
                    moved[j] = moved[p] + 1;
                    que3.push(j);
                }
            }
        }
    }
    if(ok) cout << moved[t] << endl;
    else cout << -1 << endl;
    
    return 0;
}