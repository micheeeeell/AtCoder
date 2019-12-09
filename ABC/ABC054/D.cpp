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
const int n_max = 1e5+10;

class drug{
    public:
    drug(){};
    drug(int a, int b, int c):a(a), b(b), c(c){};
    int a;
    int b;
    int c;
};

int main(){
    ll n,ma,mb; cin >> n >> ma >> mb;
    vector<drug> d(n);
    rep(i,n){
        ll a,b,c; cin >> a >> b >> c;
        d[i] = drug(a,b,c);
    }
    vvvl dp(2, vvl(400, vl(400,INF)));
    dp[0][0][0] = 0;
    rep(i,n)rep(j,400)rep(k,400){
        if(dp[i%2][j][k] != INF){
            dp[(i+1)%2][j+d[i].a][k+d[i].b] = min(dp[i%2][j][k] + d[i].c, dp[(i+1)%2][j+d[i].a][k+d[i].b]);
            dp[(i+1)%2][j][k] = min(dp[i%2][j][k], dp[(i+1)%2][j][k]);
        }
    }
    ll res = INF;
    rep(i,400)rep(j,400){
        if(!i || !j)continue;
        if(i * mb == j * ma)res = min(res, dp[n%2][i][j]);
    }
    cout << (res == INF ? -1 : res) << endl;
}