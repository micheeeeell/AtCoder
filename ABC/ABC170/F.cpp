#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include<bits/stdc++.h>
using namespace std;
#define rep(i,s,t) for(ll i = (ll)(s); i < (ll)(t); i++)
#define rrep(i,s,t) for(ll i = (ll)(s-1);(ll)(t) <= i; i--)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> Pll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
constexpr ll INF = numeric_limits<ll>::max()/4;
constexpr ll n_max = 2e5+10;
#define int ll

template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string &s) {return '"' + s + '"';}
string to_string(const char *c) {return to_string((string) c);}
string to_string(bool b) {return (b ? "true" : "false");}
template <size_t N>
string to_string(bitset<N> v){
    string res = "";
    for(size_t i = 0; i < N; i++) res += static_cast<char>('0' + v[i]);
    return res;
}
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for(const auto &x : v) {
        if(!first) res += ", ";
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p){return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}

void debug_out() {cerr << endl;}
template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

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
void print(vector<vector<T>> &df) {
    for (auto& vec : df) {
        print(vec);
    }
}

struct item{
    ll l, r, u, d;
    item(){
        l = -1;
        r = -1;
        u = -1;
        d = -1;
    }
};
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll h,w,k; cin >> h >> w >> k;
    ll sx,sy; cin >> sx >> sy;
    ll tx,ty; cin >> tx >> ty;
    sx--;sy--;tx--;ty--;

    ll dx[] = {0,0,1,-1};
    ll dy[] = {1,-1,0,0};
    auto is_out = [&](ll x, ll y){
       if(x < 0 || x >= h || y < 0 || y >= w)return true;
       return false;
    };


    vector<string> v(h);
    vector<vector<item>> items(h, vector<item>(w));

    rep(i,0,h){
        cin >> v[i];
    }

    queue<Pll> que;
    vector<vector<ll>> used(h, vector<ll>(w, INF));

    que.emplace(sx, sy);
    used[sx][sy] = 0;
    while(!que.empty()){
        auto [x, y] = que.front();que.pop();
        ll c = used[x][y];
        if(x == tx && y == ty){
            cout << c << "\n";
            return 0;
        }
        item temp = items[x][y];
        item sv;
        rep(i, 0, 4){
            ll mx = x, my = y;
            ll st = 1;
            if(i == 0 && temp.d != -1){
                st = temp.d - y;
            }
            if(i == 1 && temp.u != -1){
                st = y - temp.u;
            }
            if(i == 2 && temp.r != -1){
                st = temp.r - x;
            }
            if(i == 3 && temp.l != -1){
                st = x - temp.l;
            }
            // debug(x, y, i, st);
            rep(j, st, k+1){
                ll nx = x + dx[i] * j, ny = y + dy[i] * j;
                if(is_out(nx, ny))break;
                if(v[nx][ny] == '@')break;
                mx = nx, my = ny;
                if(used[nx][ny] != INF)continue;
                used[nx][ny] = c + 1;
                que.emplace(nx, ny);
            }
            if(i == 0) sv.d = my;
            if(i == 1) sv.u = my;
            if(i == 2) sv.r = mx;
            if(i == 3) sv.l = mx;
            // debug(x, y, i, mx, my);
        }
        rep(i,0,4){
            ll st = 1;
            if(i == 0 && temp.d != -1){
                st = temp.d - y;
            }
            if(i == 1 && temp.u != -1){
                st = y - temp.u;
            }
            if(i == 2 && temp.r != -1){
                st = temp.r - x;
            }
            if(i == 3 && temp.l != -1){
                st = x - temp.l;
            }
            rep(j, st, k+1){
                ll nx = x + dx[i] * j, ny = y + dy[i] * j;
                if(is_out(nx, ny))break;
                if(v[nx][ny] == '@')break;
                if(i == 0){
                    items[nx][ny].d = sv.d;
                    items[nx][ny].u = sv.u;
                }
                if(i == 1){
                    items[nx][ny].u = sv.u;
                    items[nx][ny].d = sv.d;
                }
                if(i == 2){
                    items[nx][ny].r = sv.r;
                    items[nx][ny].l = sv.l;
                }
                if(i == 3){
                    items[nx][ny].r = sv.r;
                    items[nx][ny].l = sv.l;
                }
            }
        }
        // print(used);
        // print();
    }
    // debug(used);
    // print(used);
    cout << (used[tx][ty] == INF ? -1 : used[tx][ty]) << endl;
}