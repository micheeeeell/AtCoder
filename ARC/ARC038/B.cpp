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

void YES(bool ok){
    cout << (ok ? "First" : "Second") << endl;
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll h,w; cin >> h >> w;
    string s[h];
    rep(i,h)cin >> s[i];
    vector<vector<ll>> graph(h, vector<ll>(w, -1));
    ll dx[] = {1,0,1};
    ll dy[] = {0,1,1};

    auto c = [&](ll x, ll y){
        if(x < 0 || h <= x)return false;
        if(y < 0 || w <= y)return false;
        return true;
    };

    // graph[h-1][w-1] = 0;
    vector<ll> cnt(4), clear(4);
    ll nx, ny;
    rrep(i,h){
        rrep(j,w){
            if(s[i][j] == '#')continue;
            cnt = clear;
            rep(k,3){
                nx = i + dx[k], ny = j + dy[k];
                if(!c(nx, ny))continue;
                if(graph[nx][ny] == -1)continue;
                cnt[graph[nx][ny]]++;
            }
            rep(k,4)if(cnt[k] == 0){
                graph[i][j] = k;
                break;
            }
        }
    }

    // print(graph);

    YES(graph[0][0]);
}