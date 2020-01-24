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
        i64 exp = Modulus - 2;
        while(exp) {
            if(exp & 1) {
                *this *= rhs;
            }
            rhs *= rhs;
            exp /= 2;
        }
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

void print(vector< mint > & vec) {
    for(auto i : vec)cout << i << " ";
    cout << "\n";
}

int main(){
    ll d; cin >> d;
    string s;cin >> s;
    ll n = s.size();
    vector <vector< vector <mint>>> dp(2, vector<vector< mint >> (2, vector<mint>(d,0)));
    vector <vector< mint >> clear(2,vector<mint>(d,0));
    dp[0][0][0] = 1;
    rep(i,n){
        ll t = s[i] - '0';
        rep(k, d){
            rep(small, 2){
                rep(j, (small ? 10 : t)){
                    dp[(i+1) & 1][1][(k + j) % d] += dp[i & 1][small][k];
                }
            }
            dp[(i+1) & 1][0][(k + t) % d] += dp[i & 1][0][k];
        }
        // print(dp[(i+1) & 1][0]);
        // print(dp[(i+1) & 1][1]);
        // cout << endl;

        dp[i & 1] = clear;
    }

    cout << mint(dp[n & 1][0][0] + dp[n & 1][1][0]) - mint(1) << endl;
}