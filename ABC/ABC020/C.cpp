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
    ll h,w,t; cin >> h >> w >> t;
    string s[h];
    rep(i,h)cin >> s[i];
    Pll st, go;
    rep(i,h)rep(j,w){
        if(s[i][j] == 'S')st = {i,j};
        if(s[i][j] == 'G')go = {i,j};
    }
    using Plll = pair<ll, Pll>;
    int dx[] = {0,0,1,-1};
    int dy[] = {1,-1,0,0};
    
    auto check = [&](ll time){
        vector<vector<ll>> graph(h, vector<ll>(w,INF));
        priority_queue<Plll, vector<Plll>, greater<Plll>> pq;
        graph[st.first][st.second] = 0;
        pq.emplace(0,st);
        while(!pq.empty()) {
            auto p = pq.top();pq.pop();
            ll c = p.first;
            int x = p.second.first;
            int y = p.second.second;
            if(graph[x][y] < c)continue;
            rep(i,4){
                int nx = x + dx[i], ny = y + dy[i];
                if(nx < 0 || h <= nx)continue;
                if(ny < 0 || w <= ny)continue;
                ll nc = (s[nx][ny] == '#' ? time : 1);
                if(graph[nx][ny] <= c + nc)continue;
                graph[nx][ny] = c + nc;
                pq.emplace(c+nc, Pll(nx,ny));
            }
            // print(c,x,y);
        }
        // print(graph);print(); 
        return graph[go.first][go.second] <= t;
    };

    ll ok = 1;
    ll ng = t;
    while(abs(ok - ng) > 1) {
        ll x = (ok + ng) / 2;
        if(check(x))ok = x;
        else ng = x;
    }

    cout << ok << endl;
}