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
#define reps(i,x) for(ll i = 1; i < (ll)(x); i++)
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
    vector<ll> a_sum(n+1, 0);
    rep(i,n)a_sum[i+1] = a[i] + a_sum[i];
    ll left = 1, med = 2, right = 3;
    ll ans = INF;
    for(;med < n-1; med++){
        while(left < med - 1 && a_sum[left] < a_sum[med] - a_sum[left]) {
            left++;
        }
        ll l_l, l_r;
        l_l = a_sum[left];
        l_r = a_sum[med] - a_sum[left];
        if(left != 1){
            if(abs(l_l - l_r) > abs(a_sum[left-1] * 2 - a_sum[med])){
                l_l = a_sum[left-1];
                l_r = a_sum[med] - a_sum[left-1];
            }
        }
        while(right < n && a_sum[right] - a_sum[med] < a_sum[n] - a_sum[right]) {
            right++;
        }
        ll r_l, r_r;
        r_l = a_sum[right] - a_sum[med];
        r_r = a_sum[n] - a_sum[right];
        if(right != 1){
            if(abs(r_l - r_r) > abs(a_sum[right-1] * 2 - a_sum[med] - a_sum[n])){
                r_l = a_sum[right-1] - a_sum[med];
                r_r = a_sum[n] - a_sum[right-1];
            }
        }
        if(chmin(ans, max({l_l, l_r, r_l, r_r}) - min({l_l, l_r, r_l, r_r}))){
            // debug(left);debug(med);debug(right);
            // debug(l_l);debug(l_r);debug(r_l);debug(r_r);
        }
    }

    cout << ans << endl;
}