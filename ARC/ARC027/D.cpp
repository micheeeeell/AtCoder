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
template<std::int_fast64_t Modulus>
class modint {
    using i64 = int_fast64_t;

    public:
    i64 a;

    constexpr modint(const i64 x = 0) noexcept {
        this -> a = x % Modulus;
        if(a < 0){
            a += Modulus;
        }
    }
    constexpr int getmod() { return Modulus; }
    constexpr modint operator - () const noexcept {
        return a ? Modulus - a : 0;
    }
    constexpr const i64 &value() const noexcept {return a;}
    constexpr modint operator+(const modint rhs) const noexcept {
        return modint(*this) += rhs;
    }
    constexpr modint operator-(const modint rhs) const noexcept {
        return modint(*this) -= rhs;
    }
    constexpr modint operator*(const modint rhs) const noexcept {
        return modint(*this) *= rhs;
    }
    constexpr modint operator/(const modint rhs) const noexcept {
        return modint(*this) /= rhs;
    }
    constexpr modint &operator+=(const modint rhs) noexcept {
        a += rhs.a;
        if(a >= Modulus) {
            a -= Modulus;
        }
        return *this;
    }
    constexpr modint &operator-=(const modint rhs) noexcept {
        if(a < rhs.a) {
            a += Modulus;
        }
        a -= rhs.a;
        return *this;
    }
    constexpr modint &operator*=(const modint rhs) noexcept {
        a = a * rhs.a % Modulus;
        return *this;
    }
    constexpr modint &operator/=(modint rhs) noexcept {
        i64 a_ = rhs.a, b = Modulus, u = 1, v = 0;
        while(b){
            i64 t = a_/b;
            a_ -= t * b; swap(a_,b);
            u -= t * v; swap(u,v);
        }
        a = a * u % Modulus;
        if(a < 0) a += Modulus;
        return *this;
    }
    
    // 自前実装
    constexpr bool operator==(const modint rhs) noexcept {
        return a == rhs.a;
    }
    constexpr bool operator!=(const modint rhs) noexcept {
        return a != rhs.a;
    }
    constexpr bool operator>(const modint rhs) noexcept {
        return a > rhs.a;
    }
    constexpr bool operator>=(const modint rhs) noexcept {
        return a >= rhs.a;
    }
    constexpr bool operator<(const modint rhs) noexcept {
        return a < rhs.a;
    }
    constexpr bool operator<=(const modint rhs) noexcept {
        return a <= rhs.a;
    }
    constexpr modint& operator++() noexcept {
        return (*this) += modint(1);
    }
    // constexpr modint operator++(int) {
    //     modint tmp(*this);
    //     operator++();
    //     return tmp;
    // }
    constexpr modint& operator--() noexcept {
        return (*this) -= modint(1);
    }
    // constexpr modint operator--(int) {
    //     modint tmp(*this);
    //     operator--();
    //     return tmp;
    // }
    template<typename T>
    friend constexpr modint modpow(const modint &mt, T n) noexcept {
        if(n < 0){
            modint t = (modint(1) / mt);
            return modpow(t, -n);
        }
        modint res = 1, tmp = mt;
        while(n){
            if(n & 1)res *= tmp;
            tmp *= tmp;
            n /= 2;
        }
        return res;
    }

    friend constexpr string to_string(const modint &mt) noexcept {
        return to_string(mt.a);
    }
};

// 標準入出力対応
template<std::int_fast64_t Modulus>
std::ostream &operator<<(std::ostream &out, const modint<Modulus> &m) {
    out << m.a;
    return out;
}
template<std::int_fast64_t Modulus>
std::istream &operator>>(std::istream &in, modint<Modulus> &m) {
    ll a;
    in >> a;
    m = modint<Modulus>(a);
    return in;
}

const ll MOD = 1e9+7;
// const ll MOD = 998244353;
using mint = modint<MOD>;

template<typename T, typename U>
mint modpow(const T t, U n){return modpow(mint(t), n);}

vector<mint> solve(ll n, vector<ll> &h, ll d, vector<ll> &s, vector<ll> &t) {
    vector<mint> res(d);
    ll m = sqrt(n);
    debug(n, m);

    if (n <= 100) {
        rep(i, 0, d) {
            vector<mint> dp(n);
            dp[s[i]] = 1;
            rep(j, s[i], t[i]) {
                rep(k, 0, h[j]) {
                    if (j + k + 1 < n) dp[j + k + 1] += dp[j];
                }
            }

            res[i] = dp[t[i]];
        }

        return res;
    }
    vector dp(n, vector<mint>(10));
    rep(i, 0, n) {
        if (i % m < 10) {
            rep(j, 0, 10) dp[i][j] = 0;
            dp[i][i % m] = 1;
        }
        rep(k, 0, h[i]) {
            rep(j, 0, 10) {
                if (i + k + 1 < n) dp[i + k + 1][j] += dp[i][j];
            }
        }
    }

    rep(i, 0, d) {
        ll x = s[i], y = t[i];
        vector<mint> tmp(m);
        vector<mint> ten(10);
        tmp[x % m] = 1;
        {
            ll c = x % m;
            rep(j, c, m) {
                if (x + j - c >= n) break;
                rep(k, 0, h[x + j - c]) {
                    if (j + k + 1 < m) tmp[j + k + 1] += tmp[j];
                }
            }
        }

        if (x / m == y / m) {
            // cout << tmp[y % m] << "\n";
            res[i] = tmp[y % m];
            continue;
        }
        debug(tmp);
        debug(x);
        x = m * (x / m + 1) - 10;
        debug(x, m, y);
        while (1) {
            rep(j, 0, 10) ten[j] = 0;
            rrep(j, 10, 0) {
                if (x >= n) break;
                if (h[x] > j) {
                    rep(k, 0, h[x] - j) {
                        ten[k] += tmp[m - j - 1];
                    }
                }
                x++;
            }
            rep(j, 0, 10) {
                if (x + j >= n) break;
                rep(k, 0, h[x + j]) {
                    if (j + k + 1 < 10) ten[j + k + 1] += ten[j];
                }
            }
            debug(ten);

            if (x / m == y / m) {
                mint ans = 0;
                rep(j, 0, 10) ans += dp[y][j] * ten[j];
                // cout << ans << "\n";
                res[i] = ans;
                break;
            }

            x += m - 10;

            rrep(j, 10, 0) {
                // if(x >= n)break;
                tmp[m - j - 1] = 0;
                rep(k, 0, 10) {
                    tmp[m - j - 1] += dp[x][k] * ten[k];
                }
                x++;
            }
            debug(x);
            x -= 10;
        }
    }
    return res;
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    vector<ll> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];
    ll m = sqrt(n);
    ll d; cin >> d;
    vector<ll> s(d), t(d);
    for(int i = 0; i < d; i++) {
        cin >> s[i] >> t[i];
        s[i]--;
        t[i]--;
    }

    auto res = solve(n, h, d, s, t);
    rep(i,0,d){
        cout << res[i] << "\n";
    }
}