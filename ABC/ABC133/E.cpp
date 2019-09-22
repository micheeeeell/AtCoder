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
    int n,k; cin >> n >> k;
    vector<int> ab[n];
    rep(i,n-1){
        int a,b; cin >> a >> b;
        a--;b--;
        ab[a].pb(b);
        ab[b].pb(a);
    }
    ll prob[n] = {};
    fill(prob,prob+n,N);
    prob[0] = k;
    // rep(i,n){
    //     rep(j,ab[i].size()){
    //         cout << ab[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    queue<ll> que;
    que.push(0);
    while(que.size()){
        ll p = que.front();que.pop();
        ll start = 0;
        if(p == 0) start = k-1;
        else start = k-2;
        for(auto i : ab[p]){
            if(prob[i] == N){
                prob[i] = start;
                start--;
                que.push(i);
            }
        }
    }
    // rep(i,n){
    //     int start = 0;
    //     if(i == 0){
    //         start = k-1;
    //     }
    //     else{
    //         start = k-2;
    //     }
    //     rep(j,ab[i].size()){
    //         if(prob[ab[i][j]] == 0){
    //             prob[ab[i][j]] = start;
    //             start--;
    //         }
    //     }
    // }
    // rep(i,n)cout << i  << ' ' << prob[i] << endl;
    ll ans = 1;
    rep(i,n) {
        ans = (ans * prob[i])%N;
        // cout << i  << ' ' << ans << endl;
    }
    if(ans >= 0)cout << ans%N << endl;
    else cout << 0 << endl;
    return 0;
}