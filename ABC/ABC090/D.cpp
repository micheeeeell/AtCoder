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
    ll n,k; cin >> n >> k;
    ll res = 0;
    for(ll b = max(k,1ll);b <= n; ++b){
        ll p = n/b, r = n%b;
        res += p * max(0ll, b-k);
        res += max(0ll, r-k+1);
        if(k == 0)--res;
    }
    cout << res << endl;
}