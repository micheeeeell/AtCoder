#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#define rep(i,x) for(int i = 0; i < x; i++)
typedef long long ll;
using namespace std;
const ll N = 1e9+7;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
const int ma = 600;
int moved[ma][ma] = {};
int intmap[ma][ma] = {};
int gx,gy;

void dfs(int x, int y){
    moved[x][y] = 1;
    // cout <<  x << ' ' << y << endl;
    // if(intmap[x][y] == 2){
    //     return true;
    // }
    rep(i,4){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && ny >= 0 && moved[nx][ny] == 0 && intmap[nx][ny] != 4 && intmap[nx][ny] != 0){
            dfs(nx,ny);
        }
    }
    // return false;
}

int main(){
    int h,w; cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    int sx ,sy;
    rep(i,h){
        rep(j,w){
            if(s[i][j] == 's') {
                intmap[i][j] = 1;
                sx = i;sy = j;
            }
            else if(s[i][j] == 'g'){
                intmap[i][j] = 2;
                gx = i;gy = j;
            }
            else if(s[i][j] == '.'){
                intmap[i][j] = 3;
            }
            else intmap[i][j] = 4;
        }
    }
    // rep(i,h){
    //     rep(j,w){
    //         cout << intmap[i][j];
    //     }
    //     cout << endl;
    // }
    dfs(sx,sy);
    string ans;
    if(moved[gx][gy] == 1) ans = "Yes";
    else ans = "No";
    cout << ans << endl;
    // rep(i,h){
    //     rep(j,w){
    //         cout << moved[i][j];
    //     }
    //     cout << endl;
    // }
}