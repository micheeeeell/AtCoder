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
const ll INF = LLONG_MAX/4;
const ll MOD = 1e9+7;
const int n_max = 1e5+10;

template<typename T>
void chmax(T &a, T &b){if(a < b)a = b;}
template<typename T>
void chmin(T &a, T &b){if(a > b)a = b;}

int main(){
    ll n,W; cin >> n >> W;
    ll v_max = 0, w_max = 0;
    vector<ll> v(n), w(n);
    rep(i,n){
        cin >> v[i] >> w[i];
        chmax(v_max,v[i]);
        chmax(w_max,w[i]);
    }
    ll res = 0;
    if(v_max <= 1e3){
        ll vm = v_max * n;
        vector<vector<ll>> dp(n+1, vector<ll>(vm + 1,INF));
        dp[0][0] = 0;
        rep(i,n){
            rep(j,vm+1){
                dp[i+1][j] = dp[i][j];
                if(v[i] <= j)dp[i+1][j] = min(dp[i+1][j], dp[i][j-v[i]] + w[i]);
            }
        }
        rep(i,vm+1)if(dp[n][i] <= W)res = i;
        cout << res << endl;
        return 0;
    }


    if(w_max <= 1e3){
        ll wm = w_max * n;
        vector<vector<ll>> dp(n+1, vector<ll>(wm + 10,0));
        rep(i,n){
            rep(j,wm+10){
                dp[i+1][j] = dp[i][j];
                if(w[i] <= j)dp[i+1][j] = max(dp[i+1][j], dp[i][j-w[i]] + v[i]);
            }
        }
        rep(i,wm+10)if(i <= W)chmax(res,dp[n][i]);
        cout << res << endl;
        return 0;
    }


    if(n <= 30){
        ll x = n/2;
        vector<Pll> dp(1LL << x), dp2;
        rep(i,(1LL << x)){
            ll v_temp = 0, w_temp = 0;
            rep(j,x){
                if(i & (1LL << j)){
                    v_temp += v[j];
                    w_temp += w[j];
                }
                dp[i] = {w_temp, v_temp};
            }
        }
        sort(all(dp),
        [&](const auto &a, const auto &b){
            return a.first < b.first || (a.first == b.first && a.second > b.second);
        });
        dp2.emplace_back(dp[0]);
        rep(i,(1LL << x)){
            Pll t = dp2.back();
            if(t.second < dp[i].second)dp2.emplace_back(dp[i]);
        }
        ll re = n-x;
        auto check = [&](ll x, ll w_temp){
            bool ret = true;
            if(W - w_temp < dp2[x].first)ret = false;
            return ret;
        };
        rep(i,(1LL << re)){
            ll v_temp = 0, w_temp = 0;
            rep(j,re){
                if(i & (1LL << j)){
                    v_temp += v[x+j];
                    w_temp += w[x+j];
                }
            }
            ll ok = 0;
            ll ng = dp2.size()-1;
            if(!check(ok,w_temp)){
                if(w_temp <= W)chmax(res, v_temp);
                continue;
            }
            if(check(ng,w_temp)){
                res = max(res, v_temp + dp2[ng].second);
                continue;
            }
            while(abs(ok - ng) > 1){
                ll t = (ok+ng)/2;
                if(check(t,w_temp))ok = t;
                else ng = t;
            }
            res = max(res, v_temp + dp2[ok].second);
        }
        cout << res << endl;
        return 0;
    }
}