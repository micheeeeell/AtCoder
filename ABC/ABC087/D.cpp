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
#define eb emplace_back
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
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

ll n = 1e5+10,m = 2e5+10;
ll INF = INT_MAX;
vector<ll> place(n,INF);
// bool ok = true;
vector<vector<Pll>> graph(n);
// template<class T>
bool dfs(int now){
    bool ok = true;
    // is_move[now] = 1;
    for(auto i : graph[now]){
        int to = i.first;
        ll dis = i.second;
        // if(to == pre)continue;
        if(place[to] == INF){
            place[to] = place[now] + dis;
            ok &= dfs(to);
        }
        else{
            if(place[to] != place[now] + dis){
                ok = false;
                break;
            }
        }
    }
    return ok;
}

int main(){
    cin >> n >> m;
    // vector<ll> l(m), r(m), d(m);
    // vector<vector<Pll>> graph(n);
    set<ll> st;
    rep(i,m){
        ll l,r,d;cin >> l >> r >> d;
        l--;r--;
        st.insert(l);
        st.insert(r);
        graph[l].emplace_back(Pll(r,d));
        graph[r].emplace_back(Pll(l,-d));
    }
    bool res = true;

    // clock_t start = clock();

    rep(i,n){
        // if(graph[i].size() == 0)continue;
        // print(i,is_move[i],place[i]);
        if(place[i] == INF){
            place[i] = 0;
            res &= dfs(i);
        }
        if(!res)break;
    }

    // clock_t end = clock();

    // const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    // printf("time %lf[ms]\n", time);
    cout << (res ? "Yes" : "No") << endl;
}