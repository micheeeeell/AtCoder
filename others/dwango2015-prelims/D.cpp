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
    ll n,L; cin >> n >> L;
    vector<Pll> v(n);
    rep(i,0,n){
        ll a,b,c; cin >> a >> b >> c;
        v[i] = {a, b - c};
    }
    vector<Pll> l, r, m;
    ll cnt = 0;
    ll res = 0;
    ll lsum = 0, rsum = 0;
    rep(i, 0, n) {
        cnt += v[i].second;
        ll d = v[(i + 1) % n].first - v[i].first;
        if (d < 0) d += L;
        if(cnt > 0){
            r.emplace_back(Pll{cnt, d});
            rsum += d;
            res += cnt * d;
        }
        else if(cnt < 0){
            l.emplace_back(Pll{abs(cnt), d});
            lsum += d;
            res += abs(cnt) * d;
        }
    }

    sort(all(r), greater<Pll>());
    sort(all(l), greater<Pll>());

    debug(res, l, r, lsum, rsum);

    ll t = 0;
    if(lsum > (L - lsum)){
        while (lsum > (L - lsum)) {
            auto p = l.back();
            p.first -= t;
            res -= p.first * lsum;
            res += p.first * (L - lsum);
            t += p.first;
            while (!l.empty()) {
                auto p = l.back();
                if (p.first > t) break;
                lsum -= p.second;
                l.pop_back();
            }
            debug(lsum, t);
        }
        debug(l);
    } else if (rsum > (L - rsum)) {
        while (rsum > (L - rsum)) {
            auto p = r.back();
            res -= p.first * rsum;
            res += p.first * (L - rsum);
            t += p.first;
            while(!r.empty()){
                auto p = r.back();
                if (p.first > t) break;
                rsum -= p.second;
                r.pop_back();
            }
        }
    }

    cout << res << endl;

}