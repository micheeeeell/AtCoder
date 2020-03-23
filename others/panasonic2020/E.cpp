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
    string a,b,c; cin >> a >> b >> c;
    auto check = [](string &s, string &t){
        assert(s.size() == t.size());
        ll n = s.size();
        rep(i,n){
            if(s[i] == t[i])continue;
            if(s[i] == '?' || t[i] == '?')continue;
            return false;
        }
        return true;
    };

    auto make = [](string &s, string &t){
        ll n = s.size();
        string ret;
        rep(i,n){
            if(s[i] == t[i])ret += s[i];
            else if(s[i] == '?')ret += t[i];
            else if(t[i] == '?')ret += s[i];
        }
        return ret;
    };

    auto chmin = [](string &s, string t){
        if(s.size() > t.size())s = t;
    };

    
    auto com = [&](const string &s, const string &t){
        string stmp, ttmp;
        // bool ok = false;
        ll n = s.size(), k = t.size();
        string ans = s + t;
        rep(i,n){
            stmp = s.substr(i,min(n-i, k));
            ttmp = t.substr(0,min(n-i, k));
            if(check(stmp, ttmp)){
                if(i + k  <= n){
                    chmin(ans, s.substr(0,i) + make(stmp,ttmp) + s.substr(i+k, n-i-k));
                    // debug(s.substr(0,i));
                    // debug(make(stmp, ttmp));
                    // debug(s.substr(i+k, n-i-k));
                }
                else {
                    chmin(ans, s.substr(0,i) + make(stmp, ttmp) + t.substr(n-i, k-n+i));
                    // debug(s.substr(0,i) + make(stmp, ttmp) + t.substr(n-i, k-n+i));
                }
                // debug(i);
                // debug(stmp);debug(ttmp);debug(ans);
            }
        }
        
        return ans;
    };

    string ans = a + b + c;

    

    chmin(ans, com(com(a,b), c));
    chmin(ans, com(com(b,a), c));
    chmin(ans, com(com(b,c), a));
    chmin(ans, com(com(c,b), a));
    chmin(ans, com(com(c,a), b));
    chmin(ans, com(com(a,c), b));

    debug(ans);
    // debug(com(c,a));
    cout << ans.size() << endl;
}