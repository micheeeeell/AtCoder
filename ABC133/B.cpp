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
    int n,d; cin >> n >> d;
    long double xy[n][d];
    rep(i,n){
        rep(j,d){
            cin >> xy[i][j];
        }
    }
    int ans = 0;
    rep(i,n){
        rep(j,n){
            if(i >= j)continue;
            long double sum = 0;
            bool ok = true;
            rep(k,d)sum += (xy[i][k] - xy[j][k]) * (xy[i][k] - xy[j][k]);
            long double sq = sqrtl(sum); 
            // cout << i  << ' ' << j  << ' ' << sq << endl;
            rep(k,sum+1){
                if(k == sq){
                    // cout << i  << ' ' << j << endl;
                    ans++;
                    break;
                }
                if(k  > sq){
                    ok = false;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}