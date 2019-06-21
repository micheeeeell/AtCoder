#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#define rep(i,x) for(int i = 0; i < x; i++)
typedef long long ll;
using namespace std;

int main(){
    int h,w; cin >> h >> w;   
    vector<string> s(h);
    rep(i,h){
        cin >> s.at(i);
    }
    vector<vector<int>> l(h, vector<int>(w,0));
    vector<vector<int>> r(h, vector<int>(w,0));
    vector<vector<int>> d(h, vector<int>(w,0));
    vector<vector<int>> u(h, vector<int>(w,0));
    rep(i,h){
        rep(j,w){
            if(s[i][j] == '.'){
                if(i == 0) u[i][j] = 1;
                else u[i][j] = u[i-1][j] + 1;
                if( j == 0) l[i][j] = 1;
                else l[i][j] = l[i][j-1] + 1;
            }
            else{
                l[i][j] = 0; 
                r[i][j] = 0;
                u[i][j] = 0;
                d[i][j] = 0;
            }
        }
    
    }

    for(int i = h-1; i >= 0;i--){
        for(int j = w-1; j >= 0;j--){
            if(s[i][j] == '.'){
                if(i == h-1) d[i][j] = 1;
                else  d[i][j] = d[i+1][j] + 1;
                if( j == w-1) r[i][j] = 1;
                else r[i][j] = r[i][j+1] + 1;
            }
        }
    }

    vector<int> ans;
    rep(i,h){
        rep(j,w){
            ans.push_back(l[i][j] + r[i][j] + d[i][j] + u[i][j] -3);
            // cout << i << j << l[i][j] << r[i][j] << u[i][j] << d[i][j] <<endl;
        }
    }

    cout << *max_element(ans.begin(), ans.end()) << endl;
}