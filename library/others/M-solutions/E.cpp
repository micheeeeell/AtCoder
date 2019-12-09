#include<bits/stdc++.h>
typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
using namespace std;


int main(){
    int q;scanf("%d",&q);
    vector<ll> x(q);
    vector<ll> d(q);
    vector<ll> n(q);
    ll N = 1000003;
    rep(i,q){
        ll xt,dt,nt;
        scanf("%lld%lld%lld",&xt,&dt,&nt);
        x[i]=xt;
        d[i]=dt;
        n[i]=nt;
    }
    vector<vector<ll> > an(q, vector<ll>(n,0));
    rep(i,q){
        
    }
    
}
