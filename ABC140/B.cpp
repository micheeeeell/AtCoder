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
    int n; cin >> n;
    vector<ll> a(n), b(n), c(n-1);
    rep(i,n)cin >> a[i];
    rep(i,n)cin >> b[i];
    rep(i,n-1)cin >> c[i];
    ll ans = 0;
    rep(i,n){
      int temp = a[i]-1;
      ans += b[temp];  
    }
    rep(i,n-1){
        // if(i == n-2)
        if(a[i]+1 == a[i+1])ans += c[a[i]-1];
    }
    cout << ans << endl;
    return 0;
}