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
const int n_max = 2e5+10;

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

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

vector<vector<ll>> memo(3,vector<ll>(n_max,-1));
bool dfs(ll top, ll index){
    bool res = false;
    assert(top == 1 || top == 2);
    if(memo[top][index] != -1)return memo[top][index];
    if(index == 1){
        memo[1][index] = 1;
        memo[2][index] = 0;
        return memo[top][index];
    }
    if(top == 1){
        res |= !dfs(1, index-1);
        res |= !dfs(2, index-1);
    }
    if(top == 2){
        res |= !dfs(1,index);
        res |= !dfs(2,index-1);
    }
    memo[top][index] = res;
    return res;
};
int main(){
    ll n; cin >> n;
    vector<vector<ll>> graph(n);
    rep(i,n-1){
        ll a,b; cin >> a >> b;
        a--;b--;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    queue<Pll> que;
    bitset<n_max> bs(0);
    vector<ll> count(n,0);
    Pll m = {-1,-1};
    rep(i,n){
        if(graph[i].size() == 1){
            que.push({i,1});
            bs[i] = 1;
            // count[1]++;
        }
    }
    while(que.size()){
        Pll t = que.front();que.pop();
        count[t.second]++;
        chmax(m, {t.second, count[t.second]});
        for(auto to : graph[t.first]){
            if(bs[to] == 0){
                que.push({to,t.second + 1});
                bs[to] = 1;
            }
        }
    }

    print(count);
    debug(m.first);debug(m.second);

    cout << (dfs(m.second, m.first) ? "First" : "Second") << endl;
}