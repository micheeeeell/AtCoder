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
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    bool ok = true;
    for(int i = n-1;i > 0; i--){
        if(h[i] <= h[i-1] - 2){
            ok = false;
            break;
        }
        else if(h[i] == h[i-1] - 1){
            h[i-1]--;
        }
    }
    if(ok)cout << "Yes" << endl;
    else cout << "No" << endl;
    // rep(i,n)cout << h[i] << " ";
    return 0;
}