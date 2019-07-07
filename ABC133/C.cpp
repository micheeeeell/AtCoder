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
const ll M = 2019;

int main(){
    int l,r;cin >> l >> r;
    if(r-l >= 2019){
        cout << 0 << endl;
        return 0;
    }
    int middle = r-l+1;
    r %= M;
    l %= M;
    int ans = N;
    rep(i,middle){
        rep(j,middle){
            if(i >= j)continue;
            int temp = (i+l)*(l+j)%M;
            // cout << temp << endl;
            ans = min(ans,temp);
        }
    }
    cout << ans << endl;
    return 0;
}