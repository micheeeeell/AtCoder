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

void answer(vector<string> &s){
    for(auto &t : s)cout << t << "\n";
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    vector<string> ans(n, string(n, '.'));
    if(n == 2){
        cout << -1 << "\n";
        return 0;
    }
    if(n == 3){
        vector<string> s3 = {
            "aad", "b.d", "bcc"
        };
        answer(s3);
        return 0;
    }
    vector<string> s4 = {
        "aade",
        "bbde",
        "cfgg",
        "cfhh"
    };
    vector<string> s5 = {
        "a.hhj",
        "a.g.j",
        "bbgii",
        "cc.ef",
        ".ddef"
    };
    vector<string> s6 = {
        "aad.ii",
        "b.dj..",
        "bccj..",
        ".kkeeh",
        "l..f.h",
        "l..fgg"
    };
    vector<string> s7 = {
        "a.jj.dd",
        "ae..hh.",
        ".e.ll.m",
        "n.i...m",
        "n.i..g.",
        ".ff..gc",
        "bb.kk.c"
    };

    ll t = n % 4;
    n -= t + 4;
    for(int i = 0; i < n; i += 4){
        rep(ii,0,4)rep(jj,0,4){
            ans[i + ii][i + jj] = s4[ii][jj];
        }
    }
    if(t == 0){
        rep(i,0,4)rep(j,0,4){
            ans[n+i][n+j] = s4[i][j];
        }
    }
    if(t == 1){
        rep(i,0,5)rep(j,0,5){
            ans[n+i][n+j] = s5[i][j];
        }
    }
    if(t == 2){
        rep(i,0,6)rep(j,0,6){
            ans[n+i][n+j] = s6[i][j];
        }
    }
    if(t == 3){
        rep(i,0,7)rep(j,0,7){
            ans[n+i][n+j] = s7[i][j];
        }
    }

    answer(ans);
}