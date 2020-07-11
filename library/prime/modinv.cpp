#include<bits/stdc++.h>
typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
using namespace std;

ll modinv(ll a, ll m){
    ll b = m, u = 1, v = 0;
    while(b){
        ll t = a/b;
        a -= t * b; swap(a,b);
        u -= t * v; swap(u,v);
    }
    u %= m;
    if(u < 0) u += m;
    return u;
}
int main(){
    int a,m;
    cin >> a >> m;
    cout << modinv(a,m) << endl;
}