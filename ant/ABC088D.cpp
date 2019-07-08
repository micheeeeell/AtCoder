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
    int h,w; cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    int moved[h][w] = {};
    int count = 0;
    rep(i,h)rep(j,w) moved[i][j] = N;
    rep(i,h)rep(j,w) if(s[i][j] == '.')count++;
    queue<P> que;
    que.push(P(0,0));
    moved[0][0] = 0;
    int dis = 0;
    while(que.size()){
        P p = que.front();que.pop();
        int tx = p.first, ty = p.second;
        if(tx == h-1 && ty == w-1){
            dis = moved[tx][ty];
            break;
        }
        rep(i,4){
            int nx = tx + dx[i], ny = ty + dy[i];
            if(nx < h && 0 <= nx && ny < w && 0 <= ny && s[nx][ny] == '.' && moved[nx][ny] == N){
                moved[nx][ny] = moved[tx][ty] + 1;
                que.push(P(nx,ny));
            }
        }
    }
    int ans = 0;
    if(dis){
        ans = count - dis - 1;
    }
    else ans = -1;

    // cout << ans <<  ' ' << count << ' ' << dis << endl;

    cout << ans << endl;
    return 0;

}