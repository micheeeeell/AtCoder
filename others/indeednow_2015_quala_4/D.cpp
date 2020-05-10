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
    if (sizeof...(tail) != 0) cout << " ";
    print(forward<Tail>(tail)...);
}

template <class T>
void print(vector<T> &vec) {
    for (auto& a : vec) {
        cout << a;
        if (&a != &vec.back()) cout << " ";
    }
    cout << endl;
}

template <class T>
void print(vector<T> &vec, ll k){
   ll n = vec.size();
   k = min(k, n);
   rep(i,k-1)cout << vec[i] << " ";
   cout << vec[k-1] << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
    for (auto& vec : df) {
        print(vec);
    }
}

template<class T, class U>
void print(pair<T,U> &p){
    cout << p.first << " " << p.second << "\n";
}

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
map<vvl, ll> mp;
map<vvl, ll> mp2;
ll h,w;
struct state{
    state(){};
    vvl g;
    ll x, y;
    state(vvl &g, ll x, ll y): g(g), x(x), y(y) {}
};
void bfs(vvl &g, ll x, ll y){
    mp[g] = 0;

    queue<state> que;
    que.emplace(g, x, y);
    while(!que.empty()){
        auto t = que.front();que.pop();
        ll c = mp[t.g];
        if(c == 12)break;
        rep(i,4){
            ll nx = t.x + dx[i];
            ll ny = t.y + dy[i];
            if(nx < 0 || nx >= h)continue;
            if(ny < 0 || ny >= w)continue;
            swap(t.g[t.x][t.y], t.g[nx][ny]);
            if(mp.find(t.g) == mp.end()){
                que.emplace(t.g, nx, ny);
                mp[t.g] = c + 1;
                // print(t.g);debug(mp[t.g]);
            }
            swap(t.g[t.x][t.y], t.g[nx][ny]);
        }
    }

}

ll ans = INF;
void bfs_2(vvl &g, ll x, ll y){
    mp2[g] = 0;

    queue<state> que;
    que.emplace(g, x, y);
    while(!que.empty()){
        auto t = que.front();que.pop();
        ll c = mp2[t.g];
        if(mp.find(t.g) != mp.end()){
            chmin(ans, mp[t.g] + mp2[t.g]);
        }
        if(c == 12)continue;
        rep(i,4){
            ll nx = t.x + dx[i];
            ll ny = t.y + dy[i];
            if(nx < 0 || nx >= h)continue;
            if(ny < 0 || ny >= w)continue;
            swap(t.g[t.x][t.y], t.g[nx][ny]);
            if(mp2.find(t.g) == mp2.end()){
                que.emplace(t.g, nx, ny);
                mp2[t.g] = c + 1;
            }
            swap(t.g[t.x][t.y], t.g[nx][ny]);
        }
    }
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    cin >> h >> w;
    vvl g(h, vl(w));
    ll sx, sy;
    rep(i,h)rep(j,w) {
        cin >> g[i][j];
        if(g[i][j] == 0){
            sx = i;
            sy = j;
        }
    }
    vvl e(h, vl(w));
    rep(i,h)rep(j,w){
        e[i][j] = i * w + j + 1;
        if(i == h-1 && j == w-1)e[i][j] = 0;
    }

    // print(e);
    bfs(g, sx, sy);
    bfs_2(e, h-1, w-1);

    
    cout << ans << endl;
}