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
    string s;cin >> s;
    reverse(all(s));
    bool ok = true;
    ll pos = 0;
    ll n = s.size();
    while(pos < n){
        string t = s.substr(pos,3);
        // debug(pos);debug(t);
        if(t == "mae"){
            if(s.substr(pos,5) != "maerd"){ok = false;break;}
            else pos += 5;
        }
        else if(t == "rem"){
            if(s.substr(pos, 7) != "remaerd"){ok = false;break;}
            else pos += 7;
        }
        else if(t == "esa"){
            if(s.substr(pos,5) != "esare"){ok = false;break;}
            else pos += 5;
        }
        else if(t == "res"){
            if(s.substr(pos, 6) != "resare"){ok = false;break;}
            else pos += 6;
        }
        else {
            ok = false;
            break;
        }

    }

    cout << ( ok ? "YES" : "NO") << endl;
}