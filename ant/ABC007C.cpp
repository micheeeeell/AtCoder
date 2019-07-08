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
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};


int main(){
    int r,c; cin >> r >> c;
    int sx,sy; cin >> sy >> sx;
    int gx,gy; cin >> gy >> gx;

    sy--;sx--;gy--;gx--;

    vector<string> s(r);
    rep(i, r) cin >> s[i];
    int moved[r][c];
    rep(i,r)rep(j,c) moved[i][j] = N;
    queue<P> que;
    que.push(P(sy,sx));
    moved[sy][sx] = 0;
    int ans = 0;
    int count = 0;
    while(que.size()){
        P p = que.front();
        que.pop();
        int ty = p.first, tx = p.second;
        // moved[ty][tx] = min(count,moved[ty][tx]);
        if(p.first == gy && p.second == gx){
            ans = moved[gy][gx];
            break;
        }
        else{
            rep(i,4){
                int nx = tx + dx[i], ny = ty + dy[i];
                if(moved[ny][nx] == N && s[ny][nx] == '.' && 0<=nx && nx<c && 0 <= ny && ny < r){
                    moved[ny][nx] = moved[ty][tx] + 1;
                    que.push(P(ny,nx));
                }
            }
        }
    }
    cout << ans << endl;
    return 0;

}