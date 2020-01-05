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
    string s;cin >> s;
    ll n = s.size();
    bitset<26> bs(0);
    rep(i,n)bs[s[i]-'a'] = 1;
    string ans;
    if(bs.count() != 26){
        ans = s;
        rep(i,26)if(bs[i] == 0){ans += 'a'+i;break;}
    }
    else{
        ans = s;
        for(int i = 25; 0 <= i; i--){
            bool ok = false;
            ans.pop_back();
            ll t = s[i] - 'a';
            bs[t] = 0;
            for(int j = t+1; j < 26; j++){
                if(bs[j] == 0){ans += 'a' + j; ok = true;break;}
            }
            if(ok)break;
        }
        if(ans == "")ans = "-1";
    }

    cout << ans << endl;
}