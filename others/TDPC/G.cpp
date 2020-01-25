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
    ll k; cin >> k;
    ll n = s.size();
    vector< vector< ll >> dp(n+1, vector<ll>(26,0));
    // vector< vector< ll >> next(n+1, vector<ll>(26,n));
    for(int i = n-1; i >= 0; i--){
        ll t = s[i] - 'a';
        ll sum = 0;
        rep(j,26){
            sum += dp[i+1][j];
            if(sum >= INF)sum = INF;
            if(j != t)dp[i][j] = dp[i+1][j];
        }
        dp[i][t] = sum + 1;
    }
    string ans;
    // ll cnt = 0;
    // for(int i = n-1;i >= 0; i--){
    //     ll t = s[i] - 'a';
    //     rep(j,26){
    //         if(j != t)next[i][j] = next[i+1][j];
    //         else next[i][j] = i;
    //     }
    // }
    bool ok = false;
    ll pos = 0;
    while(k > 0){
        rep(i,26){
            if(k > dp[pos][i])k -= dp[pos][i];
            else{
                ans += 'a' + i;
                k--;
                // pos = next[pos][i] + 1;
                while(s[pos] != i + 'a')pos++;
                pos++;
                ok = true;
                break;
            }
        }
        if(!ok)break;
    }

    cout << (ok ? ans : "Eel") << endl;
}