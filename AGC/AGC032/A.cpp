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
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> b(n);
    rep(i,n) cin >> b[i];
    #define SZ(x) (int)x.size()
    vector<ll> ans;
    auto remove = [&](auto index){
        auto itr = b.begin();
        itr += index;
        b.erase(itr);
        return ;
    };
    bool ok = true;
    while(SZ(b)){
        bool temp = false;
        for(int i = SZ(b) - 1; 0 <= i; i--){
            if(b[i] == i+1){
                ans.emplace_back(i+1);
                remove(i);
                temp = true;
                break;
            }
        }
        ok &= temp;
        if(!temp)break;
    }

    reverse(all(ans));
    if(ok){
        for(auto i : ans)cout << i << "\n";
    }
    else cout << -1 << endl;
}