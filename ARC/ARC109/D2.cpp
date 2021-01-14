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
    
    ll t; cin >> t;
    auto solve = [](ll x, ll y) {
        ll xq = x / 3;
        ll yq = y / 3;
        ll xr = x % 3;
        ll yr = y % 3;
        if (xr < 0) {
            xq--;
            xr += 3;
        }
        if (yr < 0) {
            yq--;
            yr += 3;
        }
        if (xq == yq) {
            if (xq > 0) {
                if (xr == yr && xr == 2) {
                    return xq * 2 + 2;
                } else {
                    return xq * 2 + 1;
                }
            } else if(xq < 0) {
                if (xr == yr && xr == 1) {
                    return abs(xq) * 2 + 1;
                }
                else{
                    return abs(xq) * 2;
                }
            }
            else{
                if (xr == yr && xr == 1) {
                    return abs(xq) * 2;
                } else {
                    return abs(xq) * 2 + 1;
                }
            }
        }

        if(xq > yq){
            if(xq >= abs(yq)){
                if(xr == 1){
                    return xq * 2;
                }
                else
                    return xq * 2 + 1;
            }
            else{
                if (yr == 2) return abs(yq) * 2 - 1;
                else
                    return abs(yq) * 2;
            }
        }
        else{
            if(yq >= abs(xq)){
                if (yr == 1) return yq * 2;
                else
                    return yq * 2 + 1;
            }
            else{
                if (xr == 2) return abs(xq) * 2 - 1;
                else
                    return abs(xq) * 2;
            }
        }
    };

    // vector<string> v(21, string(21, '.'));
    // rep(i,-10, 11)rep(j,-10,11){
    //     if (i % 3 == 0 || j % 3 == 0) continue;
    //     v[i + 10][j + 10] = '0' + solve(i, j);
    //     debug(i, j, solve(i, j));
    // }

    // print(v);
    rep(_, 0, t) {
        ll x,y; cin >> x >> y;
        ll a,b; cin >> a >> b;
        x += a;
        y += b;
        cin >> a >> b;
        x += a;
        y += b;
        debug(x, y);

        cout << solve(x, y) << "\n";
    }
}