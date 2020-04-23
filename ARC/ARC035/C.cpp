#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
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
#define int ll

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
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll n,m; cin >> n >> m;
    vector<vector<ll>> graph(n, vector<ll>(n, INF));
    rep(i,m){
        ll s,t,c; cin >> s >> t >> c;
        s--;t--;
        chmin(graph[s][t], c);
        chmin(graph[t][s], c);
    }
    rep(i,n)graph[i][i] = 0;
    rep(k,n){
        rep(i,n)rep(j,n){
            chmin(graph[i][j], graph[i][k] + graph[k][j]);
        }
    }
    ll k; cin >> k;
    // print(graph);
    rep(i,k){
        ll s,t,c; cin >> s >> t >> c;
        s--;t--;
        chmin(graph[s][t], c);
        chmin(graph[t][s], c);
        if(s > t)swap(s,t);
        rep(j, n)rep(jj, n){
            chmin(graph[j][jj], graph[j][s] + graph[s][t] + graph[t][jj]);
            chmin(graph[j][jj], graph[j][t] + graph[t][s] + graph[s][jj]);
        }
        ll temp = 0;
        rep(j, n)rep(jj, n)if(j < jj)temp += graph[j][jj];
        cout << temp<< "\n";
        // print(graph);
    }
}