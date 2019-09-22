#include<bits/stdc++.h>
typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
using namespace std;

int main(){
    float w,h,x,y;
    cin >> w >> h >> x >> y;
    int ans;
    if(w == x*2.0 && h == y*2.0) ans = 1;
    else ans = 0;
    cout << w/2.0*h << " " << ans << endl;

}