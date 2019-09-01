#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(int i = 0; i < x; i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
const ll MOD = 1e9+7;
const int n_max = 1e5+10;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int main(){
    int h,w; cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    int sx,sy,gx,gy;
    rep(i,h)rep(j,w){
        if(s[i][j] == 's'){sx = i;sy = j;}
        if(s[i][j] == 'g'){gx = i;gy = j;} 
    }
    bool ok = false;
    vector<vector<int> > is_moved(h,vector<int>(w,0));
    deque<pair<int, P> > que;
    pair<int, P> start = make_pair(0, P(sx,sy));
    is_moved[sx][sy] = 1;
    que.push_front(start);
    while(que.size()){
        pair<int, P> p = que.front();que.pop_front();
        int c = p.first, tx = p.second.first, ty = p.second.second;
        if(tx == gx && ty == gy){ok = true;break;}
        rep(i,4){
            int nx = tx + dx[i], ny = ty + dy[i];
            if(nx < 0 || h <= nx || ny < 0 || w <= ny || is_moved[nx][ny] == 1)continue;
            if(s[nx][ny] == '.' && c <= 2){
                is_moved[nx][ny] = 1;
                pair<int, P> next = make_pair(c, P(nx,ny));
                que.push_front(next);
            }
            else if(s[nx][ny] == '#' && c < 2){
                is_moved[nx][ny] = 1;
                pair<int, P> next = make_pair(c+1, P(nx,ny));
                que.push_back(next);

            }
            else if(s[nx][ny] == 'g' && c <= 2){
                is_moved[nx][ny] = 1;
                pair<int, P> next = make_pair(c, P(nx,ny));
                que.push_front(next);
            }
        }
    }

    cout << (ok ? "YES" : "NO") << endl;
    return 0;
}