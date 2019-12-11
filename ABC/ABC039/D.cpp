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

template<typename T>
void print(T &arr){
    ll sz = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0;i < sz-1;i++){cout << arr[i] << ' ';}
    cout << arr[sz-1] << endl;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll h,w; cin >> h >> w;
    string s[h];
    rep(i,h)cin >> s[i];
    int dx[8] = {0,0,1,-1,1,1,-1,-1};
    int dy[8] = {1,-1,0,0,1,-1,1,-1};
    auto is_black = [&](ll x, ll y){
        bool ret = true;
        rep(i,8){
            ll nx = x + dx[i];
            ll ny = y + dy[i];
            if(nx < 0 || ny < 0 || h <= nx || w <= ny)continue;
            ret &= (s[nx][ny] == '#');
        }
        return ret;
    };
    vector<vector<ll>> graph(h,vector<ll>(w,0));
    rep(i,h)rep(j,w){
        if(s[i][j] == '#' && is_black(i,j))graph[i][j] = 1;
    }
    // print(graph);
    auto check = [&](ll x, ll y){
        bool ret = false;
        rep(i,8){
            ll nx = x + dx[i];
            ll ny = y + dy[i];
            if(nx < 0 || ny < 0 || h <= nx || w <= ny)continue;
            ret |= (graph[nx][ny]);
        }
        ret |= graph[x][y];
        return ret;
    };
    bool ok = true;
    rep(i,h)rep(j,w){
        if(s[i][j] == '#')ok &= check(i,j);
    }
    if(ok){
        cout << "possible" << endl;
        rep(i,h){
            rep(j,w){
                if(graph[i][j])cout << '#';
                else cout << '.';
            }
            cout << "\n";
        }
    }
    else{
        cout << "impossible" << endl;
    }
}