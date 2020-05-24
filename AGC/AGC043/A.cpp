// #define LOCAL
#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include<bits/stdc++.h>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define rrep(i,x) for(ll i = (ll)(x)-1;0 <= i; i--)
#define reps(i,x) for(ll i = 1; i < (ll)(x)+1; i++)
#define rreps(i,x) for(ll i = (ll)(x); 1 <= i; i--)
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
string to_string(const char c) {return to_string((string) &c);}
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

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll h,w; cin >> h >> w;
    string s[h];
    rep(i,h)cin >> s[i];
    ll dx[] = {0,1};
    ll dy[] = {1,0};
    auto is_out = [&](ll x, ll y){
       if(x < 0 || x >= h || y < 0 || y >= w)return true;
       return false;
    };
    ll ans = 0;
    if(s[0][0] == '#')ans++;
    deque<Pll> deq;
    vector<vector<ll>> used(h, vector<ll>(w, INF));
    used[0][0] = ans;
    deq.emplace_back(0,0);

    while(!deq.empty()){
        auto p = deq.front();deq.pop_front();
        ll x = p.first, y = p.second;
        ll c = used[x][y];
        rep(i,2){
            ll nx = x + dx[i];
            ll ny = y + dy[i];
            if(is_out(nx, ny))continue;
            if(used[nx][ny] <= c)continue;
            if(s[nx][ny] == '#' && s[x][y] == '.'){
                used[nx][ny] = c + 1;
                deq.emplace_back(nx, ny);
            }
            else{
                used[nx][ny] = c;
                deq.emplace_front(nx, ny);
            }
        }
        debug(used);
    }

    cout << used[h-1][w-1] << endl;
}