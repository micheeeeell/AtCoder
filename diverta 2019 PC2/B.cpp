#include<bits/stdc++.h>
typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
using namespace std;
int ans = 0;


int main(){
    int n; cin >> n;
    vector<int> x(n),y(n);
    rep(i,n){
        cin >> x[i] >> y[i];
    }
    int ans = n;
    rep(i,n){
        rep(j,n){
            if(i == j)continue;
            else{
                int p = x[i] - x[j];
                int q = y[i] - y[j];
                int cnt = 0;
                rep(ii,n){
                    rep(jj,n){
                        if(x[ii] - x[jj] == p && y[ii] - y[jj] == q){
                            cnt++;
                        }
                    }
                }
                ans = min(ans, n-cnt);
            }
        }
    }
    if(n==1)ans = 1;
    cout << ans << endl;
}