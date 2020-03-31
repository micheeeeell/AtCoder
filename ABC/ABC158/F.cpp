#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define rrep(i,x) for(ll i = (ll)(x)-1;0 <= i; i--)
#define reps(i,x) for(ll i = 1; i < (ll)(x)+1; i++)
#define rreps(i,x) for(ll i = (ll)(x); 1 <= i; i--)
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
    // constexpr i64 &value() const noexcept {return a;}
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

const ll MOD = 998244353;
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


// nはサイズ，fはfunction, M1はMonoidの単位元
// SegmentTree(n, f, M1):= サイズ n の初期化。
// ここで f は2つの区間の要素をマージする二項演算, M1 はモノイドの単位元である。
// set(k, x):= k 番目の要素に x を代入する。
// build():= セグメント木を構築する。
// query(a, b):= 区間 [a,b) に対して二項演算した結果を返す。
// update(k, x):= k 番目の要素を x に変更する。
// operator[k] := k 番目の要素を返す。
// find_first(a, check) := [a,x) が check を満たす最初の要素位置 x を返す。
// find_last(b, check) := [x,b) が check を満たす最後の要素位置 x を返す。
template< typename Monoid >
struct SegmentTree {
    using F = function< Monoid(Monoid, Monoid) >;

    int sz;
    vector< Monoid > seg;

    const F f;
    const Monoid M1;
    SegmentTree(vector< Monoid > &vec, const F f, const Monoid &M1) : f(f), M1(M1) {
        int n = vec.size();
        sz = 1;
        while(sz < n)sz <<= 1;
        seg.assign(2*sz, M1);
    }

    void set(int k, const Monoid &x) {
        seg[k + sz] = x;
    }

    void build(vector< Monoid > &vec) {
        for(int i = 0; i < vec.size(); i++)set(i, vec[i]);
        for(int k = sz - 1; k > 0; k--) {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }

    void update(int k, const Monoid &x) {
        k += sz;
        seg[k] = x;
        while(k >>= 1) {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }

    Monoid query(int a, int b) {
        Monoid L = M1, R = M1;
        for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if(a & 1) L = f(L, seg[a++]);
            if(b & 1) R = f(seg[--b], R);
        }
        return f(L, R);
    }

    Monoid operator[] (const int &k) const {
        return seg[k + sz];
    }

    template< typename C >
    int find_subtree(int a, const C &check, Monoid &M, bool type) {
        while(a < sz) {
            Monoid nxt = type ? f(seg[2 * a + type], M) : f(M, seg[2 * a + type]);
            if(check(nxt)) a = 2 * a + type;
            else M = nxt, a = 2 * a + 1 - type;
        }
        return a - sz;
    }

    template< typename C >
    int find_first(int a, const C &check) {
        Monoid L = M1;
        if(a <= 0) {
            if(check(f(L, seg[1]))) return find_subtree(1, check, L, false);
            return -1;
        }
        int b = sz;
        for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if(a & 1) {
                Monoid nxt = f(L, seg[a]);
                if(check(nxt)) return find_subtree(a, check, L, false);
                L = nxt;
                ++a;
            }
        }
        return -1;
    }

    template< typename C >
    int find_last(int b, const C &check) {
        Monoid R = M1;
        if(b >= sz) {
            if(check(f(seg[1], R))) return find_subtree(1, check, R, true);
            return -1;
        }
        int a = sz;
        for(b += sz; a < b; a >>= 1, b >>= 1) {
            if(b & 1){
                Monoid nxt = f(seg[--b], R);
                if(check(nxt)) return find_subtree(b, check, R, true);
                R = nxt;
            }
        }
        return -1;
    }
};


int main(){
    ll n; cin >> n;
    vector<Pll> vec(n);
    rep(i,n){
        ll x,d; cin >> x >> d;
        vec[i] = {x, d};
    }
    sort(all(vec));
    unordered_map<ll, ll> mp;
    rep(i,n){
        mp[vec[i].first] = i;
    }

    auto bound = [&](ll x){
        ll ok = -1, ng = n;
        while(abs(ok - ng) > 1){
            ll id = (ok + ng) / 2;
            if(vec[id].first < x)ok = id;
            else ng = id;
        }

        return ok;
    };

    vector<ll> r(n, 0);
    std::iota(all(r), 0);
    auto f = [](auto const &a, auto const &b){return max(a,b);};
    SegmentTree<ll> seg(r, f, 0);
    seg.build(r);
    rrep(i,n){
        ll right = bound(vec[i].first + vec[i].second);
        // right = max(right, i);
        seg.update(i, seg.query(i, right + 1));
    }

    // rep(i,n)cout << seg[i] << " ";
    // cout << endl;

    vector<mint> count(n+1, 0);
    count[n] = 1;
    rrep(i,n){
        if(seg[i] == i)count[i] = count[i+1] * 2;
        else{
            count[i] = count[i+1] + count[seg[i] + 1];
        }
    }

    cout << count[0] << endl;
}