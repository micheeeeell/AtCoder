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
    vector<ll> vec(26,0);
    rep(i,n){
        string s;cin >> s;
        vec[s[0] - 'A']++;
    }
    string m = "MARCH";
    ll ans = 0;
    for(int i = 0;i < 3;i++){
        for(int j = i+1; j < 4;j++){
            for(int k = j+1; k < 5;k++){
                ans += vec[m[i] - 'A'] * vec[m[j] - 'A'] * vec[m[k] - 'A'];
            }
        }
    }
    cout << ans << endl;
}