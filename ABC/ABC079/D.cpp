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

    ll n,z; cin >> n >> z;
    ll w; cin >> w;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll ans = 0;
    if(n == 1)ans = abs(a[0] - w);
    else{
        ans = max(abs(a[n-1]-w), abs(a[n-2]-a[n-1]));
    }
    cout << ans << endl;
}
