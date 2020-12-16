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
const long double pi = 3.14159265358979323846;
const long double eps = 1e-12;

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
    ll n; cin >> n;

    using L = pair<Pll, Pll>;
    vector<L> v(n);
    vector<pair<ld, ld>> at(n);
    rep(i, 0, n) {
        auto &[x1, y1] = v[i].first;
        auto &[x2, y2] = v[i].second;
        cin >> x1 >> y1 >> x2 >> y2;
        at[i] = {atan2(y1, x1), atan2(y2, x2)};
        if(abs(at[i].first - at[i].second) > pi){
            if (at[i].first < at[i].second) swap(at[i].first, at[i].second);
            at[i].first -= 2 * pi;
        }
        else{
            if (at[i].first > at[i].second) swap(at[i].first, at[i].second);
        }
    }
    sort(all(v), [](auto const a, auto const b) {
        return atan2(a.second.second, a.second.first) <
               atan2(b.second.second, b.second.first);
    });
    sort(all(at),
         [](const auto a, const auto b) { return a.second < b.second; });
    {
        auto t = v;
        copy(all(t), back_inserter(v));
        auto tt = at;
        rep(i,0,n){
            tt[i].first += 2 * pi;
            tt[i].second += 2 * pi;
        }
        copy(all(tt), back_inserter(at));
    }
    debug(v, at);

    ll ans = INF;
    rep(i, 0, n) {
        ld last = -INF;
        ll tmp = 0;
        rep(j, i, n + i) {
            if(last < at[j].first){
                tmp++;
                last = at[j].second;
            }
        }
        debug(i, tmp);
        chmin(ans, tmp);
    }

    cout << ans << endl;
}