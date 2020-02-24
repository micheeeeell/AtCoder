#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define rrep(i,x) for(ll i = (ll)(x)-1;i <= 0; i--)
#define reps(i,x) for(ll i = 1; i < (ll)(x); i++)
#define rreps(i,x) for(ll i = (ll)(x)-1; i <= 1; i--)
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

ll solve(string s){
    ll ans = 0;
    bool is_high = false;
    rep(i,s.size()){
        ll temp = s[i] - '0';
        if(!is_high){
            if(temp < 5)ans += temp;
            else if(temp == 5){
                if(i == s.size()-1 || s[i+1] - '0' < 5)ans += temp;
                else{
                    is_high = true;
                    ans++;
                    ans += 9 - temp;
                }
            }
            else {
                is_high = true;
                ans++;
                ans += 9 - temp;
            }
        }
        else{
            if(temp < 5){
                ans++;
                ans += temp;
                is_high = false;
            }
            else {
                ans += 9-temp;
            }
        }
    }
    if(is_high)ans++;
    return ans;
}

ll sum_(ll n){
    ll ans = 0;
    while(n){
        ans += n % 10;
        n /= 10;
    }
    return ans;
}
ll guchoku(ll s){
    ll min_ = INF;
    rep(i,1e6){
        if(i < s)continue;
        min_ = min(min_, sum_(i) + sum_(i-s));
    }
    return min_;
}
int main(){

    rep(i,1e6){
        ll sol = solve(to_string(i)), gu = guchoku(i);
        if(sol != gu){
            debug(i);
            debug(sol);
            debug(gu);
            
        }
    }
    
}