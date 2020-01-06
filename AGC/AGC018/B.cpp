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


template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}
int main(){
    ll n,m; cin >> n >> m;  
    vector<vector<ll>> table(n,vector<ll>(m));
    rep(i,n)rep(j,m){
        cin >> table[i][j];
        table[i][j]--;
    }
    Pll ans = {INF,-1};
    vector<ll> index(n,0), num(m,0);
    const int m_max = 330;
    bitset<m_max> bs(0);
    bs = ~bs;
    // debug(bs);
    rep(i,n){
        num[table[i][0]]++;
    }
    rep(i,m){
        Pll temp = {0,-1};
        rep(j,m)chmax(temp, {num[j],j});
        // // debug(temp.first);debug(temp.second);
        bs[temp.second] = 0;
        num[temp.second] = 0;
        rep(j,n){
            bool is_update = false;
            while(bs[table[j][index[j]]] == 0 && index[j] < m){
                index[j]++;
                is_update = true;
            }
            if(is_update && index[j] < m)num[table[j][index[j]]]++;
            // debug(index[j]);
        }
        chmin(ans, temp);
    }

    cout << ans.first << endl;
}