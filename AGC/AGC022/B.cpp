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
    ll n; cin >> n;
    ll n2 = n;
    vector<ll> ans;
    if(n == 3)ans = {2,5,63};
    if(n == 4)ans = {2,5,20,63};
    if(n > 4) {
        ans.emplace_back(2);
        ans.emplace_back(4);
        ans.emplace_back(6);
        n -= 3;
        ll tmp = 3;
        while((tmp + 6) <= 30000 && 1 < n){
            ans.emplace_back(tmp);
            ans.emplace_back(tmp + 6);
            n -= 2;
            tmp += 12;
        }
        tmp = 8;
        while(tmp+4 <= 30000 && n > 2){
            ans.emplace_back(tmp);
            ans.emplace_back(tmp+2);
            ans.emplace_back(tmp+4);
            tmp += 6;
            n -= 3;
        }
        
        if(n == 2){
            ans.emplace_back(tmp);
            ans.emplace_back(tmp + 2);
        }
        if(n == 1){
            ans.emplace_back(tmp + 4);
        }
    }
    debug(ans.size());
    assert(ans.size() == n2);
    for(auto i : ans)cout << i << " ";
    cout << endl;
}