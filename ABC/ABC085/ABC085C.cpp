// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<cmath>
// #include<aldorithm>
typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)

using namespace std;

int main(){
    int n,y;
    cin >> n >> y;
    int m,g,s;
    m = y /10000;
    
    bool ok = true;
    rep(i,m+1){
        g = min(n-i , (y-i*10000)/5000);
        rep(j,g+1){
            s = n-i-j;
            if(i * 10000 + j * 5000 + s * 1000 == y){
                cout << i << " " << j << " " << s <<endl;
                ok = false;
                goto END;
            }
            // cout << i << " " << j << " " << s << endl;
        }
    }
    END:

    if(ok){cout << -1 << " "  << -1 << " " << -1 <<endl;}

    return 0;
}