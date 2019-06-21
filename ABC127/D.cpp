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
    vector<ll> a(n);
    rep(i,n) scanf("%llu",&a[i]);
    vector<ll> bc[m];
    rep(i,m) {
        ll t1,t2;
        scanf("%llu%llu",&t1,&t2);
        bc[i].push_back(t1);bc[i].push_back(t2);
    }

    sort(a.begin(),a.end());
    rep(i,m){
        rep(j,bc[i][0]){
            if(a[j] < bc[i][1]) a[j] = bc[i][1];
            else break;
        }
        sort(a.begin(),a.end());
    }
    ll ans = 0;
    for(auto i : a){
        ans += i; 
        // cout << i << endl;
    }
    cout << ans << endl;
}