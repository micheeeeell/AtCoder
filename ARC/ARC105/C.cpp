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
    ll n,m; cin >> n >> m;
    vector<ll> w(n);
    for(int i = 0; i < n; i++) cin >> w[i];
    vector<Pll> lv(m);
    for(auto &[l, v] : lv){
        cin >> l >> v;
    }

    rep(i,0,n){
        bool ok = true;
        for (auto [l, v] : lv) {
            ok &= v >= w[i];
        }
        if(!ok){
            cout << -1 << endl;
            return 0;
        }
    }

    map<ll, ll> mp;
    rep(i,0,1LL << n){
        ll tmp = 0;
        rep(j,0,n){
            if((i >> j) & 1){
                tmp += w[j];
            }
        }
        if (mp.count(tmp)) continue;
        ll len = 0;
        rep(j,0,m){
            auto [l, v] = lv[j];
            if (tmp > v) chmax(len, l);
        }
        mp[tmp] = len;
    }

    vector<ll> v(n);
    iota(all(v), 0);
    ll ans = INF;
    do {
        vector<ll> pos(n);
        rep(i,0,n){
            ll tmp = w[v[i]];
            ll tpos = pos[i];
            rep(j, i + 1, n) {
                tmp += w[v[j]];
                ll len = mp[tmp] + tpos;
                if(chmax(pos[j], len)){
                    rep(k, j, n) chmax(pos[k], pos[k - 1]);
                }
            }
        }
        // debug(v, pos);
        chmin(ans, pos.back() - pos[0]);
    } while (next_permutation(all(v)));

    cout << ans << endl;
}