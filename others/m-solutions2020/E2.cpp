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


void print() {
    cout << endl;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
    cout << head;
    if (sizeof...(tail) != 0) cout << " ";
    print(forward<Tail>(tail)...);
}

template <class T>
void print(vector<T> &vec) {
    for (auto& a : vec) {
        cout << a;
        if (&a != &vec.back()) cout << "\n";
    }
    cout << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
    for (auto& vec : df) {
        print(vec);
    }
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    vector<tuple<ll, ll, ll>> v(n);
    rep(i,0,n){
        auto &[x,y,p] = v[i];
        cin >> x >> y >> p;
    }
    vector<ll> t(n);
    rep(i,0,n){
        auto &[x, y, p] = v[i];
        t[i] = min(abs(x), abs(y));
    }

    vector rdp(1LL << n, vector(n, 0LL)), cdp(1LL << n, vector(n, 0LL));
    rdp[0] = cdp[0] = t;
    rep(mask,0,1LL << n){
        vector<ll> rtmp = t, ctmp = t;
        rep(i,0,n){
            auto &[x,y,p] = v[i];
            rep(j,0,n){
                auto &[xx, yy, pp] = v[j];
                if((mask >> j) & 1)chmin(ctmp[i], abs(x - xx));
                if((mask >> j) & 1)chmin(rtmp[i], abs(y - yy));
            }
        }
        rdp[mask] = rtmp;
        cdp[mask] = ctmp;
    }
    vector<ll> ans(n+1, INF);
    rep(i,0,pow(3, n)){
        ll t = i;
        ll rmask = 0, cmask = 0;
        rep(j,0,n){
            if(t % 3 == 1)rmask |= (1LL << j);
            if(t % 3 == 2)cmask |= (1LL << j);
            t /= 3;
        }
        vector<ll> tv(n);
        rep(j,0,n){
            tv[j] = min(rdp[rmask][j], cdp[cmask][j]);
        }
        ll num = __builtin_popcountll(rmask) + __builtin_popcountll(cmask);
        ll score = 0;
        rep(j,0,n){
            score += get<2>(v[j]) * tv[j];
        }
        chmin(ans[num], score);
    }

    print(ans);
}