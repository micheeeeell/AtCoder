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
    int n; cin >> n;
    vector<ld> a(n);
    ld sum = 0;
    rep(i,n){
        cin >> a[i];
        sum += ld(1.0)/a[i];
        // cout << sum << endl;
    }
    ld ans;
    ans = ld(1.0) / sum;
    // cout << fixed << setprecision(13) << ans << endl;
    cout << ans << endl;
    // cout << typeid(ans).name() << endl;
    // cout << typeid(200.0/3.0).name() << endl;
    // cout << typeid(double(200)/double(3)).name() << endl;
    // cout << typeid(float(200)/float(3)).name() << endl;
    return 0;
}