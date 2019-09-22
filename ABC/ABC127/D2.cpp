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
    vector<pair<ll, ll>> all(n+m);
    vector<pair<ll, ll>> a(n);
    rep(i,n) {
        ll temp;
        scanf("%llu",&temp);
        a[i] = make_pair(temp,1);
        all[i] = a[i];
    }
    vector<pair<ll, ll>> bc(m);
    rep(i,m) {
        ll t1,t2;
        scanf("%llu%llu",&t1,&t2);
        bc[i] = make_pair(t2,t1);
        all[n+i] = bc[i];
    }

    sort(all.begin(), all.end());
    // rep(i,all.size()) cout << all[i].first << " " << all[i].second << endl;
    vector<ll> ans;
    int i = 0;
    while(ans.size() < n){
        rep(j,all[n+m-i-1].second){
            ans.push_back(all[n+m-i-1].first);
        }
        i++;
    }
    
    ll sum = 0;
    rep(i,n) sum += ans[i];
    cout << sum << endl;
    // sort(a.begin(),a.end());
}