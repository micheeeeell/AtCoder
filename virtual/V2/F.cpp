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

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,A,B; cin >> n >> A >> B;
    vector<tuple<ll, ll, ll> > av(n / 2), bv(n - n / 2);
    for(auto &[a, b, c] : av) {
        cin >> a >> b >> c;
    }
    for(auto &[a, b, c] : bv) {
        cin >> a >> b >> c;
    }
    map<Pll, ll> ma, mb;
    ll na = n / 2, nb = n - na;
    ll ans = INF;
    rep(i, 0, 1LL << na) {
        ll at = 0, bt = 0, ct = 0;
        rep(j, 0, na) {
            if((i >> j) & 1) {
                auto &[a, b, c] = av[j];
                at += a;
                bt += b;
                ct += c;
            }
        }
        if(!ma.count({at, bt})) ma[{at, bt}] = ct;
        else{
            chmin(ma[{at, bt}], ct);
        }
    }
    rep(i, 0, 1LL << nb) {
        ll at = 0, bt = 0, ct = 0;
        rep(j, 0, nb) {
            if((i >> j) & 1) {
                auto &[a, b, c] = bv[j];
                at += a;
                bt += b;
                ct += c;
            }
        }
        if(!mb.count({at, bt}))
            mb[{at, bt}] = ct;
        else {
            chmin(mb[{at, bt}], ct);
        }
    }

    for(auto &p : ma) {
        auto &[a, b] = p.first;
        debug(p);
        for(ll s = A; s < 410; s += A) {
            ll t = B * (s / A);
            if(s < a || t < b) continue;
            if(mb.count({s - a, t - b})) {
                chmin(ans, p.second + mb[{s - a, t - b}]);
            }
        }
    }


    cout << (ans != INF ? ans : -1) << "\n";
}