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
    vector<vector<ll>> ab(n,vector<ll>());
    map<Pll,ll> mp;
    rep(i,n-1){
        ll a,b; cin >> a >> b;
        a--;b--;
        ab[a].emplace_back(b);
        ab[b].emplace_back(a);
        mp[Pll(a,b)] = i;
    }
    vector<ll> c(n-1,0);
    queue<Pll> que;
    que.push(Pll(-1,0));
    vector<ll> is_move(n,0);
    
    ll pre_color = -1;
    ll max_c = 0;
    // ll pre = -1;
    while(que.size()){
        Pll te = que.front();que.pop();
        ll t = te.second;
        pre_color = te.first;
        is_move[t] = 1;
        max_c = max(max_c,ll(ab[t].size()));
        ll next_color = 1;
        for(auto i : ab[t]){
            if(is_move[i])continue;
            ll temp = mp[Pll(t,i)];
            if(c[temp] == 0){
                if(next_color != pre_color){
                    c[temp] = next_color;
                }
                else{
                    c[temp] = next_color+1;
                    next_color++;
                }
                next_color++;
            }
            que.push(Pll(next_color-1,i));
        }
        
    }

    cout << max_c << endl;
    rep(i,n-1){
        cout << c[i] << "\n";
    }

}