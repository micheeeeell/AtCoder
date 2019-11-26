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
    ll a,b,c; cin >> a >> b >> c;
    ll d,e,f; cin >> d >> e >> f;

    pair<ld,pair<ll,ll>> res = make_pair(0,make_pair(a*100,0));

    for(ll x = a;x <= (f/100);x++){
        rep(j,x/a+1){
            ll re = x-j*a;
            if(re%b != 0)continue;
            ll sugar = min(x*e, f - x*100);
            rep(k,sugar/c+1){
                ll re_sug = sugar - k*c;
                re_sug = (re_sug/d)*d;
                ll all_sug = re_sug + k*c;
                if(f < x*100 + all_sug)continue;
                ld con = 100.0*all_sug/(x*100+all_sug);
                if(res.first < con)res = make_pair(con,make_pair(x*100+all_sug,all_sug));
            }
        }
    }

    cout << res.second.first << " " << res.second.second << endl;
}