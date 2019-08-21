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
const ll N = 1e9+7;
const int n_max = 30;

vector<int> buka[n_max];

int salary(int a){
    if(!buka[a].size()) return 1;
    int temp_min = INT_MAX;
    int temp_max = 0;
    for(auto i : buka[a]){
        temp_min = min(temp_min, salary(i));
        temp_max = max(temp_max, salary(i));
    }

    return temp_min + temp_max + 1;
}

int main(){
    int n; cin >> n;
    rep(i,n-1){
        int temp; cin >> temp;
        temp--;
        buka[temp].push_back(i+1);
    }
    cout << salary(0) << endl;
    return 0;
}