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
    ll n,m; cin >> n >> m;
    vector<int> p(n);
    rep(i, n) cin >> p[i];
    ll ans = 0;
    ll temp[4] = {};
    sort(p.begin(),p.end());
    ivec pkl(n*n+n);
    rep(i,n) pkl[i] = p[i];
    rep(i,n){
        rep(j,n){
            pkl[n+j+(i*n)] = p[i] + p[j];
        }
    }
    sort(pkl.begin(),pkl.end());
    for(auto i : p){
        temp[0] = i;
        for(auto j: p){
            temp[1] = i+j;
            ll lkitr = upper_bound(pkl.begin(),pkl.end(),m-i-j) - pkl.begin() -1;
            if(lkitr != -1){
                ll lk = pkl[lkitr];
                temp[2] = i+j+lk;
            }
            // temp[2] = i+j+k;
            // ll litr = upper_bound(p.begin(),p.end(),m-i-j-k) - p.begin() - 1;
            // if(litr != -1){
            //     ll l = p[litr];
            //     temp[3] = i+j+k+l;
            //     // cout <<  i << ' ' <<  j << ' ' <<  k << ' ' << l << ' ' << endl;
            // }
            rep(a,3) if(temp[a] <= m) ans = max(ans,temp[a]);
        }
    }
    cout << ans << endl;
}