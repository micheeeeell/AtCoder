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

ll solve(string &a, string &b){
    // a = to_string(al);b = to_string(bl);
    auto fb = [&](string s){
        ll n = s.size();
        // dp[i][small][is_forbidden]
        vvvl dp(n+1,vvl(2,vl(2,0)));
        dp[0][0][0] = 1;
        rep(i,n){
            rep(small,2){
                if(!small){
                    ll t = s[i] - '0';
                    rep(j,t){
                        if(j != 4 && j != 9)dp[i+1][1][0] += dp[i][small][0];
                        else dp[i+1][1][1] += dp[i][small][0];
                        dp[i+1][1][1] += dp[i][small][1];
                    }
                    if(t != 4 && t != 9 && dp[i][small][0])dp[i+1][small][0] = dp[i][small][0];
                    else dp[i+1][small][1] = dp[i][small][0] + dp[i][small][1];
                }
                else{
                    rep(j,10){
                        if(j != 4 && j != 9)dp[i+1][1][0] += dp[i][small][0];
                        else dp[i+1][1][1] += dp[i][small][0];
                        dp[i+1][1][1] += dp[i][small][1];
                    }
                }
            }
        }
        return dp[n][0][1] + dp[n][1][1];
    };
    return (fb(b) - fb(a));
}

template<class T>
ll guchoku(T &a, T &b){
    auto one = [&](ll x){
        return x - (x/10)*10;
    };
    ll ret = 0;
    for(ll i = a;i <= b;i++){
        ll temp = i;
        while(0 < temp){
            if(one(temp) == 4 || one(temp) == 9){ret++;break;}
            temp /= 10;
        }
    }
    return ret;
}

int main(){
    ll a, b;
    random_device rnd;
    ll m = 100000;
    rep(i,100){
        a = rnd() % m;
        b = rnd() % m;
        if(a > b)swap(a,b);
        string as, bs;as = to_string(a-1); bs = to_string(b);
        if(guchoku(a,b) != solve(as,bs)){
            debug(a);
            debug(b);
            debug(guchoku(a,b));
            debug(solve(as,bs));
            break;
        }
    }
}