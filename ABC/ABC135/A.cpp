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
const int n_max = 1e5+10;

int main(){
    ll a,b; cin >> a >> b;
    ld ald = a, bld = b;
    ld ans = (ald + bld) / 2;
    if(ceil(ans) == floor(ans)){
        cout << int(ans) << endl;
    }
    else cout << "IMPOSSIBLE" << endl;
    return 0;
}