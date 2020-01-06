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

ld f(ld x, ld p){
    return x + p * pow(0.5, x / 1.5);
}
/*
int main(){
    ld p;cin >> p;

    ld lb,t1,t2,ub;
    lb = 0;ub = p;
    rep(i,200){
        t1 = (2.0 * lb + ub) / 3.0;
        t2 = (lb + 2.0 * ub) / 3.0;

        if(f(t1,p) <= f(t2,p)) ub = t2;
        else lb = t1;
    }

    cout << fixed << setprecision(10) << f(lb,p) << endl;
    return 0;
}
*/

int main(){
    ld p; cin >> p;

    ld a = pow(2.0, 1.0 / 1.5);
    ld x = (log(p) + log(log(a))) / log(a);

    cout << fixed << setprecision(10) << (x > 0 ? f(x, p) : f(0, p)) << endl;
}