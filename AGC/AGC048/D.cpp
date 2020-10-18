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
    ll q; cin >> q;
    while(q--){
        ll n; cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        vector<vector<int>> flag(n + 1, vector<int>(n + 1));
        vector<vector<int>> memo(n + 1, vector<int>(n + 1));
        auto solve = [&](auto self, ll l, ll r, ll turn) {
            if(flag[l][r]){
                return memo[l][r] > 0;
            }
            if(l == r - 1){
                flag[l][r] = 1;
                memo[l][r] = (turn % 2 == 0);
                return turn % 2 == 0;
            }

            if(l == r - 2){
                flag[l][r] = 1;
                memo[l][r] =
                    a[l] > a[r - 1] || (a[l] == a[r - 1] && turn % 2 == 0);
                return a[l] > a[r - 1] || (a[l] == a[r - 1] && turn % 2 == 0);
            }

            bool res = (turn & 1) ? true : false;
            if (~turn & 1) {
                if (a[l] > a[r - 1]){
                    res |= self(self, l + 1, r, turn + 1);
                    a[l] -= a[r];
                    res |= self(self, l, r - 1, turn);
                }
                else if(a[l] == a[r-1]){
                    res |= self(self, l + 1, r, turn + 1);
                    res |= self(self, l + 1, r - 1, turn + 1);
                }
                else{
                    res |= self(self, l + 1, r, turn + 1);
                }
            }
            else{
                if(a[l] < a[r - 1]){
                    res &= self(self, l, r - 1, turn + 1);
                    a[r - 1] -= a[l];
                    res &= self(self, l + 1, r, turn);
                } else if (a[l] == a[r - 1]){
                    res &= self(self, l, r - 1, turn + 1);
                    res &= self(self, l + 1, r - 1, turn + 1);
                }
                else{
                    res &= self(self, l, r - 1, turn + 1);
                }
            }

            flag[l][r] = 1;
            memo[l][r] = res;
            return res;
        };

        cout << (solve(solve, 0, n, 0) ? "First"
                                      : "Second")
                                            << "\n";
    }
}