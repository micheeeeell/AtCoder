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
    int n,m; cin >> n >> m;
    int card[n] = {0};
    vector<int> lr[m];
    int mm[2] = {0};
    rep(i,m){
        int t1,t2;
        scanf("%d%d",&t1,&t2);
        lr[i].push_back(t1-1);
        lr[i].push_back(t2-1);
        // cout << lr[i][0] << lr[i][1] << endl;
    }
    // rep(i,m){
    //     for(int j =lr[i].at(0);j < lr[i].at(1)+1;j++){
    //         card[j]++;
    //         // cout << j;
    //     }
    // }
    mm[1] = n;
    rep(i,m){
        if(mm[0] < lr[i][0]) mm[0] = lr[i][0];
        if(mm[1] > lr[i][1]) mm[1] = lr[i][1]; 
        // cout << mm[0] << mm[1] << endl;
    }
    int ans = 0;
    // rep(i,n){
    //     if(card[i] == m) {
    //         ans++;
    //         // cout << i+1 << endl;
    //     }
    // }
    ans = mm[1]-mm[0]+1;
    if(ans < 0) ans = 0;
    cout << ans << endl;
}