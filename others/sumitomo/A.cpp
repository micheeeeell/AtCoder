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
    
    ll m,d; cin >> m >> d;
    ll m2,d2; cin >> m2 >> d2;
    cout << (m != m2 ? 1 : 0) << endl;
    
}