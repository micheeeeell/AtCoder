#include<bits/stdc++.h>
typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
using namespace std;

int main(){
    int n,x; cin >> n >> x;
    vector<int> l(n);
    rep(i,n){
        cin >> l[i];
    }
    int d[n] = {0};
    int ans = 1;
    for(int i = 1; i < n+1 ;i++){
        d[i] = d[i-1] + l[i-1];
        // cout << d[i] << " " << i << endl;
        if(d[i] > x) {
            break;
        }
        ans = i+1;
    }
    cout << ans << endl;
    return 0;
}