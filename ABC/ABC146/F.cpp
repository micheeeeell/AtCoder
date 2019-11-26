#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(int i = 0; i < (int)(x); i++)
#define pb push_back
#define mp make_pair
#define debug(x) cerr << #x << ": " << (x) << "\n";
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
const ll MOD = 1e9+7;
const int n_max = 1e5+10;

int main(){
    ll n,m; cin >> n >> m;
    string s;cin >> s;
    reverse(all(s));
    vector<ll> res;

    ll now = 0;
    bool ok = true;
    while(now < n){
        ll temp = min(m,n-now);
        while(s[now + temp] == '1')temp--;
        res.emplace_back(temp);
        now += temp;
        if(temp <= 0){ok = false;break;}
    }
    if(!ok){
        cout << -1 << endl;
        return 0;
    }
    reverse(all(res));
    rep(i,res.size())cout << res[i] << " ";
    cout << endl;
}