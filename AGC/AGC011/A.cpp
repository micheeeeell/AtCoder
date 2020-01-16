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
    ll n,c,k; cin >> n >> c >> k;
    vector<ll> t(n);
    rep(i,n) cin >> t[i];
    sort(all(t));
    ll num = 0;
    ll num_t = 0;
    ll time = -1;
    ll time_min = t[0];
    ll ans = 0;
    rep(i,n){
        if(t[i] == time_min + k){
            num_t++;
            while(t[i] >= time_min + k){
                num += min(c,num_t);
                num_t -= min(c,num_t);
                time_min = t[num];
                ++ans;
                // debug(num_t);
            }
        }
        else if(t[i] > time_min + k){
            while(t[i] >= time_min + k){
                num += min(c,num_t);
                num_t -= min(c,num_t);
                time_min = t[num];
                ++ans;
            }
            num_t++;
        }
        else num_t++;
        // debug(i);
        // debug(ans);
    }
    while(num_t > 0){
        num_t -= min(c,num_t);
        ++ans;
    }

    cout << ans << endl;
}