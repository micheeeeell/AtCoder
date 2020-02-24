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

int main(){
    ll n,k; cin >> n >> k;
    vector<ll> minus, plus;
    ll zero = 0;
    rep(i,n){
        ll a; cin >> a;
        if(a > 0)plus.emplace_back(a);
        else if(a < 0)minus.emplace_back(a);
        else zero++;
    }
    ll mi = minus.size() * plus.size();

    sort(all(minus));
    sort(all(plus));
    
    if(k <= mi){
        ll ok = 0;
        ll ng = -INF;
        auto check = [&](ll x){
            ll cnt = 0;
            for(auto i : minus){
                ll temp = upper_bound(all(plus), x/i) - plus.begin();
                cnt += plus.size() - temp;
            }
            // debug(x);debug(cnt)
            if(cnt >= k)return true;
            else return false;
        };
        while(abs(ok - ng) > 1){
            ll x = (ok + ng) / 2;
            if(check(x))ok = x;
            else ng = x;
        }

        cout << ng << endl;
    }
    else if(k <= mi + zero * (minus.size() + plus.size()) + (zero-1) * zero / 2){
        cout << 0 << endl;
    }
    else{
        k -= mi + zero * (minus.size() + plus.size()) +  + (zero-1) * zero / 2;
        debug(k);
        ll ok = INF;
        ll ng = 0;
        auto check = [&](ll x){
            ll cnt = 0;
            for(auto i : minus){
                ll temp = upper_bound(all(minus), x/i) - minus.begin();
                cnt += minus.size() - temp;
                if(i * i < x)cnt--;
            }
            for(auto i : plus){
                ll temp = upper_bound(all(plus), x/i) - plus.begin();
                cnt += temp;
                if(i * i < x)cnt--;
            }
            cnt /= 2;
            // debug(cnt); debug(x);
            if(cnt >= k)return true;
            else return false;
        };
        while(abs(ok - ng) > 1){
            ll x = (ok + ng) / 2;
            if(check(x))ok = x;
            else ng = x;
        }
        cout << ok << endl;
    }
    
}