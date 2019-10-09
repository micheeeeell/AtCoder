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
    int n,c; cin >> n >> c;
    vector<vector<int>> c_num(3,vector<int>(35,0));
    // map<int, int> d0, d1, d2;
    vector<int> d[c];
    rep(i,c){
        rep(j,c){
            int temp;
            cin >> temp;
            d[i].push_back(temp);
        }
    }
    vector<int> c_mp[n];
    rep(i,n)rep(j,n){
        int temp;cin >> temp;
        temp--;
        c_mp[i].push_back(temp);
        c_num[(i+j)%3][temp]++;
    }

    int res = INT_MAX;
    // c_numの 
    // [0] => i
    // [1] => j
    // [2] => k
    rep(i,c)rep(j,c)rep(k,c){
        if(i == j || j == k || i == k)continue;
        int temp_sum = 0;
        rep(l,c){
            temp_sum += d[l][i] * c_num[0][l];
            temp_sum += d[l][j] * c_num[1][l];
            temp_sum += d[l][k] * c_num[2][l];
        }
        res = min(res, temp_sum);
    }
    cout << res << endl;
    return 0;
}