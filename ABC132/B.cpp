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
    int p[n];
    rep(i,n) cin >> p[i];
    int ans =  0;
    rep(i,n){
        bool ok = false;
        if(i > 0 && i < n-1){
            if(p[i] < p[i-1] && p[i] > p[i+1]) ok = true;
            else if(p[i] > p[i-1] && p[i] < p[i+1]) ok = true;
        }
        if(ok) ans++;

    }
    cout << ans << endl;
    return 0;
}