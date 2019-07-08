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
    int n,m; cin >> n >> m;
    vector<P> ab(m);
    rep(i,m){
        int a,b;cin >> a >> b;
        ab[i] = P(a,b);
    }
    sort(ab.begin(),ab.end());
    vector<P> minmax;
    int count = 0;
    minmax.pb(ab[0]);
    rep(i,m){
        int ta,tb;ta = ab[i].first;tb = ab[i].second;
        int ca = minmax[count].first,cb = minmax[count].second;
        if(ta > ca && ta < cb ) minmax[count].first = ta;
        if(tb < cb && tb > ca) minmax[count].second = tb;
        if(ta >= cb){
            count++;
            minmax.pb(P(ta,tb));
        }
    }
    int ans = minmax.size();
    cout << ans << endl;
    return 0;
}