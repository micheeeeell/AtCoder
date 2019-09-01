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
    int n,m; cin >> n >> m;
    int ans[3];
    bool ok = true;
    rep(i,min(n+1,m/4+2)){
        ok = true;
        ans[2] = i;
        ans[0] = 3*n-m+i;
        if(ans[0] < 0){
            ok = false;
            continue;
        }
        ld temp = m- 4*i - 2*ans[0];
        if(temp < 0){
            ok = false;
            continue;
        }
        if(ceil(temp/3.0) != floor(temp/3.0)){
            ok = false;
            continue;
        }
        ans[1] = temp/3;
        break;
    }

    rep(i,3){
        cout << (ok ? ans[i] : -1) << " ";
    }
    cout << endl;
    return 0;
}