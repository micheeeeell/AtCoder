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
    ll n; cin >> n;
    string s;cin >> s;
    bool ok = true;
    if(n%2 == 0){
        string t = s.substr(n/2);
        rep(i,n/2){
            if(s[i] != t[i])ok = false;
        }
    }
    else ok = false;
    cout << (ok ? "Yes" : "No") << endl;

}