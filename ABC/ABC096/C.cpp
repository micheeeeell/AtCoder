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
    ll h,w; cin >> h >> w;
    string s[h];
    rep(i,h)cin >> s[i];
    ll dx[4] = {0,0,1,-1};
    ll dy[4] = {1,-1,0,0};
    bool ok = true;
    rep(i,h)rep(j,w){
        if(s[i][j] == '#'){
            bool temp = false;
            rep(k,4){
                ll nx = i + dx[k];
                ll ny = j + dy[k];
                if(0 <= nx && nx < h && 0 <= ny && ny < w){
                    temp |= s[nx][ny] == '#';
                }
            }
            ok &= temp;
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
}