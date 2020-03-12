#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define rrep(i,x) for(ll i = (ll)(x)-1;0 <= i; i--)
#define reps(i,x) for(ll i = 1; i < (ll)(x)+1; i++)
#define rreps(i,x) for(ll i = (ll)(x); 1 <= i; i--)
#define itrrep(itr,vec) for(auto itr = (vec).begin(); itr != (vec).end();itr++)
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
    ll r,c,k; cin >> r >> c >> k;
    ll n; cin >> n;
    set<ll> R;
    map<ll,ll> cnt_r, cnt_c;
    map<Pll, bool> rc;
    rep(i,n){
        ll r,c; cin >> r >> c;
        R.insert(r);
        rc[{r,c}]= 1;
        cnt_r[r]++;
        cnt_c[c]++;
    }
    map<ll,vector<ll>> rmap, cmap;
    // itrrep(itr, cnt_r){
    //     rmap[itr->second].emplace_back(itr->first);
    // }
    itrrep(itr, cnt_c){
        cmap[itr->second].emplace_back(itr->first);
    }

    ll ans = 0;
    
    itrrep(itr,R){
        ll r = *itr;
        if(cmap.find(k-cnt_r[r]) != cmap.end()){
            for(auto c : cmap[k - cnt_r[r]]){
                if(!rc[{r,c}])ans++;
            }
        }
        if(cmap.find(k-cnt_r[r]+1) != cmap.end()){
            for(auto c : cmap[k - cnt_r[r] + 1]){
                if(rc[{r,c}])ans++;
            }
        }

    }
    cout << ans << endl;
}