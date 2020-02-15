#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define rrep(i,x) for(ll i = (ll)(x)-1;i <= 0; i--)
#define reps(i,x) for(ll i = 1; i < (ll)(x); i++)
#define rreps(i,x) for(ll i = (ll)(x)-1; i <= 1; i--)
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
const int n_max = 1010;

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
    ll n,m; cin >> n >> m;
    vector<vector<ll>> graph(n), rev(n);
    vector<Pll> edge(m);
    rep(i,m){
        ll a,b; cin >> a >> b;
        a--;b--;
        graph[a].emplace_back(b);
        rev[b].emplace_back(a);
        edge[i] = {a, b};
    }
    vector<ll> path, clear;
    auto check = [&](ll s, ll g) -> bool{
        bool ret = false;
        vector<ll> moved(n,0);
        queue<ll> que;
        que.push(s);
        moved[s] = 1;
        while(!que.empty()) {
            ll t = que.front();que.pop();
            if(t == g){
                ret = true;
                break;
            }
            for(auto to : graph[t]){
                if(moved[to] == 0){
                    moved[to] = moved[t] + 1;
                    que.push(to);
                }
            }
        }
        // debug(s);debug(g);
        // print(moved);
        if(!ret)return ret;
        ll pos = g;
        path.emplace_back(g);
        while(pos != s) {
            for(auto to : rev[pos]){
                if(moved[to] == moved[pos] - 1){
                    path.emplace_back(to);
                    pos = to;
                    break;
                }
            }
        }
        return ret;
    };

    using Pv = pair<ll, vector<ll>>;
    Pv res = make_pair(INF, path);

    rep(i,m){
        ll s = edge[i].first, t = edge[i].second;
        path = clear;
        if(check(t,s)){
            Pv p = {path.size(), path};
            chmin(res, p);
        }
    }



    if(res.first == INF)cout << -1 << endl;
    else{
        cout << res.first << "\n";
        for(auto i : res.second)cout << i+1 << "\n";
    }
    return 0;
}