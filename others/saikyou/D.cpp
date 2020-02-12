#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define pb push_back
#define eb emplace_back
#define debug(x) cerr << #x << ": " << (x) << "\n";
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
const ll INF = numeric_limits<ll>::max()/4;
const int n_max = 510;

vector<vector<ll>> table(n_max, vector<ll>(n_max, 0));
void dfs(vector<ll> elem, ll cl) {
    int sz = elem.size();
    if(sz == 1)return ;
    vector<ll> left(sz/2), right(sz - sz/2);
    auto itr = elem.begin();
    itr += sz/2;
    copy(elem.begin(), itr, left.begin());
    copy(itr, elem.end(), right.begin());
    for(auto l : left){
        for(auto r : right){
            table[l][r] = cl;
            table[r][l] = cl;
        }
    }
    dfs(left, cl + 1);
    dfs(right, cl + 1);
}

int main(){
    ll n; cin >> n;
    vector<ll> vec(n);
    iota(vec.begin(), vec.end(), 0);
    dfs(vec, 1);
    rep(i,n-1){
        for(int j = i+1; j < n; j++)cout << table[i][j] << " ";
        cout << "\n";
    }
}