#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(int i = 0; i < x; i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
const ll MOD = 1e9+7;
const int n_max = 1e5+10;

int main(){
    ll n; cin >> n;
    vector<Pll> lr(n);
    // ll min_r, max_l;
    rep(i,n){
        ll l,r;
        cin >> l >> r;
        lr[i] = Pll(l,r);
    }
    auto comp = [](auto const a, auto const b){
        return a.first < b.first || (a.first == b.first && a.second > b.second);
    };
    // sort(lr.begin(), lr.end(),comp);
    sort(lr.begin(), lr.end());

    vector<Pll> down(n), up(n);

    down[0] = lr[0];
    rep(i,n){
        if(!i)continue;
        ll l, r;
        l = max(lr[i].first, down[i-1].first);
        r = min(lr[i].second, down[i-1].second);
        down[i] = Pll(l,r);
    }

    up[n-1] = lr[n-1];
    for(int i = n-2; 0 <= i; --i){
        ll l,r;
        l = max(lr[i].first, up[i+1].first);
        r = min(lr[i].second, up[i+1].second);
        up[i] = Pll(l,r);
    }

    auto cal = [](ll a, ll b){
        if(a <= b)return b-a+1;
        else return ll(0);
    };
    ll ans = 0;
    rep(i,n-1){
        ll temp = 0;
        temp += cal(down[i].first, down[i].second);
        temp += cal(up[i+1].first, up[i+1].second);
        ans = max(ans, temp);
    }
    // 一つだけ別
    rep(i,n){
        if(i == 0 || i == n-1)continue;
        ll temp = 0;
        ll l,r;
        l = max(down[i-1].first, up[i+1].first);
        r = min(down[i-1].second, up[i+1].second);
        temp += cal(l,r);
        temp += cal(lr[i].first, lr[i].second);
        ans = max(ans, temp);
    }

    
   
    cout << ans << endl;
}