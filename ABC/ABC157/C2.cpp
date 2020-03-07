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

int main(){
    bool ok = true;
    ll n,m; cin >> n >> m;
    string str(n, 'a');
    rep(i,m){
        ll s,c; cin >> s >> c;
        s--;
        if(str[s] != 'a' && str[s] != '0' + c){ok = false;break;}
        str[s] = '0' + c;
    }
    if(str[0] == '0' && n != 1)ok = false;
    if(str[0] == 'a'){
        if(n != 1)str[0] = '1';
        else str[0] = '0';
    }
    reps(i,n-1)if(str[i] == 'a')str[i] = '0';

    cout << (ok ? str : "-1") << endl;;
}
