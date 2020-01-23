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
const ll INF = LLONG_MAX/4;
const ll MOD = 1e9+7;
const int n_max = 1e5+10;

int main(){
    ll n,m; cin >> n >> m;
    const int m_max = 30;
    bitset<m_max> bs((1LL << m)-1);
    rep(i,n){
        ll k; cin >> k;
        bitset<m_max> temp(0);
        rep(j,k){
            ll a; cin >> a;
            a--;
            temp[a] = 1;
        }
        bs &= temp;
    }

    cout << bs.count() << endl;
}