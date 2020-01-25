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
const int n_max = 1e5+10;

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

void print() {
    cout << endl;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
    cout << head;
    if (sizeof...(tail) != 0) cout << ' ';
    print(forward<Tail>(tail)...);
}

template <class T>
void print(vector<T> &vec) {
    for (auto& a : vec) {
        if(a == INF)cout << "INF";
        else cout << a;
        if (&a != &vec.back()) cout << ' ';
    }
    cout << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
    for (auto& vec : df) {
        print(vec);
    }
}

void print(Pll &p){
    print(p.first, p.second);
}

int main(){
    ll h,w; cin >> h >> w;
    ll a[h][w];
    rep(i,h)rep(j,w)cin >> a[i][j];
    auto ch = [&](ll x, ll y){
        return 0 <= x && x < h && 0 <= y && y < w;
    };
    using Plll = pair<ll, Pll>;
    // priority_queue<Plll, vector< Plll >, greater< Plll > > pq;
    // vector<vector<ll>> cost(h, vector<ll>(w,INF));
    // cost[h-1][0] = 0;
    // pq.push(Plll(0,Pll(h-1,0)));
    ll dx[] = {0,0,1,-1};
    ll dy[] = {1,-1,0,0};
    // while(!pq.empty()){
    //     Plll t = pq.top();pq.pop();
    //     ll x = t.second.first, y = t.second.second;
    //     if(x == 0 && y == w-1)break;
    //     rep(i,4){
    //         ll nx = x + dx[i], ny = y + dy[i];
    //         if(ch(nx,ny) && chmin(cost[nx][ny], cost[x][y] + a[nx][ny])){
    //             pq.push(Plll(cost[nx][ny], Pll(nx,ny)));
    //         }
    //     }
    // }

    // debug("test");
    // vector<Pll> path;
    // queue<Pll> que;
    // vvl is_used(h,vl(w,0));
    // is_used[0][w-1] = 1;
    // que.push(Pll(0,w-1));
    // while(!que.empty()){
    //     Pll t = que.front();que.pop();
    //     path.emplace_back(t);
    //     rep(i,4){
    //         ll nx = t.first + dx[i], ny = t.second + dy[i];
    //         if(ch(nx,ny) && cost[nx][ny] == cost[t.first][t.second] - a[t.first][t.second] && is_used[nx][ny] == 0){
    //             que.push(Pll(nx,ny));
    //             is_used[nx][ny] = 1;
    //         }
    //     }
    // }
    ll ans = INF;
    rep(i,h)rep(j,w){
        priority_queue<Plll, vector< Plll >, greater< Plll > > pque;
        vector<vector<ll>> c(h, vector<ll>(w,INF));
        c[i][j] = 0;
        pque.push(Plll(0,Pll(i,j)));
        while(!pque.empty()){
            Plll t = pque.top();pque.pop();
            ll x = t.second.first, y = t.second.second;
            // if(x == h-1 && y == w-1)break;
            rep(i,4){
                ll nx = x + dx[i], ny = y + dy[i];
                if(ch(nx,ny) && chmin(c[nx][ny], c[x][y] + a[nx][ny])){
                    pque.push(Plll(c[nx][ny], Pll(nx,ny)));
                }
            }
        }

        if(chmin(ans, c[h-1][0] + c[h-1][w-1] + c[0][w-1] + a[i][j])){
            // print("i:", i,"j:", j);
            // print(c);
            // print("ans:",ans);
        }
    }

    cout << ans << endl;
}