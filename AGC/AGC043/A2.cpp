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
        cout << a;
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

template<class T, class U>
void print(pair<T,U> &p){
    print(p.first, p.second);
}


int main(){
    ll h,w; cin >> h >> w;
    string s[h];
    rep(i,h)cin >> s[i];

    int dx[] = {0,1};
    int dy[] = {1,0};
    auto check = [&](int x, int y){
        if(x < 0 || h <= x)return false;
        if(y < 0 || w <= y)return false;
        return true;
    };

    auto dijkstra = [&](int sx, int sy){
        vector<vector<ll>> graph(h, vector<ll>(w,INF));
        graph[0][0] = (s[0][0] == '#') ? 1 : 0;
        using Plll = pair<ll, Pll>;
        priority_queue<Plll, vector<Plll>, greater<Plll>> pq;
        Plll st = {graph[0][0], {0 ,0}};
        pq.emplace(st);
        Plll temp;
        while(!pq.empty()) {
            auto p = pq.top();pq.pop();
            ll c = p.first, x = p.second.first, y = p.second.second;
            if(graph[x][y] < c)continue;
            rep(i,2){
                int nx = x + dx[i], ny = y + dy[i];
                if(!check(nx,ny))continue;
                if(c + 1 > graph[nx][ny])continue;
                if(s[nx][ny] == '#'){
                    if(s[x][y] == '#'){
                        graph[nx][ny] = c;
                        temp = {c, {nx,ny}};
                        pq.emplace(temp);
                    }
                    else {
                        graph[nx][ny] = c + 1;
                        temp = {c+1, {nx, ny}};
                        pq.emplace(temp);
                    }
                }
                else{
                    graph[nx][ny] = c;
                    temp = {c, {nx,ny}};
                    pq.emplace(temp);
                }
            }
            // print(c,x,y);
            // print(graph);
            // print();
        }
        return graph;
    };
    auto graph = dijkstra(0,0);

    // print(graph);
    cout << graph[h-1][w-1] << endl;
}