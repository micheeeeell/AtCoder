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

int main(){
    int n,m; cin >> n >> m;
    bool xy[n][n] = {};
    rep(i,m){
        int x,y;
        cin >> x >> y;
        xy[x-1][y-1] = true;
        xy[y-1][x-1] = true;
    }
    rep(i,n) xy[i][i] = true;
    if(m == 0){
        cout << 1 << endl;
        return 0;
    }
    int ans = 0;
    
    rep(i,(1 << n)){
        ivec nei;
        int sum = 0;
        rep(j,n){
            if(1 & (i >> j)){
                nei.push_back(j);
            }
        }
        // rep(j,nei.size()) cout << nei[j] ;
        // cout << endl;
        // if(nei.size() != 0) sum = 1e5;
        // else sum = 0;
        sum = 0;
        bool ok = true;
        for(auto k : nei){
            int ksum = 0;
            for(auto l : nei){
                if(xy[k][l] == false) ok = false;
            }
            // sum = min(sum,ksum);
        }
        if(ok) sum = nei.size();
        ans = max(ans,sum);
        // cout << sum << endl;
        
    }
    // rep(i,n){
    //     rep(j,n){
    //         cout << xy[i][j];
    //     }
    //     cout << endl;
    // }
    cout << ans << endl;
}