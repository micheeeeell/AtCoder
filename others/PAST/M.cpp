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
const int n_max = 1e5+10;

class monster {
    public:
    ll w, m;
    bool sub;
    monster(){} ;
    monster(ll w, ll m, bool sub): w(w), m(m), sub(sub) {};
};

int main(){
    ll n,m; cin >> n >> m;
    vector<monster> mon(n+m);
    rep(i,n){
        ll a,b; cin >> a >> b;
        mon[i] = monster(a,b,0);
    }
    rep(i,m){
        ll c,d; cin >> c >> d;
        mon[n+i] = monster(c,d,1);
    }

    ld ok = 0;
    ld ng = 110000;
    rep(i,100){
        ld x = (ok + ng) / 2.0;
        sort(all(mon),
        [&](const auto &a, const auto &b){
            ld ta = x * a.w;
            ld tb = x * b.w;
            ld na = a.m;
            ld nb = b.m;
            return (na - ta) > (nb - tb);
        });
        ll cnt = 0, cnt_sub = 0, pos = 0;
        ll wei = 0, mag = 0;
        while(cnt < 5){
            if(mon[pos].sub == 1){
                if(cnt_sub){pos++;continue;}
                cnt++;
                cnt_sub++;
                wei += mon[pos].w;
                mag += mon[pos].m;
            }
            else {
                cnt++;
                wei += mon[pos].w;
                mag += mon[pos].m;
            }
            pos++;
        }

        if(ld(mag) / ld(wei) >= x)ok = x;
        else ng = x;
    }

    cout << fixed << setprecision(10);
    cout << ok << endl;

}