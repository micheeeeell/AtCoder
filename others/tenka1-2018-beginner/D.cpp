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

void print(vvl &ans){
    cout << "Yes" << "\n";
    ll k = ans.size();
    cout << k << endl;
    rep(i,k) {
        cout << ans[i].size() << " ";
        for(auto j : ans[i])cout << j << " ";
        cout << "\n";
    }
}

int main(){
    ll n; cin >> n;
    vvl ans;
    
    if(n == 1) {
        ans = {{1}, {1}};
        print(ans);

        return 0;
    }
    ll rt = sqrt(n * 2);
    if(rt * (rt + 1) != n * 2){
        cout << "No" << endl;
        return 0;
    }

    ans = {{1,2}, {2,3}, {3,1}};
    ll cnt = 3;
    while(cnt < n){
        ll ps = cnt + 1;
        vector<ll> add;
        rep(i,ans.size()) {
            ans[i].emplace_back(ps);
            add.emplace_back(ps);
            ps++;
        }
        ans.emplace_back(add);
        cnt = ps-1;
    }

    print(ans);
}