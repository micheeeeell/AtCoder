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
    vector<ll> b(n-1);
    rep(i,n-1)cin >> b[i];
    vector<ll> a(n,0);
    ll ans = 0;
    rep(i,n-1){
        if(i == 0){
            a[i] = b[i];
            ans += a[i];
            continue;
        }
        a[i] = min(b[i-1],b[i]);
        // cout << "i=" << i << " " << a[i] << endl;
        ans += a[i];
    }
    a[n-1] = b[n-2];
    ans += a[n-1];
    // rep(i,n)cout << a[i] << " ";
    // cout << endl;
    cout << ans << endl;
    return 0;
}