#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#define rep(i,x) for(int i = 0; i < x; i++)
typedef long long ll;
using namespace std;
const ll N = 1e5+5;

int main(){
    int n;cin >> n;
    // vector<pair<ll, ll>> xy(n);
    vector<ll> xy[N];
    vector<ll> yx[N];
    ll xsize[N] = {},ysize[N] = {};
    rep(i,n){
        int x,y;cin >> x >> y;
        xy[x].push_back(y);
        yx[y].push_back(x);
        xsize[x]++;
        ysize[y]++;
        // xy[i] = make_pair(x,y);
    }
    // sort(xy.begin(),xy.end());
    ll count = 0;
    rep(i,N){
        if(xsize[i] != 0){
            ll min = *min_element(xy[i].begin(),xy[i].end());
            if(ysize[min] != 0){
                // ll xsize = xy[i].size()-1, ysize = yx[min].size()-1;
                count += (xsize[i]) * (ysize[min]-1);
                xsize[i] = 0;
                ysize[min] = 0;
            }
            else count -= xsize[i];
            cout << i << " " << xsize[i] << endl;
        }
    }
    cout << count << endl;

}