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

vvl solve(ll n, ll k, vvl &a){
    rep(i, 0, n) rep(j, 0, k) a[i][j]--;

    auto check = [&](ll i, ll x) -> pair<bool, vector<ll>> {
        vector<ll> used(n_max);
        vector<ll> res;
        ll cnt = 0;
        rep(ii, 0, i) {
            rep(j, 0, x) {
                if (!used[a[ii][j]]) {
                    cnt++;
                    used[a[ii][j]] = 1;
                    res.emplace_back(a[ii][j]);
                }
            }
        }

        cnt += (n - i) * x;
        bool ok = cnt <= k;
        if (ok && x < k) {
            rep(ii, 0, i) {
                if (cnt >= k) break;
                if (!used[a[ii][x]]) {
                    cnt++;
                    used[a[ii][x]];
                    res.emplace_back(a[ii][x]);
                }
            }
        }

        return {ok, res};
    };

    vector<ll> used(n_max);
    vvl res;

    rep(i, 0, n) {
        ll ok = 0, ng = k + 1;
        while (abs(ok - ng) > 1) {
            ll x = (ok + ng) / 2;
            if (check(i + 1, x).first)
                ok = x;
            else
                ng = x;
        }

        vector<ll> tmp = check(i + 1, ok).second;
        // debug(i, ok, tmp);
        vector<ll> ans;
        for (auto j : tmp) {
            if (!used[j]) {
                ans.emplace_back(j + 1);
                used[j] = 1;
            }
        }
        sort(all(ans));
        res.emplace_back(ans);
    }
    debug(res);
    return res;
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    random_device rnd;
    mt19937_64 mt(rnd());
    rep(_, 0, 10) {
        ll n = mt() % 10 + 1;
        ll k = mt() % 10 + 1;
        vvl a(n, vl(k));
        rep(i,0,n)rep(j,0,k){
            a[i][j] = mt() % 20 + 1;
        }
        debug(n, k, a);
        auto res = solve(n, k, a);
    }
}