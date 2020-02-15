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
    ll n,q; cin >> n >> q;
    string s;cin >> s;
    string que, lr;
    rep(i,q){
        string a;cin >> a;
        string l;cin >> l;
        que += a; lr += l;
    }
    auto right = [&](int id){
            if(id >= n)return true;
            if(id < 0)return false;
        rep(i,q){
            if(s[id] == que[i]){
                if(lr[i] == 'R')id++;
                else id--;
            }
            if(id >= n)return true;
            if(id < 0)return false;
        }
        return false;
    };
    auto left = [&](int id){
            if(id >= n)return false;
            if(id < 0)return true;
        rep(i,q){
            if(s[id] == que[i]){
                if(lr[i] == 'R')id++;
                else id--;
            }
            if(id >= n)return false;
            if(id < 0)return true;
        }
        return false;
    };

    ll l = n, r = -1;
    ll ok = -1;
    while(abs(l - ok) > 1){
        ll id = (l + ok) / 2;
        if(left(id))ok = id;
        else l = id;
    }
    ok = n;
    while(abs(ok - r) > 1){
        ll id = (r + ok)/2;
        if(right(id))ok = id;
        else r = id;
    }

    debug(l);debug(r);
    cout << r - l + 1 << endl;

}