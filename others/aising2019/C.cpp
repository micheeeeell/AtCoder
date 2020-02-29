#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define rrep(i,x) for(ll i = (ll)(x)-1;0 <= i; i--)
#define reps(i,x) for(ll i = 1; i < (ll)(x)+1; i++)
#define rreps(i,x) for(ll i = (ll)(x); 1 <= i; i--)
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

ll h, w;
ll h_max = 410, w_max = 410;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
vector<vector<ll>> is_moved(h_max, vector<ll>(w_max, 0));
vector<ll> cnt(2, 0);
void dfs(vector<string> &s, ll x, ll y){
    is_moved[x][y] = 1;
    if(s[x][y] == '.')cnt[0]++;
    else cnt[1]++;
    rep(i,4){
        ll nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || h <= nx)continue;
        if(ny < 0 || w <= ny)continue;
        if(is_moved[nx][ny])continue;
        if(s[nx][ny] == s[x][y])continue;
        dfs(s, nx, ny);
    }
}

int main(){
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h)cin >> s[i];

    ll ans = 0;

    rep(i,h)rep(j,w){
        if(is_moved[i][j])continue;
        if(s[i][j] == '.')continue;
        fill(all(cnt), 0);
        dfs(s, i, j);
        ans += cnt[0] * cnt[1];

        // debug(i);debug(j);debug(ans);
    }

    cout << ans << endl;
}