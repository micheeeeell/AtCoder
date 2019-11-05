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
    ld a,b; cin >> a >> b;
    ld x; cin >> x;

    ld ans;
    if(a*a*b <= x*2){
        ld y = (2*x/(a*a))-b;
        ans = atan2(a, b-y);
    }
    else{
        ld y = (2*x/(a*b));
        ans = atan2(y, b);
    }
    ld degrees = ans * (180.0/3.141592653589793238463);
    cout << fixed << setprecision(10) << fixed << 90 - degrees << endl;
    return 0;
}