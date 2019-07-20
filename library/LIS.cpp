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
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
const ll N = 1e9+7;
const int n_max = 1e5+10;



const int INF = INT_MAX;
int dp[n_max] = {};

//狭義のLIS
void N_LIS(vector<int> a){
    fill(dp, dp+n_max, INF);
    int n = a.size();
    rep(i,n){
        *lower_bound(dp, dp + n_max, a[i]) = a[i];
    }
    cout << lower_bound(dp, dp + n_max, INF) - dp << endl;
    return ;
}
//広義のLIS
void B_LIS(vector<int> a){
    int n = a.size();
    fill(dp, dp+n_max, INF);
    rep(i,n){
        *upper_bound(dp, dp + n_max, a[i]) = a[i];
    }
    cout << lower_bound(dp, dp + n_max, INF) - dp << endl;
    return ;

}

//狭義のLDS
void N_LDS(vector<int> a){
    // fill(dp, dp + n_max, INF);
    int n = a.size();
    vector<int> b;
    for(int i = n-1;0 <= i;i--){
        b.pb(a[i]);
    }
    N_LIS(b);
}

//広義のLDS
void B_LDS(vector<int> a){
    int n = a.size();
    vector<int> b;
    for(int i = n-1;0 <= i;i--){
        b.pb(a[i]);
    }
    B_LIS(b);
}


int main(){
    int n;cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    B_LDS(a);
    return 0;   
}