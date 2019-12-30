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
const ll MOD = 1e9+7;
const int n_max = 1e5+10;

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

int main(){
    ll n,m; cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(all(a), greater<ll>());
    ll ret = 0;
    vector<ll> sum(n+1,0);
    rep(i,n)sum[i+1] = sum[i] + a[i];
    for(int i = 2; i < min(2*n, m+1) + 1; i++){
        ll temp = i;
        if(i%2){
            temp =i-1;
        }
        // if((1+(temp/2)) * (temp/2) < 2*m)continue;
        debug(i);
        ll sm = 0;
        ll cnt = 2*m;
        ll ind = 0;
        temp = i;
        while(0 < cnt){
            sm += temp*a[ind];
            if(2 < temp)sm += (sum[temp/2] - sum[1]) * 2;
            cnt -= temp * 2 - 2;
            ind++;
            temp = min(temp*2 - 2, (cnt + 2) / 2);
            debug(cnt);
        }
        chmax(ret, sm);
    }
    cout << ret << endl;
}