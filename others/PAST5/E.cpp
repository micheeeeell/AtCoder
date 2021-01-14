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
    ll h,w; cin >> h >> w;
    vector<string> s(h), t(h);
    rep(i, 0, h) cin >> s[i];
    rep(i, 0, h) cin >> t[i];
    ll xmin = INF, xmax = 0;
    rep(i, 0, h) {
        bool used = false;
        rep(j, 0, w) used |= t[i][j] == '#';
        if(used){
            chmin(xmin, i);
            chmax(xmax, i);
        }
    }
    ll ymin = INF, ymax = 0;
    rep(j,0,w){
        bool used = false;
        rep(i, 0, h) used |= t[i][j] == '#';
        if(used){
            chmin(ymin, j);
            chmax(ymax, j);
        }
    }

    vector<string> td;
    rep(i,xmin, xmax + 1){
        td.emplace_back(t[i].substr(ymin, ymax - ymin + 1));
    }
    debug(td);

    auto rot = [](vector<string> d) {
        ll H = d.size();
        ll W = d[0].size();

        vector<string> res(W, string(H, '.'));
        rep(j,0,W){
            rrep(i, H, 0){
                if(d[i][j] == '#'){
                    res[j][H - i - 1] = '#';
                }
            }
        }
        return res;
    };

    debug(rot(td));

    auto check = [&](vector<string> d) {
        bool res = false;
        ll H = d.size();
        ll W = d[0].size();
        rep(i,0,h){
            if (i + H > h) break;
            rep(j, 0, w) {
                if (j + W > w) break;
                bool tmp = true;
                rep(ii, 0, H) rep(jj, 0, W) {
                    tmp &= d[ii][jj] != s[i + ii][j + jj] || d[ii][jj] == '.';
                }
                res |= tmp;
            }
        }
        return res;
    };

    bool ok = false;
    rep(_,0,4){
        ok |= check(td);
        if (check(td)) debug(td);
        td = rot(td);
    }

    cout << (ok ? "Yes" : "No") << endl;
}