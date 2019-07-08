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
    vector<P> wh(n);
    rep(i,n){
        int w,h; cin >> w >> h;
        wh[i] = P(w,h);
    }
    sort(wh.begin(),wh.end(),greater<P>());
    rep(i,n) cout << wh[i].first  << ' ' << wh[i].second << endl;

}