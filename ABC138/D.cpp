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
const int n_max = 2e5+10;


ll ans[n_max] = {};
bool is_moved[n_max] = {};
vector<int> ab[n_max];
void dfs(int x, ll a){
    is_moved[x] = 1;
    ans[x] += a;
    for(auto i : ab[x]){
        if(is_moved[i] == 0){
            dfs(i,ans[x]);
        }
    }
}

int main(){
    int n,q; cin >> n >> q;
    rep(i,n-1){
        int atemp,btemp; cin >> atemp >> btemp;
        atemp--;btemp--;
        ab[atemp].push_back(btemp);
        ab[btemp].push_back(atemp);
    }
    rep(i,q){
        int p,x; cin >> p >> x;
        p--;
        ans[p] += x;
    }
    dfs(0,0);
    rep(i,n){
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}