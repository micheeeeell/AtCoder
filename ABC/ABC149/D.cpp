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


int main(){
    ll n,k; cin >> n >> k;
    ll r,s,p; cin >> r >> s >> p;
    string t;cin >> t;
    vector<ll> vec(n,0);
    rep(i,n){
        if(t[i] == 'r')vec[i] = p;
        if(t[i] == 's')vec[i] = r;
        if(t[i] == 'p')vec[i] = s;
    }
    bool same = false;
    ll sum = 0;
    rep(i,k){
        for(int j = i; j < n; j += k){
            if(j == i){
                sum += vec[j];
                same = false;
                continue;
            }
            if(t[j] == t[j-k]){
                if(same)sum += vec[j];
                same ^= true;
            }
            else{
                sum += vec[j];
                same = false;
            }
        }
    } 
    // ll sum = 0;
    // rep(i,n)sum += vec[i];
    cout << sum << endl;
    // string str[k];
    // rep(i,k){
    //     for(int j = i; j < n; j += k){
    //         str[i] += t[j];
    //     }
    // }
    // auto point = [&](string str, int index){
    //     ll ret = 0;
    //     if(str[index] == 'p')ret = s;
    //     else if(str[index] == 'r')ret = p;
    //     else ret = r;
    //     return ret;
    // };
    // auto solve = [&](string str){
    //     ll ret = 0;
    //     ll n = str.size();
    //     ll pre = -1;
    //     rep(i,n){
    //         if(!i)ret += point(str, i);
    //         else if(pre != point(str, i))ret += point(str, i);
    //         if(pre == point(str, i))pre = 0;
    //         else pre = point(str, i);
    //     }
    //     return ret;
    // };
    // ll ret = 0;
    // rep(i,k)ret += solve(str[i]);
    // cout << ret << endl;
}