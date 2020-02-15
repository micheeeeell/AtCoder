#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(int i = 0; i < (int)(x); i++)
#define rrep(i,x) for(int i = (int)(x)-1;i <= 0; i--)
#define reps(i,x) for(int i = 1; i < (int)(x); i++)
#define rreps(i,x) for(int i = (int)(x)-1; i <= 1; i--)
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
const int n_max = 110;

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
    ll n,k; cin >> n >> k;
    vector<Pll> ans;
    if((n-1) * (n-2) / 2 < k){
        cout << -1 << endl;
        return 0;
    }
    vector< bitset<n_max> > graph(n, bitset<n_max>(0));
    rep(i,n-1){
        graph[0][i+1] = 1;
        graph[i+1][0] = 1;
        ans.emplace_back(1, i + 2);
    }
    ll num = (n-1) * (n-2) / 2;
    bool ok = num <= k;
    for(int i = 1; i < n; i++){
        if(ok)break;
        for(int j = i+1; j < n; j++){
            if(ok)break;
            if(graph[i][j] == 0){
                graph[i][j] = 1;
                graph[j][i] = 1;
                ans.emplace_back(i+1, j+1);
                num--;
                ok = (num <= k);
            }
        }
    }

    cout << ans.size() << endl;
    rep(i,ans.size())print(ans[i]);
}