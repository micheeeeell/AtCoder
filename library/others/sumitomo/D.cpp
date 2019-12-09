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
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    string s;cin >> s;
    ll res = 0;
    rep(i,10)rep(j,10)rep(k,10){
        ll temp = 1;
        rep(l,n){
            if(s[l]-'0' == i && temp == 1)temp++;
            else if(s[l]-'0' == j && temp == 2)temp++;
            else if(s[l]-'0' == k && temp == 3)temp++;
        }
        if(temp == 4)res++;
    }

    cout << res << endl;

}