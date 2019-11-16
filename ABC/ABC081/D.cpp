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

void print(vector<Pll> vec){
    ll n = vec.size();
    rep(i,n){
        cout << vec[i].first << " " << vec[i].second << "\n";
    }
    return ;
}

void print(vector<ll> vec){
    ll n = vec.size();
    rep(i,n)cout << vec[i] << " ";
    cout << "\n";
    return ;
}
int main(){
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
    }
    Pll ma = {0,a[0]};
    rep(i,n)if(abs(a[i]) > abs(ma.second))ma = Pll(i,a[i]);
    vector<Pll> res;
    rep(i,n){
        if(i == ma.first)continue;
        res.emplace_back(Pll(ma.first+1, i+1));
        a[i] += ma.second;
    }
    if(ma.second > 0){
        rep(i,n-1){
            if(a[i] > a[i+1]){
                a[i+1] += a[i];
                res.emplace_back(Pll(i+1, i+2));
            }
        }
    }
    else if(ma.second < 0){
        for(int i = n-1;0 < i; --i){
            if(a[i] < a[i-1]){
                a[i-1] += a[i];
                res.emplace_back(Pll(i+1,i));
            }
        }
    }

    cout << res.size() << endl;
    print(res);
    // print(a);
    return 0;
}