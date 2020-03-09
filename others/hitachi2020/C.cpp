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
const int n_max = 2e5+10;

// vector<ll> cnt(6,0), assign(6,0);
vector<ll> used(n_max,0), clear(n_max,0);
vector<ll> ans(n_max, 0);
// void count(vvl &graph, int pos, int depth = 0){
//     used[pos] = 1;
//     cnt[depth % 6]++;
//     for(auto to : graph[pos]){
//         if(!used[to])count(graph, to, depth+1);
//     }
// }

void dfs(vvl &graph, int pos, int depth = 0){
    used[pos] = 1;
    ans[pos] = depth;
    for(auto to : graph[pos]){
        if(!used[to])dfs(graph, to, depth + 1);
    }
}

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}


template <class T>
void print(vector<T> &vec, int n) {
    int cnt = 0;
    for (auto& a : vec) {
        cout << a;
        if (&a != &vec.back()) cout << ' ';
        if(++cnt >= n)break;
    }
    cout << endl;
}


template<class T, class U>
void print(pair<T,U> &p){
    print(p.first, p.second);
}


int main(){
    ll n; cin >> n;
    vector<vector<ll>> graph(n);
    rep(i,n-1) {
        ll a,b;cin >> a >> b;
        a--;b--;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }

    // count(graph, 0);
    // used = clear;
    // Pll p = {INF, -1};
    // rep(i,3)chmin(p, {cnt[i] + cnt[i+3], i});
    // if(p.second == 0)assign = {0,1,2,0,2,1};
    // else if(p.second == 1)assign = {2,0,2,1,0,1};
    // else assign = {1,2,0,2,1,0};
    dfs(graph, 0);
    // print(ans, n);

    ll x = n/3, y = x + (x * 3 < n), z = x + (x * 3 + 1 < n);
    vector<ll> cnt(2,0);
    rep(i,n)cnt[ans[i] & 1]++;
    int jud = 0;
    if(cnt[1] < y)jud = 1;
    if(cnt[0] < z)jud = 2;
    ll zero = 3, one = 1, two = 2;
    rep(i,n){
        if(jud == 0){
            if(ans[i] & 1){
                if(one <= n){
                    ans[i] = one;
                    one += 3;
                }
                else{
                    ans[i] = zero;
                    zero += 3;
                }
            }
            else{
                if(two <= n){
                    ans[i] = two;
                    two += 3;
                }
                else{
                    ans[i] = zero;
                    zero += 3;
                }
            }
        }
        if(jud == 1){
            if(ans[i] & 1){ans[i] = zero;zero+=3;}
            else{
                if(one <= n){ans[i] = one;one += 3;}
                else if(two <= n){ans[i] = two;two += 3;}
                else{ans[i] = zero;zero += 3;}
            }
        }
        if(jud == 2){
            if((ans[i] & 1) == 0){ans[i] = zero;zero+=3;}
            else{
                if(one <= n){ans[i] = one;one += 3;}
                else if(two <= n){ans[i] = two;two += 3;}
                else{ans[i] = zero;zero += 3;}
            }
        }
    }
    debug(jud);
    rep(i,n)cout << ans[i] << " ";
    cout << endl;
}