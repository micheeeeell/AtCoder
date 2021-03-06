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
    ll h,w; cin >> h >> w;
    vvl c(10,vector<ll>(10,0));
    rep(i,10)rep(j,10){
        cin >> c[i][j];
    }

    // ワーシャルフロイド
    rep(k,10){
        rep(i,10){
            rep(j,10){
                c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
            }
        }
    }
    vvl a(h,vl(w));
    rep(i,h)rep(j,w){
        cin >> a[i][j];
    }
    ll res = 0;
    rep(i,h)rep(j,w){
        if(a[i][j] == -1)continue;
        else res += c[a[i][j]][1];
    }
    cout << res << endl;
}