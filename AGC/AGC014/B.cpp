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
    ll n,m; cin >> n >> m;
    bool ok = true;
    vector<ll> cnt(n);
    rep(i,m){
        ll a,b; cin >> a >> b;
        a--;b--;
        cnt[a]++;cnt[b]++;
    }
    rep(i,n){
        if(cnt[i]%2)ok = false;
    }
    cout << (ok ? "YES" : "NO") << endl;
    return 0;
}