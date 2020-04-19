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

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

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


vector<vector<ll>> b(2, vector<ll>(3));
vector<vector<ll>> c(3, vector<ll>(2));

ll dfs(vvl &graph, ll x, ll y, ll turn){
    graph[x][y] = turn % 2 + 1;
    if(turn == 8){
        ll res = 0;
        rep(i,2)rep(j,3){
            if(graph[i][j] == graph[i+1][j])res += b[i][j];
        }   
        rep(i,3)rep(j,2){
            if(graph[i][j] == graph[i][j+1])res += c[i][j];
        }
        // print(graph);print(res);
        graph[x][y] = 0;
        return res;
    }
    ll ret = (turn % 2 == 0 ? INF : 0);
    rep(i,3)rep(j,3){
        if(graph[i][j])continue;
        if(turn % 2 == 0)chmin(ret, dfs(graph, i, j, turn + 1));
        else chmax(ret, dfs(graph, i, j, turn + 1));
    }
    graph[x][y] = 0;
    return ret;
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    rep(i,2)rep(j,3)cin >> b[i][j];
    rep(i,3)rep(j,2)cin >> c[i][j];

    vector<vector<ll>> graph(3, vector<ll>(3));
    ll ans = 0;
    // debug(dfs(graph, 0, 0, 0));
    ll sum = 0;
    rep(i,2)rep(j,3)sum += b[i][j];
    rep(i,3)rep(j,2)sum += c[i][j];

    rep(i,3)rep(j,3)chmax(ans, dfs(graph, i, j, 0));
    cout << ans << endl;
    cout << sum - ans << endl;
}