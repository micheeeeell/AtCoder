#include<bits/stdc++.h>
typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
using namespace std;

int main(){
    int n;scanf("%d",&n);
    vector<int> a(n-1);
    vector<int> b(n-1);
    vector<int> c(n);
    rep(i,n-1){
        int at,bt;
        scanf("%d%d",&at,&bt);
        a[i]=at-1;
        b[i]=bt-1;
    }
    rep(i,n){
        int ct;
        scanf("%d",&ct);
        c[i]=ct;
    }
    pair<int,int> a_count;
    pair<int,int> b_count;
    rep(i,n-1){
        a_count[i] = {count(a.begin(),a.end(),a[i]),i};
        b_count[i] = {count(b.begin(),b.end(),b[i]),i};

    }

    sort(a_count,a_count+n-1);
    sort(b_count,b_count+n-1);
    sort(c.begin(),c.end());
    vector<int> cd(n);
    rep(i,n-1){
        cd
    }

    int ans=0;
    rep(i,n-1){
        ans += min(c[a[i]],c[b[i]]);
    }
    cout << ans << endl;
    rep(i,n){
        cout << c[i] << " ";
    }

}
