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
    ll t; cin >> t;
    ll a,b,tmp;
    rep(i,t){
        string n; cin >> n;

        string as, bs;
        rep(j,n.size()){
            tmp = n[j] - '0';
            a = tmp / 2;
            b = tmp - a;
            if(a == 4 || b == 4){
                a--;b++;
            }
            as += '0' + a;
            bs += '0' + b;
        }

        cout << "Case #" << i + 1 << ": " << as << " " << bs << "\n";
    }
}