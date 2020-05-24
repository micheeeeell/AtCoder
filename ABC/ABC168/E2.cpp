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


  

signed main(){ 
    ll n; cin >> n;
    map<Pll, ll> mp, mp2;
    ll acnt = 0, bcnt = 0;
    ll cnt = 0;
//   for(ll i = 0;  i < N; i++){ 
//     ll A,B; cin >> A >> B;
//     if(A == 0 && B == 0){
//         zero++;
//         continue;
//     }
//     if(A == 0){
//         azero++;
//         continue;
//     }
//     if(B == 0){
//         bzero++;
//         continue;
//     }
//     ll c = abs(A), d = abs(B);
//     ll g = gcd(c,d);
//     c /= g;
//     d /= g;
//     if(A * B < 0){
//         c = -c;
//     }
//     mp[Pll(c,d)]++;
//     mp2[Pll(c,d)]++;
//   }
    rep(i,n){
        ll a,b;
        cin >> a >> b;
        bool p = (a >= 0) ^ (b >= 0);
        p = !p;
        if(a == 0 && b == 0){
            cnt++;
            continue;
        }
        if(a == 0){
            acnt++;
            continue;
        }
        if(b == 0){
            bcnt++;
            continue;
        }
        a = abs(a);
        b = abs(b);
        ll g = gcd(a,b);
        a = a / g;
        b = b / g;
        if(!p) a = -a;
        mp[Pll(a, b)]++;
        mp2[Pll(a, b)]++;
        
        debug(p);
        

    }

  mint ans = 1;
  
  for(auto u = mp.begin(); u != mp.end(); u++){ 
    
    auto p = u->first;
    // debug(p);
    // if( used.count(p) == 1 ){ continue; } 
    debug(p);
    
    ll a = p.first; ll b = p.second;
    
    // if( a == 0 && b == 0 ){ 
    //   //ゼロベクトルはこれ単体で選ぶことしかできない
      
    //   zero = u.second;
      
    //   used[p] = true;
    //   continue;
    // }
    Pll v;
    // if(a * b == 0){
    //     v = {b,a};
    // }
    if((a * b) < 0){
        v = Pll(b, -a);
    }
    else{
        v = Pll(-b, a);
    }
    ll x = u->second;
    ll y = mp2[v];
    if(a * b < 0){
        if(x >= 1 && y >= 1)continue;
        // if(a * b == 0 && a > 0)continue;
    }
    ans *= modpow(mint(2), x) + modpow(mint(2), y) - mint(1);
    debug(p,v,x,y, ans);
  }
//   rep(i,1e4){
//       ll a = p2(i);
//       assert(a < mod && 0 <= a);
//       mint b = modpow(mint(2), i);
//       assert(mint(a) == b);
//       debug(a);
//   }
  ans *= modpow(mint(2), acnt) + modpow(mint(2), bcnt) - mint(1);
  ans += mint(cnt);
  cout << ans-mint(1) << endl;
  
  return 0;
}
     
