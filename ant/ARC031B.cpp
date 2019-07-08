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
const ll N = 1e9+7;
const int h = 10,w = 10;

int sea[h][w];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int moved[h][w] = {};

void dfs(int x, int y){
    moved[x][y] = 1;
    sea[x][y] = 1;
    rep(i,4){
        int nx = x + dx[i],ny = y + dy[i];
        if(moved[nx][ny] == 0 && sea[nx][ny] == 0 && nx >= 0 && ny >= 0 && nx < w && ny < h){
            dfs(nx,ny);
        }
    }
}


int main(){
    bool ok = false;
    int consea[h][w] = {};
    rep(i,h){
        string s;cin >> s;
        rep(j,w){
            if(s[j] == 'o') {
                sea[i][j] = 0;
                consea[i][j] = 0;
                }
            else {
                sea[i][j] = 1;
                consea[i][j] = 1;
            }
        }
    }
    int count = 0;
    rep(i,h){
        rep(j,w){
            rep(k,h){
                rep(l,w) {
                    sea[k][l] = consea[k][l];
                    moved[k][l] = 0;
                }
            }
            count = 0;
            if(sea[i][j] == 1){
                sea[i][j] = 0;
                rep(k,h){
                    rep(l,w){
                        if(sea[k][l] == 0){
                            dfs(k,l);
                            count++;
                        }
                    }
                }
            }
            // cout << count << endl;
            if(count == 1){
                ok = true;
                break;
            }
        }
    }
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
}