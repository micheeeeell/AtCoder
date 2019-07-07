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

int main(){
    int n; cin >> n;
    int damu[n];
    rep(i,n) cin >> damu[i];
    ll sum = 0;
    rep(i,n)sum += damu[i];
    // sum /= 2;
    int n2 = n/2;
    ll sum2 = 0;
    rep(i,n2){
        sum2 += damu[2*i]*2;
    }
    int yama[n];
    yama[n-1] = sum - sum2;
    yama[0] = damu[n-1]*2-yama[n-1];
    rep(i,n-1){
        if(i == 0)continue;
        yama[i] = damu[i-1]*2-yama[i-1];
    }
    // for(int i = n-2;i >= 0;i--){
    //     yama[i] = damu[i]
    // }

    rep(i,n)cout << yama[i] << " ";
    cout << endl;
    return 0; 

}