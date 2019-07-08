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

int d = 11,g,sum,cnt = 10000;
vector<int> p(d),c(d);
vector<pair<bool,int>> pd(d);

int dfs(int i, int k){
    int sum = 0;
    rep(j,i){
        if(pd[j].first == 1) sum += pd[j].second;
    }
    if(sum >= g) cnt = min(cnt,k);
    else{
        int temp = 0;
        rep(j,i){
            if(pd[j].first == 0) temp = max(temp,j);
        }
        if(g-sum < p[temp] * (temp+1) * 100) {
            if((g-sum) % ((temp+1) * 100) != 0)cnt = min(cnt,k + (g-sum) / ((temp+1) * 100)+1);
            else cnt = min(cnt,k + (g-sum) / ((temp+1) * 100));
        }
    }
    // cout << i << ' ' << k << ' ' << cnt << ' ' << endl;
    if(i == d) return cnt;
    
    pd[i].first = 0;
    ll ans1 = dfs(i+1,k);
    pd[i].first = 1;
    ll ans2 = dfs(i+1,k + p[i]);
    return min(ans1, ans2);
    
}

int main(){
    cin >> d >> g;
    rep(i,d){
        cin >> p[i] >> c[i];
        pd[i] = make_pair(0,p[i]*(i+1)*100+c[i]);
    }
    int ans = dfs(0,0);
    cout << ans << endl;
    return 0;
}