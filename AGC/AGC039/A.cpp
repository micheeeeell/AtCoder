// #include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<bitset>
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
    ll k; cin >> k;
    vector<ll> vec;
    ll n = s.size();
    ll tmp = 1;
    rep(i,n-1){
        if(s[i+1] == s[i])tmp++;
        else{
            vec.emplace_back(tmp);
            tmp = 1;
        }
    }
    vec.emplace_back(tmp);
    ll ret = 0;
    if(vec.size() == 1){
        if(n % 2 == 1 && k%2 == 1){
            ret = n/2 + (n*2)/2 * (k/2);
        }
        else{
            ret = ((n*2) * k) / 4;
        }
    }
    else{
        if(s[0] != s[n-1]){
            for(auto itr = vec.begin(); itr != vec.end(); itr++){
                ret += *itr /2;
            }
            ret *= k;
        }
        else{
            ll st = 0, ed = 0;
            ll cnt = 0;
            while(s[cnt] == s[0]){
                st++;cnt++;
            }
            cnt = n-1;
            while(s[cnt] == s[n-1]){
                ed++;cnt--;
            }
            
            for(int i = 1; i < vec.size()-1; i++){
                ret += vec[i]/2;
            }
            
            ret *= k;
            ret += (k-1) * ((st+ed) / 2);
            ret += st / 2 + ed / 2;
        }
    }
    cout << ret << endl;
}