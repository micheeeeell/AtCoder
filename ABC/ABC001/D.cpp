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


int main(){
    ll n; cin >> n;
    vector<ll> time(1500,0);
    rep(i,n){
        string s;cin >> s;
        ll st = (s[0] - '0') * 10 + (s[1] - '0');
        ll sm = (s[2] - '0') * 10 + (s[3] - '0');
        ll et = (s[5] - '0') * 10 + (s[6] - '0');
        ll em = (s[7] - '0') * 10 + (s[8] - '0');
        ll stime = st*60 + sm, etime = et*60 + em;
        stime = (stime/5) * 5;
        etime = ((etime + 5 - 1)/5) * 5;
        time[stime]++;time[etime+1]--;
    }
    rep(i,1499) time[i+1] += time[i];
    vector<Pll> ret;
    bool is_rain = false;
    ll start = -1;
    rep(i,1500){
        if(!is_rain && 0 < time[i]){
            is_rain = true;
            start = i;
        }
        if(is_rain && time[i] == 0){
            is_rain = false;
            ret.emplace_back(start, i-1);
        }
    }
    for(auto i : ret) {
        string r = "";
        vector<ll> res(4);
        res[0] = i.first / 60; res[1] = i.first - res[0]*60;
        res[2] = i.second / 60; res[3] = i.second - res[2]*60;
        rep(i,4){
            if(i == 2)r += "-";
            if(res[i] < 10)r += "0" + to_string(res[i]);
            else r += to_string(res[i]);
        }
        cout << r << "\n";
    }
}