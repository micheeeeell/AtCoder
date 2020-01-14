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
    ll h,w; cin >> h >> w;
    string s[h];
    rep(i,h)cin >> s[i];
    vector<Pll> start;
    rep(i,h)rep(j,w)if(s[i][j] == '.')start.emplace_back(Pll(i,j));

    ll dx[4] = {0,0,1,-1};
    ll dy[4] = {1,-1,0,0};
    ll ans = 0;
    for(auto st : start){
        queue<Pll> que;
        vector<vector<ll>> is_moved(h,vector<ll>(w,0));
        is_moved[st.first][st.second] = 1;
        que.push(st);
        ll max_ = 0;
        while (que.size())
        {
            Pll t = que.front();que.pop();
            ll x = t.first, y = t.second;
            rep(i,4){
                ll nx = x + dx[i];
                ll ny = y + dy[i];
                if(0 <= nx && nx < h && 0 <= ny && ny < w && s[nx][ny] == '.' && is_moved[nx][ny] == 0){
                    is_moved[nx][ny] = is_moved[x][y] + 1;
                    max_ = max(max_, is_moved[nx][ny]);
                    que.push({nx,ny});
                }
            }
        }
        ans = max(ans, max_);
    }

    cout << ans-1 << endl;
}