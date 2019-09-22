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

template<typename T>
ld dis(T x, T y){
    return sqrt(x * x + y * y);
}

int main(){
    int n; cin >> n;
    Pll x_max, x_min, y_max, y_min;
    // cout << x_min.first << x_max.second << endl;
    rep(i,n){
        ll x,y; cin >> x >> y;
        if(x >= 0 && y >= 0){
            x_max.first += x;
            x_max.second += y;
        } 
        if(x <= 0 && y >= 0){
            x_min.first += x;
            x_min.second += y;
        }
        if(x >= 0 && y <= 0){
            y_max.first += x;
            y_max.second += y;
        }
        if(x <= 0 && y <= 0){
            y_min.first += x;
            y_min.second += y;
        }
    }
    ld ans = max(dis(x_max.first, x_max.second), dis(x_min.first, x_min.second));
    ans = max(ans, max(dis(y_max.first, y_max.second), dis(y_min.first, y_min.second)));
    cout << fixed << setprecision(20) << ans << endl;
    return 0;
}