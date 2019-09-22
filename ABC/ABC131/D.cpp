#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#define rep(i,x) for(int i = 0; i < x; i++)
typedef long long ll;
using namespace std;
const ll N = 1e9+7;

int main(){
    ll n; cin >> n;
    vector<pair<ll, ll>> ba(n);
    rep(i,n){
        int a,b; cin >> a >> b;
        ba[i] = make_pair(b,a);
    }
    sort(ba.begin(),ba.end());
    // rep(i,n) cout << ba[i].first << " " << ba[i].second << endl;
    ll time = 0;
    bool ok = true;
    rep(i,n){
        time += ba[i].second;
        if(time > ba[i].first){
            ok = false;
            break;
        }
    }
    if(ok)cout << "Yes" << endl;
    else cout << "No" << endl;

}