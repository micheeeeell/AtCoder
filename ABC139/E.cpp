#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(int i = 0; i < x; i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<vector<P>>  vvp;
const ll MOD = 1e9+7;
const int n_max = 1e4+10;



// vvi is_moved(n_max, vi(n_max,0));
set<pair<P, P> > st;
bool ok = true;
// template<typename T>
void loop(vvp graph, P now, P pre = P(-1,-1)){
    cout << now.first  << ' ' << now.second  << endl;
    // is_moved[now.first][now.second] = 1;
    pair<P, P> edge = make_pair(now,pre);
    if(!st.insert(edge).second){ok = false;return ;}
    for(auto i : graph[now.first][now.second]){
        loop(graph, i, now);
    }
}

int memo[n_max][n_max] = {};
// template<typename T>
int dfs(vvp graph, P now, P end, int count = 0){
    // cout << now.first  << ' ' << now.second  << ' ' << count << endl;
    // cout << end.first  << ' ' << end.second  << ' ' << count << endl;
    if(now == end)return count;
    if(memo[now.first][now.second])return memo[now.first][now.second];
    int res = 0;
    for(auto i : graph[now.first][now.second]){
        // cout << i.first  << ' ' << i.second << endl;
        res = max(res, dfs(graph, i, end, count + 1));
    }
    memo[now.first][now.second] = res;
    return res;
}

int main(){
    int n; cin >> n;
    vector<int> vec[n];
    vector<vector<int>> vec2[n][n];
    vector<vector<P> >  graph[n];
    vector<vector<vector<P> > > graph_rev(n, vector<vector<P> >(n, vector<P>()));
    vvi a(n,vector<int>(n-1));
    rep(i,n){
        rep(j,n-1){
            cin >> a[i][j];
            a[i][j]--;
            // cout << "test" << endl;
        }
    }
    rep(i,n)rep(j,n-1){
        if(j == n-2)continue;
        P from = (i < a[i][j] ? P(i,a[i][j]) : P(a[i][j], i));
        P to = (i < a[i][j+1] ? P(i,a[i][j+1]) : P(a[i][j+1], i));
        cout << from.first << ' ' << from.second << ' ' << to.first << ' ' << to.second << ' ' << endl;
        graph[from.first][from.second].push_back(to);
        graph_rev[to.first][to.second].push_back(from);
    }
    // bool ok = true;
    P start, end;
    rep(i,n)rep(j,n){
        if(i >= j)continue;
        if(graph[i][j].size() == 0)end = P(i,j);
        if(graph_rev[i][j].size() == 0)start = P(i,j);
    }

    // cout << "start"  << ' ' <<  start.first  << ' ' << start.second << endl;
    // cout << "end" << ' ' <<  end.first  << ' ' << end.second << endl;
    // cout << ok << endl;
    if(start == P(0,0) || end == P(0,0))ok = false;
    // cout << ok << endl;
    loop(graph, start);
    // cout << ok << endl;
    if(!ok){
        cout << -1 << endl;
        return 0;
    }
    cout << dfs(graph, start, end) + 1 << endl;
    return 0;
}