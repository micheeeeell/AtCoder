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

void clear(queue<P> &q){
    queue<P> empty;
    swap(q,empty);
}


int main(){
    int h,w; cin >> h >> w;
    string s[h];
    rep(i,h) cin >> s[i];
    int isblack[h][w] = {};
    int count[h][w] = {};
    // rep(i,h)rep(j,w) count[i][j] = N;
    // なんかREになる、明日の俺がんばれ
    queue<P> que;
    rep(i,h)rep(j,w){
        if(s[i][j] == '#'){
            count[i][j] = 0;
            isblack[i][j] = 1;
            que.push(P(i,j));
        }
    }
    while(que.size()){
        P p = que.front();que.pop();
        int tx = p.first, ty = p.second;
        rep(i,4){
            int nx = tx + dx[i], ny = ty + dy[i];
            if(isblack[nx][ny] == 0 && nx < h && 0 <= nx && ny < w && 0 <= ny){
                que.push(P(nx,ny));
                isblack[nx][ny] = 1;
                count[nx][ny] = count[tx][ty] + 1;
            }
        }
        // rep(i,h){
        //     rep(j,w){
        //         cout << count[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
    }
    int ans  = 0;
    rep(i,h)rep(j,w) ans = max(ans,count[i][j]);
    cout << ans << endl;
    // 以下TLE実装
    // int moved[h][w];
    // // int count[h][w];
    // rep(i,h)rep(j,w) {
    //     moved[i][j] = N;
    //     // count[i][j] = N;
    // }
    // vector<P> start;
    // rep(i,h)rep(j,w) if(s[i][j] == '#') {
    //     moved[i][j] = 0;
    //     start.pb(P(i,j));
    // }

    // int ans = 0;
    // queue<P> que;
    
    // for(auto i : start){
    //     que.push(i);
    //     // count[i][j] = 0;
    //     int count[h][w] = {};
    //     while(que.size()){
    //         P p = que.front();que.pop();
    //         int tx = p.first, ty = p.second;
    //         rep(k,4){
    //             int nx = tx + dx[k], ny = ty + dy[k];
    //             if(nx < h && 0 <= nx && ny < w && 0 <= ny && count[nx][ny] == 0 && (count[tx][ty]+1) <= moved[nx][ny]){
    //                 count[nx][ny] = count[tx][ty] + 1;
    //                 moved[nx][ny] = count[tx][ty] + 1;
    //                 que.push(P(nx,ny));
    //                 // tans = max(tans,count[nx][ny]);
    //                 // cout << nx << ' ' << ny << endl;
    //             }
    //         }
    //     }
    //     clear(que);
    // }

    // rep(i,h)rep(j,w) ans = max(ans,moved[i][j]);

    // cout << ans << endl;
}