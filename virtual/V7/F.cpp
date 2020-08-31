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
constexpr ll n_max = 5e3+10;
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
    ll n; cin >> n;
    vector<ll> a(3);
    for(int i = 0; i < 3; i++) cin >> a[i];
    vector<ll> b(3);
    for(int i = 0; i < 3; i++) cin >> b[i];

    auto calc = [&](ll x, vector<ll> &f, vector<ll> &t){
        ll res = 0;
        ll sum = 0, re = 0, k, temp, temp2;
        rep(i,0,n_max){
            if(i * f[0] > x)break;
            rep(j,0,n_max){
                sum = i * f[0] + j * f[1];
                if(sum > x)break;
                re = x - sum;
                k = re / f[2];
                temp = i * t[0] + j * t[1] + k * t[2] + re % f[2];
                temp2 = i * t[0] + j * t[1] + re;
                debug(i,j,k,temp, temp2);
                chmax(res, temp);
                chmax(res, temp2);
            }
        }
        return res;
    };

    n = calc(n, a, b);
    debug(n);
    n = calc(n, b, a);
    cout << n << "\n";
}