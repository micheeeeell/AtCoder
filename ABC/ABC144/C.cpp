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
    ll n; cin >> n;
    // vector<Pll> xy;
    ll ans = LLONG_MAX;
    rep(i,sqrt(n) + 1){
        if(!i)continue;
        if(n%i == 0){
            // xy.push_back(Pll(i, n/i));
            ans = min(ans, (i + n/i - 2));
        }
    }
    cout << ans << endl;
    return 0;
}