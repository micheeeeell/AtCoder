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
const int n_max = 1e5+10;

int main(){
    ll n,q; cin >> n >> q;
    string s(n,'N');
    string t[n];
    rep(i,n)t[i] = s;
    rep(i,q){
        ll p; cin >> p;
        if(p == 1){
            ll a,b; cin >> a >> b;
            a--;b--;
            t[a][b] = 'Y';
        }
        else if(p == 2){
            ll a; cin >> a;
            a--;
            rep(i,n)if(t[i][a] == 'Y')t[a][i] = 'Y';
        }
        else{
            ll a; cin >> a;
            a--;
            vector<ll> vec;
            rep(i,n){
                if(t[a][i] == 'Y'){
                    rep(j,n)if(j != a && t[i][j] == 'Y'){
                        vec.emplace_back(j);
                    }
                }
            }
            for(auto i : vec)t[a][i] = 'Y';
        }
    }
    rep(i,n)cout << t[i] << "\n";
}