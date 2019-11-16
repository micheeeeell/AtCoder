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
    ll n,q; cin >> n >> q;
    string s;cin >> s;
    vector<ll> l(q), r(q);
    rep(i,q){
        cin >> l[i] >> r[i];
    }
    vector<int> sum(n+1,0);
    rep(i,n-1){
        if(s[i] == 'A' && s[i+1] == 'C')sum[i+1]++;
        sum[i+1] += sum[i];
    }

    rep(i,q){
        cout << sum[r[i]-1] - sum[l[i]-1] << "\n";
    }
    return 0;
}