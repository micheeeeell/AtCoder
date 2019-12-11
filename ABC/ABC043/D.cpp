#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define pb push_back
#define eb emplace_back
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
const ll INF = LLONG_MAX/4;
const ll MOD = 1e9+7;
const int n_max = 1e5+10;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;cin >> s;
    ll n = s.size();
    Pll res;
    bool ok = false;
    rep(i,n-1){
        if(s[i] == s[i+1]){
            res = Pll(i+1,i+2);
            ok = true;
            break;
        }
    }
    rep(i,n-2){
        if(s[i] == s[i+2]){
            res = Pll(i+1,i+3);
            ok = true;
            break;
        }
    }
    auto print = [&](Pll x){
        cout << x.first << " " << x.second << endl;
    };
    ok ? print(res) : print(Pll(-1,-1));
}