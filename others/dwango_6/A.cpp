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
#define debug(x) cerr << #x << ": " << (x) << "\n";
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
const ll INF = numeric_limits<ll>::max()/4;
const ll MOD = 1e9+7;
const int n_max = 1e5+10;

int main(){
    ll n; cin >> n;
    vector<string> s(n);
    vector<ll> t(n);
    rep(i,n)cin >> s[i] >> t[i];
    ll sum = 0;
    rep(i,n)sum += t[i];
    string x ;
    cin >> x;
    ll ans = 0;
    ll temp = 0;
    rep(i,n){
        if(s[i] == x){
            temp += t[i];
            ans = sum - temp;
            break;
        }
        else temp += t[i];
    }
    cout << ans << endl;
}