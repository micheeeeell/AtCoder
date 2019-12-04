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
    ll op = 0, ed = 0;
    rep(i,n){
        if(s[i] == '(')op++;
        else{
            if(op == 0)ed++;
            op = max(0LL,op-1);
        }
    }
    string sop, sed;
    rep(i,ed)sop += "(";
    rep(i,op)sed += ")";
    cout << sop + s + sed << endl;
}