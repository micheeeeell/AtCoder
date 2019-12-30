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

class City {
    public:
    City(){};
    City(ll y, ll p, ll index) : y(y), p(p), index(index) {};
    ll y, p, index;
    bool operator<(City c) {
        return this->y < c.y;
    }
};

int main(){
    ll n,m; cin >> n >> m;
    vector<City> c(m);
    rep(i,m){
        ll p,y; cin >> p >> y;
        c[i] = City(y,p,i);
    }
    sort(all(c));
    vector<ll> num(n,0);
    string s[m];
    auto num2str = [&](ll num){
        string s = to_string(num);
        ll zero = 6 - s.size();
        string ret(zero,'0');
        return ret + s;
    };
    rep(i,m){
        num[c[i].p-1]++;
        ll ind = num[c[i].p-1];
        s[c[i].index] = num2str(c[i].p) + num2str(ind);
    }
    rep(i,m)cout << s[i] << "\n";
}