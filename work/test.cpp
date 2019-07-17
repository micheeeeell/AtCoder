#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#define rep(i,x) for(int i = 0; i < x; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> ivec;
const ll N = 1e9+7;

int main(){
    vector<int> a = {1,2,3,4,5,6};
    
    // for(auto i:a)cout << (i ^ 6) << endl;
    auto ed = a.end();
    ed--;
    cout << *ed << endl;
    return 0;
}