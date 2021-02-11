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

vector<ll> Manacher(string &s) {
    int i = 0, j = 0;
    vector<ll> R(s.size());
    while (i < s.size()) {
        while (i - j >= 0 && i + j < s.size() && s[i - j] == s[i + j]) ++j;
        R[i] = j;
        int k = 1;
        while (i - k >= 0 && i + k < s.size() && k + R[i - k] < j)
            R[i + k] = R[i - k], ++k;
        i += k;
        j -= k;
    }
    return R;
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,k; cin >> n >> k;
    if(n < 10){
        rep(i, 0, 1LL << n){
            string s;
            rep(j, 0, n){
                if((i >> j) & 1){
                    s += '1';
                }
                else
                    s += '0';
                s += '$';
            }
            s.pop_back();
            auto r = Manacher(s);
            debug(s, r);

            ll t = 0;
            rep(i,0,2 * n - 1){
                if(i & 1){
                    chmax(t, r[i]);
                }
                else{
                    if (~r[i] & 1) r[i]--;
                    chmax(t, r[i]);
                }
            }
            if (t == k) {
                string st;
                rep(j, 0, n) st += s[j * 2];
                cout << st << endl;
                return 0;
            }
        }
        cout << -1 << endl;
        return 0;
    }

    if(k < 4){
        cout << -1 << endl;
        return 0;
    }
    string s = string(k, '1');
    while(s.size() < n){
        s += "010011";
    }
    cout << s.substr(0, n) << endl;
}