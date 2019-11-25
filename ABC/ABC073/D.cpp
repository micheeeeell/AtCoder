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
    ll INF = LLONG_MAX/4;
    ll n,m,r; cin >> n >> m >> r;
    vector<ll> r_vec(r);
    rep(i,r){
        cin >> r_vec[i];
        r_vec[i]--;
    }
    sort(all(r_vec));
    vvl ab(n,vector<ll>(n,INF));
    rep(i,m){
        ll a,b,c; cin >> a >> b >> c;
        a--;b--;
        ab[a][b] = c;
        ab[b][a] = c;
    }

    rep(k,n)rep(i,n)rep(j,n){
        ab[i][j] = min(ab[i][j], ab[i][k] + ab[k][j]);
    }

    ll res = INF;
    do{
        ll temp = 0;
        rep(i,r-1){
            temp += ab[r_vec[i]][r_vec[i+1]];
        }
        res = min(res,temp);
    }while(next_permutation(all(r_vec)));

    cout << res << endl;
}