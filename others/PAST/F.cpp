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

int main(){
    string s;cin >> s;
    vector<string> v;
    string t = "";
    // cout << 'A' - 'a';
    ll n = s.size();
    auto a2A = [](char s) -> char{
        s += 'A' - 'a';
        return s;
    };
    auto A2a = [](char s) -> char{
        s += 'a' - 'A';
        return s;
    };
    // debug(a2A('d'));
    // debug(A2a('D'));
    rep(i,n){
        if(s[i] - 'Z' <= 0){
            if(t.size()){
                t += A2a(s[i]);
                v.emplace_back(t);
                t = "";
            }
            else{
                t += A2a(s[i]);
            }
        }
        else t += s[i];
        // debug(i);
        // debug(t);
        // debug(t.size());
    }
    if(t.size())v.emplace_back(t);
    sort(all(v));
    rep(i,v.size()){
        v[i][0] = a2A(v[i][0]);
        v[i][v[i].size()-1] = a2A(v[i][v[i].size()-1]);
    }
    string ans = "";
    for(auto str : v)ans += str;
    cout << ans << endl;
}