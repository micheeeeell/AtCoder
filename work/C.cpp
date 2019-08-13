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
    string s[n];
    rep(i,n) cin >> s[i];
    vector<int> a[n];
    ll ans = 0;
    unordered_map<string, ll> ump;
    rep(i,n){
        sort(s[i].begin(), s[i].end());
        if(ump[s[i]] == 0){
            ump[s[i]] = 1;
        }
        else{
            ans += ump[s[i]];
            ump[s[i]]++;
        }
    }
    cout << ans << endl;
    // rep(i, n) cout << s[i] << " ";
    // cout << endl;
    return 0;

}