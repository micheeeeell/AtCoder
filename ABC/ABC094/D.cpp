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
    vector<ll> a(n);
    ll max_a = 0;
    rep(i,n){
        cin >> a[i];
        max_a = max(max_a, a[i]);
    }

    unordered_map<ll,ll> ump;
    rep(i,n){
        ump.emplace(a[i], min(max_a - a[i], a[i]));
    }
    auto itr = max_element(ump.begin(), ump.end(),
    [&](const auto &a, const auto &b) -> bool{
        return a.second < b.second;
    });
    // sort(ump.begin(), ump.end());
    cout << max_a << " " << (*itr).first << endl;
    return 0;
}