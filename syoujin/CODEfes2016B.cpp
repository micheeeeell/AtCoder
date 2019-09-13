#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(int i = 0; i < x; i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
const ll MOD = 1e9+7;
const int n_max = 1e5+10;

int main(){
    ld x[3],y[3];
    rep(i,3)cin >> x[i] >> y[i];
    ld dis[3];
    rep(i,3){
        int temp = i;
        int temp2;
        if(i != 2)temp2 = i+1;
        else temp2 = 0;
        dis[i] = sqrt((x[temp]-x[temp2])*(x[temp]-x[temp2]) + (y[temp]-y[temp2])*(y[temp]-y[temp2]));
    }
    ld s = abs((x[0]-x[2])*(y[1]-y[2]) - (x[1]-x[2])*(y[0]-y[2])) * 0.5;
    ld r = (2.0*s)/(dis[0]+dis[1]+dis[2]);
    ld A = max(dis[0],max(dis[1],dis[2]));
    ld res = (r*A)/(2*r + A);

    cout << fixed << setprecision(15) << res << endl;
    return 0;
}