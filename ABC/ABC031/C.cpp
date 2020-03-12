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
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    // [s, e)
    auto calc = [&](int s, int e) -> Pll{
        ll taka = 0, aoki = 0;
        rep(i,e-s){
            if(i & 1)aoki += a[s + i];
            else taka += a[s + i];
        }
        return {taka, aoki};
    };

    ll ans = -INF;
    vector<ll> cal(3);
    rep(i,n){
        vector<ll> temp = {-INF, 1, -INF};
        rep(j,n){
            if(i == j)continue;
            auto p = calc(min(i,j), max(i,j)+1);
            cal[0] = p.second;
            cal[1] = j;
            cal[2] = p.first;
            if(cal[0] > temp[0] || (cal[0] == temp[0] && cal[1] < temp[1])){
                // debug(i);debug(j);debug(cal[0]);debug(temp[1]);
                temp = cal;
            }
        }
        chmax(ans, temp[2]);
        // debug(i);debug(ans);
    }

    cout << ans << endl;
}