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

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}
int main(){
    ll n,k,q; cin >> n >> k >> q;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll ans = INF;
    rep(i,n){
        vector<ll> temp, temp_sum, clear;
        rep(j,n){
            if(a[j] >= a[i])temp.emplace_back(a[j]);
            else{
                if(temp.size() >= k){
                    sort(all(temp));
                    rep(jj,temp.size() - k + 1)temp_sum.emplace_back(temp[jj]);
                }
                temp = clear;
            }
        }
        // debug(i);debug(temp.size());
        if(temp.size() >= k){
            sort(all(temp));
            rep(jj,temp.size() - k + 1)temp_sum.emplace_back(temp[jj]);
        }
        if(temp_sum.size() >= q){
            sort(all(temp_sum));
            chmin(ans, temp_sum[q-1] - temp_sum[0]);
        }
    }

    cout << ans << endl;
}