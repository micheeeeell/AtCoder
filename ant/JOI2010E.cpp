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
    int h,w,n; cin >> h >> w >> n;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    int fac[w][h];
    P start[n];
    P goal[n];
    rep(i,h){
        rep(j,w){
            if(s[i][j] == 'S'){
                start[0] = P(j,i);
            }
            else if(s[i][j] != '.' && s[i][j] != 'X'){
                int temp = s[i][j] - '0';
                start[temp] = P(j,i);
                goal[temp-1] = P(j,i); 
            }
        }
    }
    int moved[w][h];
    int ans[n] = {};
    // rep(i,n) cout <<  start[i].first << ' ' << start[i].second << endl;
    // rep(i,n) cout <<  goal[i].first << ' ' << goal[i].second << endl;

    queue<P> que;
    rep(i,n){
        rep(j,h)rep(k,w)moved[k][j] = N;

        que.push(start[i]);
        moved[start[i].first][start[i].second] = 0;
        while(que.size()){
            P p = que.front();que.pop();
            int tx = p.first, ty = p.second;
            if(tx == goal[i].first && ty == goal[i].second){
                ans[i] = moved[tx][ty];
                break;
            }
            rep(j,4){
                int nx = tx + dx[j], ny = ty + dy[j];
                if(nx < w && 0 <= nx && ny < h && 0 <= ny && s[ny][nx] != 'X' && moved[nx][ny] == N){
                    moved[nx][ny] = moved[tx][ty] + 1;
                    que.push(P(nx,ny));
                    // cout << "test" << endl;
                }
            }
        }
        // cout << ans[i] << endl;
        clear(que);
    }
    ll lans = 0;
    rep(i,n){
        lans += ans[i];
    }
    cout << lans << endl;
    return 0;
}