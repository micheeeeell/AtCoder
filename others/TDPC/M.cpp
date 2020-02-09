#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define pb push_back
#define eb emplace_back
#define debug(x) cerr << #x << ": " << (x) << "\n";
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
const ll INF = numeric_limits<ll>::max()/4;
const int n_max = 1e5+10;

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
    constexpr i64 &value() const noexcept {return a;}
    // constexpr const i64 &value() const noexcept {return a;}
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
    constexpr modint operator++(int) {
        modint tmp(*this);
        operator++();
        return tmp;
    }
    constexpr modint& operator--() noexcept {
        return (*this) -= modint(1);
    }
    constexpr modint operator--(int) {
        modint tmp(*this);
        operator--();
        return tmp;
    }
    template<typename T>
    friend constexpr modint modpow(modint &mt, T n) noexcept {
        if(n < 0){
            modint t = (modint(1) / mt);
            return modpow(t, -n);
        }
        modint res = 1;
        while(n){
            if(n & 1)res *= mt;
            mt *= mt;
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

void print() {
    cout << endl;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
    cout << head;
    if (sizeof...(tail) != 0) cout << ' ';
    print(forward<Tail>(tail)...);
}

template <class T>
void print(vector<T> &vec) {
    for (auto& a : vec) {
        cout << a;
        if (&a != &vec.back()) cout << ' ';
    }
    cout << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
    for (auto& vec : df) {
        print(vec);
    }
}

template<class T, class U>
void print(pair<T,U> &p){
    print(p.first, p.second);
}


int main(){
    ll h,r; cin >> h >> r;
    vector<vector<ll>> g(r, vector<ll>(r));
    rep(i,r)rep(j,r)cin >> g[i][j];
    vvvl dp((1 << r),vvl(r, vl(r, 0)) );
    mat a(r, vector<mint>(r, 0));

    rep(i,r)dp[1 << i][i][i] = 1;

    rep(mask, 1 << r){
        rep(start, r){
            rep(now, r){
                rep(next,r){
                    if(g[now][next] == 0 || (mask >> next) & 1)continue;
                    dp[mask | (1 << next)][start][next] += dp[mask][start][now];
                }
                a[now][start] += mint(dp[mask][start][now]);
            }
        }
    }

    // print(dp[(1 << r)-1]);

    mat b_h(1, vector<mint>(r,0));
    b_h[0][0] = 1;
    mat ans = pow(a, h);
    ans = mul(ans, b_h);
    cout << ans[0][0] << endl;
}