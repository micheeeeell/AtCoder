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



template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

int main(){
    ll n; cin >> n;
    vector<ll> a(3), b(3);
    rep(i,3)cin >> a[i];
    rep(i,3)cin >> b[i];

    auto AtoB = [&](ll num, ll id){
        ll res = num / a[id];
        res *= b[id];
        return res;
    };
    auto BtoA = [&](ll num, ll id){
        return (num / b[id]) * a[id];
    };
    ll ans = 0;
    rep(i,n+1){
        rep(j,n-i+1){
            ll k = n - i - j;
            rep(bit, 8){
                ll temp = 0;
                rep(ii,3){
                    ll num;
                    if(ii == 0)num = i;
                    else if(ii == 1)num = j;
                    else num = k;
                    if((bit >> ii) & 1)temp += AtoB(num, ii);
                    else temp += BtoA(num, ii);
                }
                chmax(ans, temp);
            }
        }
    }

    cout << ans << endl;
    }