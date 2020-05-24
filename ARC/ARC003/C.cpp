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
constexpr ll n_max = 3e5+10;
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
    ll n,m; cin >> n >> m;
    string s[n];
    rep(i,n)cin >> s[i];
    using vld = vector< long double > ;
    using vvld = vector< vld >;
    vvl table(n, vl(m));
    Pll st, go;
    rep(i,n)rep(j,m){
        if(s[i][j] == 's'){
            st = {i, j};
            continue;
        }
        if(s[i][j] == 'g'){
            go = {i, j};
            table[i][j] = INF;
            continue;
        }
        if(s[i][j] == '#')continue;
        ld t = s[i][j] - '0';
        table[i][j] = t;
    }
    ll dx[] = {0,0,1,-1};
    ll dy[] = {1,-1,0,0};
    auto is_out = [&](ll x, ll y){
       if(x < 0 || x >= n || y < 0 || y >= m)return true;
       return false;
    };

    vvld pow_(9, vld(n_max));
    rep(i,9)pow_[i][0] = ld(i+1);
    rep(i,9){
        reps(j,n_max-1){
            pow_[i][j] = pow_[i][j-1] * 0.99;
        }
    }

    auto goal = [&](){
        using state = pair<Pll, ll>;
        queue<state> que;
        que.emplace(st, 0);
        vvl used(n, vl(m));
        used[st.first][st.second] = 1;

        while(!que.empty()){
            auto p = que.front();que.pop();
            ll x = p.first.first;
            ll y = p.first.second;
            ll t = p.second;
            rep(i,4){
                ll nx = x + dx[i];
                ll ny = y + dy[i];
                // debug(nx, ny);
                if(Pll(nx, ny) == go)return true;
                if(is_out(nx, ny))continue;
                if(used[nx][ny])continue;
                if(table[nx][ny] == 0)continue;
                que.emplace(Pll(nx, ny), t + 1);
                used[nx][ny] = 1;
            }
        }

        return false;
    };
    auto c = [&](ld k){
        using state = pair<Pll, ll>;
        queue<state> que;
        que.emplace(st, 0);
        vvl used(n, vl(m));
        used[st.first][st.second] = 1;

        while(!que.empty()){
            auto p = que.front();que.pop();
            ll x = p.first.first;
            ll y = p.first.second;
            ll t = p.second;
            // debug(k, x, y, t);
            rep(i,4){
                ll nx = x + dx[i];
                ll ny = y + dy[i];
                // debug(nx, ny);
                if(Pll(nx, ny) == go)return true;
                if(is_out(nx, ny))continue;
                if(used[nx][ny])continue;
                if(table[nx][ny] == 0)continue;
                if(pow_[table[nx][ny]-1][t+1] < k)continue;
                que.emplace(Pll(nx, ny), t + 1);
                used[nx][ny] = 1;
            }
        }

        return false;
    };

    if(!goal()){
        cout << -1 << endl;
        return 0;
    }
    ld ok = 0.0;
    ld ng = 10.0;
    rep(i,100){
        ld x = (ok + ng) / 2.0;
        if(c(x))ok = x;
        else ng = x;
    }
    cout << fixed << setprecision(15);
    cout << ok << endl;
}