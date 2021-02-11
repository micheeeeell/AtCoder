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
constexpr ll INF = numeric_limits<ll>::max()/2;
constexpr ll n_max = 2e5+10;
#define int ll
const long double pi = 3.14159265358979323846;
const long double eps = 1e-12;

template <typename T>
int comp(T a){
    if (abs(a) < eps) return 0;
    return a > 0 ? 1 : -1;
}

template <typename T>
int comp(T a, T b){
    // a > b -> 1, a < b -> -1
    return comp(a - b);
}
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

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    ll d = 1e9 + 10;
    set<ll> xst, yst;
    {
        xst.insert(-d);
        xst.insert(0);
        xst.insert(d);
        yst.insert(-d);
        yst.insert(0);
        yst.insert(d);
    }
    vector<tuple<ll, ll, ll>> xt(m), yt(n);
    map<ll, vector<Pll> > xmp, ymp;
    rep(i, 0, n) {
        ll a,b,c; cin >> a >> b >> c;
        xst.insert(a);
        xst.insert(b);
        yst.insert(c);
        yt[i] = {a, b ,c};
    }
    rep(i,0,m){
        ll d,e,f; cin >> d >> e >> f;
        xst.insert(d);
        yst.insert(e);
        yst.insert(f);
        xt[i] = {d, e, f};
    }

    vector<ll> xv, yv;
    for(auto t : xst)xv.emplace_back(t);
    for(auto t : yst)yv.emplace_back(t);
    debug(xv, yv);
    for (auto [d, e, f] : xt) {
        debug(d, e, f);
        d = lower_bound(all(xv), d) - xv.begin();
        e = lower_bound(all(yv), e) - yv.begin();
        f = lower_bound(all(yv), f) - yv.begin();
        xmp[d].emplace_back(e, f);
        debug(d, e, f);
    }
    for (auto [a, b, c] : yt){
        a = lower_bound(all(xv), a) - xv.begin();
        b = lower_bound(all(xv), b) - xv.begin();
        c = lower_bound(all(yv), c) - yv.begin();
        ymp[c].emplace_back(a, b);
    }
    for(auto &&v : xmp){
        sort(all(v.second));
    }
    for (auto &&v : ymp){
        sort(all(v.second));
    }
    debug(xmp, ymp);
    ll h = xv.size();
    ll w = yv.size();
    ll dx[] = {0, 1, -1, 0, 1, 1, -1, -1};
    ll dy[] = {1, 0, 0, -1, 1, -1, 1, -1};
    auto is_out = [&](ll x, ll y) {
        if (x < 0 || x >= h || y < 0 || y >= w) return true;
        return false;
    };
    auto xid = [&](ll x) { return lower_bound(all(xv), x) - xv.begin(); };
    auto yid = [&](ll y) { return lower_bound(all(yv), y) - yv.begin(); };
    auto area = [&](ll x, ll y) {
        return (xv[x + 1] - xv[x]) * (yv[y + 1] - yv[y]);
    };
    auto border = [&](ll k, ll x, ll y) {
        if (k == 0) {
            if (!ymp.count(y + 1)) return false;
            ll id =
                lower_bound(all(ymp[y + 1]), Pll(x, x)) - ymp[y + 1].begin();
            if (id == ymp[y + 1].size() || ymp[y + 1][id].first > x) {
                id--;
            }

            if (id < 0) return false;
            return (ymp[y + 1][id].first <= x && ymp[y + 1][id].second > x);
        }
        if (k == 1) {
            if (!xmp.count(x + 1)) return false;
            ll id =
                lower_bound(all(xmp[x + 1]), Pll{y, y}) - xmp[x + 1].begin();
            if (id == xmp[x + 1].size() || xmp[x + 1][id].first > y) {
                id--;
            }
            if (id >= 0) debug(x, y, id, xmp[x + 1][id]);
            if (id < 0) return false;
            return (xmp[x + 1][id].first <= y && xmp[x + 1][id].second > y);
        }

        if(k == 2){
            if (!xmp.count(x)) return false;
            ll id = lower_bound(all(xmp[x]), Pll{y, y}) - xmp[x].begin();

            if (id == xmp[x].size() || xmp[x][id].first > y) {
                id--;
            }
            if (id < 0) return false;
            return (xmp[x][id].first <= y && xmp[x][id].second > y);
        }
        if (k == 3) {
            if (!ymp.count(y)) return false;
            ll id = lower_bound(all(ymp[y]), Pll{x, x}) - ymp[y].begin();
            if (id == ymp[y].size() || ymp[y][id].first > x) {
                id--;
            }
            if (id < 0) return false;
            return (ymp[y][id].first <= x && ymp[y][id].second > x);
        }
        return false;
    };

    ll ans = 0;
    vector used(h, vector<ll>(w));
    queue<Pll> que;
    
    {
        ll xz = xid(0);
        ll yz = yid(0);
        assert(xz);
        assert(yz);
        rep(i,0,2)rep(j,0,2){
            que.emplace(xz - i, yz - j);
            used[xz - i][yz - j] = 1;
        }

    }

    while(!que.empty()){
        auto &&[x, y] = que.front();
        ans += area(x, y);
        debug(x, y, xv[x], yv[y]);
        que.pop();

        rep(k,0,4){
            ll nx = x + dx[k];
            ll ny = y + dy[k];
            if(is_out(nx, ny)){
                cout << "INF" << endl;
                exit(0);
            }
            if (used[nx][ny]) continue;
            if (border(k, x, y)) continue;
            que.emplace(nx, ny);
            used[nx][ny] = 1;
        }
    }

    cout << ans << endl;
    return 0;
}