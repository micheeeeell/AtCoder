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
const ll INF = LLONG_MAX/4;
const ll MOD = 1e9+7;
const int n_max = 1e5+10;


// 0を通る最長経路しか求められないからダメぽ
int main(){
    // cin.tie(0);
    // ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<vector<ll>> dist(2,vector<ll>(n,0));
    auto qwe = [](ll a, ll b){
        cout << "? " << a << " " << b << "\n";
    };
    auto ans = [](ll dist){
        cout << "! " << dist << endl;
    };
    ll max_index = -1, m = 0;
    rep(i,n){
        if(!i)continue;
        qwe(1,i+1);
        cin >> dist[0][i];
        if(m < dist[0][i]){
            max_index = i+1;
            m = dist[0][i];
        }
    }
    rep(i,n){
        if(i+1 == max_index)continue;
        qwe(max_index,i+1);
        cin >> dist[1][i];
    }
    // dist[1][0] = dist[0][1];

    ll ma = 0, ma_2 = 0;
    rep(i,n){
        // if(i == 0 || )continue;
        if(dist[1][i] == dist[0][i] + dist[0][max_index-1])ma = max(ma, dist[0][i]);
        if(dist[0][i] == dist[1][i] + dist[0][max_index-1])ma_2 = max(ma_2, dist[0][i]);
        if(dist[0][max_index-1] == dist[0][i] + dist[1][i])ma_2 = max(ma_2, dist[0][max_index-1]);
    }
    ans(ma + dist[0][max_index-1]);
    return 0;
}
