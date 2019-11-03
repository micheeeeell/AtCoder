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
    // cout << n / (-2) << endl;
    // cout << n % (-2) << endl;
    vector<int> res;
    ll temp = n;
    if(temp == 0)res.push_back(0);
    while(temp != 0){
        ll quot = temp / (-2);
        ll sur = temp % (-2);
        if(sur == -1){
            sur = 1;
            quot += 1;
        }
        res.push_back(sur);
        temp = quot;
        // cout << temp << endl;
    }
    reverse(res.begin(), res.end());
    for(auto i : res)cout << i;
    cout << endl;
    return 0;
}