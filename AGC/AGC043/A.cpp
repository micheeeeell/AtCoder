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

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

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

    vector<vector<ll>> graph(h, vector<ll>(w,INF));
    deque<Pll> deq;
    graph[0][0] = (s[0][0] == '.') ? 0 : 1;
    deq.emplace_front(0,0);
    while(!deq.empty()){
        auto p = deq.front();deq.pop_front();
        // print(p);
        int x = p.first, y = p.second;
        ll c = graph[x][y];
        rep(i,2){
            int nx = x + dx[i], ny = y + dy[i];
            
            if(!check(nx,ny)){continue;}
            // if(graph[nx][ny] != INF)continue;

            if(s[nx][ny] == '#'){
                if(s[x][y] == '#'){
                    if(chmin(graph[nx][ny], c))deq.emplace_front(nx,ny);
                }
                else {
                    if(chmin(graph[nx][ny], c + 1))deq.emplace_back(nx,ny);
                }
            }
            else{
                if(chmin(graph[nx][ny], c))deq.emplace_front(nx, ny);
            }
            
            // print(nx,ny);
            // debug("test");
        }
        
    }
    // print(graph);
    cout << graph[h-1][w-1] << endl;
}