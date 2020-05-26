// #define LOCAL
#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include<bits/stdc++.h>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define rrep(i,x) for(ll i = (ll)(x)-1;0 <= i; i--)
#define reps(i,x) for(ll i = 1; i < (ll)(x)+1; i++)
#define rreps(i,x) for(ll i = (ll)(x); 1 <= i; i--)
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
string to_string(const char c) {return to_string((string) &c);}
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
};

const ll MOD = 1e9+7;
using mint = modint<MOD>;
// 標準入出力対応
std::ostream &operator<<(std::ostream &out, const modint<MOD> &m) {
    out << m.a;
    return out;
}
std::istream &operator>>(std::istream &in, modint<MOD> &m) {
    ll a;
    in >> a;
    m = mint(a);
    return in;
}


string to_string(mint m){
    return to_string(m.a);
}
using vm = vector<mint>;
using vvm = vector<vm>;
using vvvm = vector<vvm>;

using vmi = vector< mint >;
using mat = vector< vmi >;

mat mul(mat &a, mat &b){
    mat c(a.size(), vector<mint>(b[0].size()));
    rep(i,a.size()){
        rep(k,b.size()){
            rep(j,b[0].size()){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

mat pow(mat &a, ll n){
    mat b(a.size(), vector<mint>(a.size()));
    rep(i,a.size())b[i][i] = 1;
    while(n > 0){
        if(n & 1)b = mul(b,a);
        a = mul(a,a);
        n >>= 1;
    }
    return b;
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll h,r; cin >> h >> r;
    vector<vector<ll>> t(r, vector<ll>(r));
    rep(i,r)rep(j,r)cin >> t[i][j];
    vvvm dp((1LL << r), vvm(r, vm(r)));
    rep(i,r){
        dp[(1LL << i)][i][i] = 1;
    }
    mat m(r, vmi(r));

    reps(mask, (1LL << r) - 1){
        rep(i,r)rep(j,r){
            rep(k,r){
                if((mask >> k) & 1)continue;
                if(t[j][k] == 0)continue;
                dp[(mask | (1LL << k))][i][k] += dp[mask][i][j];
            }
            m[j][i] += dp[mask][i][j];
        }
        debug(mask, dp[mask]);
    }

    debug(m);
    mat v(r, vmi(1));
    v[0][0] = 1;
    m = pow(m, h);
    debug(m);
    v = mul(m, v);

    cout << v[0][0] << endl;
}