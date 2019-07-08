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
    int n; cin >> n;
    vector<int> t(n);
    rep(i,n) cin >> t[i];
    int len = t.size();
    int temp = 0, ans = 1e9;
    rep(i,(1 << len)){
        int sum1 = 0,sum2 = 0; 
        rep(j,len){
            if(1 & (i >> j)){
                sum1 += t[j];
            }
            else sum2 += t[j];
        }
        temp = max(sum1,sum2);
        ans = min(ans,temp);
    }
    cout << ans << endl;
    return 0;
}
