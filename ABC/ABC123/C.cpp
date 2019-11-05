#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(int i = 0; i < x; i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
const ll MOD = 1e9+7;
const int n_max = 1e5+10;

ll ceil(ll a, ll b){
    return (a+b-1)/b;
}
int main(){
    ll n; cin >> n;
    vector<ll> vec(5);
    rep(i,5) cin >> vec[i];
    ll min_time = *min_element(vec.begin(), vec.end());
    cout << 4 + ceil(n,min_time) << endl;
    return 0;
}