#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(int i = 0; i < (int)(x); i++)
#define pb push_back
#define mp make_pair
#define debug(x) cerr << #x << ": " << (x) << "\n";
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
const ll MOD = 1e9+7;
const int n_max = 1e5+10;

int main(){
    int n; cin >> n;
    string s;cin >> s;
    string alp = "";
    rep(i,26)alp += 'A'+i;
    alp += alp;
    // cout << alp << endl;
    string ans = s;
    rep(i,s.size()){
        int temp = s[i]-'A';
        ans[i] = alp[temp+n];
    }
    cout << ans << endl;
}