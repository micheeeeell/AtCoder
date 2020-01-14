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

class pos{
    public:
    pos(){};
    pos(ll x, ll y, ll cnt): x(x), y(y), cnt(cnt){};
    ll x,y,cnt;
};
template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}
int main(){
    ll h,w,k; cin >> h >> w >> k;
    string a[h];
    rep(i,h) cin >> a[i];
    ll xs, ys;
    rep(i,h)rep(j,w)if(a[i][j] == 'S'){xs = i;ys = j;goto END;}
    END:
    ll dx[4] = {0,0,1,-1};
    ll dy[4] = {1,-1,0,0};
    bool been[h][w];
    rep(i,h)fill(been[i], been[i] + w,0);
    queue<pos> que;
    que.push(pos(xs,ys,0));
    been[xs][ys] = 1;
    while (que.size()){
        pos t = que.front();que.pop();
        ll x = t.x, y = t.y, cnt = t.cnt;
        rep(i,4){
            ll nx = x + dx[i];
            ll ny = y + dy[i];
            if(0 <= nx && nx < h && 0 <= ny && ny < w && a[nx][ny] == '.' && cnt+1 <= k && been[nx][ny] == 0){
                que.push(pos(nx,ny,cnt+1));
                been[nx][ny] = 1;
            }
        }
    }
    ll temp = INF;
    rep(i,h)rep(j,w){
        if(been[i][j] == 0)continue;
        ll min_ = min({i,j,h-1-i, w-1-j});
        min_ = (min_ + k - 1) / k;
        chmin(temp,min_);
    }
    cout << temp + 1 << endl;
}