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
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll n,m; cin >> n >> m;
    vector<Pll> ab(n);
    rep(i,n){
        ll a,b; cin >> a >> b;
        ab[i] = make_pair(a,b);
    }
    sort(all(ab));
    ll temp = 0, res = 0, cnt = 0;
    while(temp < m){
        ll rest = m - temp;
        if(ab[cnt].second < rest){
            temp += ab[cnt].second;
            res += ab[cnt].first * ab[cnt].second;
        }
        else{
            temp += rest;
            res += ab[cnt].first * rest;
        }
        cnt++;
    }
    cout << res << endl;
}