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
const int n_max = 2e5+10;

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

// modintが必要
// modintによる実装
const int MAX = 1e6;
vector<mint> fac(MAX);
void COMinit(){
    fac[0] = 1;
    reps(i,MAX-1){
        fac[i] = fac[i-1] * mint(i);
    }
}

mint COM(ll n, ll k){
    if (n < k) return (mint)0;
    if (n < 0 || k < 0) return (mint)0;
    return fac[n] / (fac[k] * fac[n-k]);
}

// 木の上のトポロジカルソート
// 適当な根から有向であるとみなしてBFS
vector<ll> tree_topo(vvl &graph, ll root){
    // const ll n_max = 2e5+10;
    bitset<n_max> bs(0);
    vector<ll> ans;
    queue<ll> que;
    que.emplace(root);
    bs[root] = 1;
    while(!que.empty()) {
        auto f = que.front();que.pop();
        ans.emplace_back(f);
        for(auto &to : graph[f]){
            if(bs[to])continue;
            bs[to] = 1;
            que.emplace(to);
        }
    }
    return ans;
}

vector<ll> par(n_max);
bitset<n_max> used(0);
void dfs(vvl &graph, ll pos){
    for(auto &to : graph[pos]){
        if(used[to])continue;
        par[to] = pos;
        used[to] = 1;
        dfs(graph, to);
    }
}

int main(){

    ll n; cin >> n;
    vector<vector<ll>> graph(n);
    rep(i,n-1) {
        ll a,b;cin >> a >> b;
        a--;b--;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    
    vector<ll> topo = tree_topo(graph, 0);
    // vector<ll> rev_topo = tree_topo(graph, topo.back());

    // print(topo);
    // print(rev_topo);

    auto f = [&](vector<ll> &topo){
        vector<ll> part(n, 0);
        ll temp;
        rrep(i,n){
            temp = 0;
            for(auto &to : graph[topo[i]])temp += part[to];
            part[topo[i]] = temp+1;
        };
        return part;
    };
    vector<ll> part = f(topo);
    // print(part);
    // print(rev_part);

    vector<mint> vec(n);
    COMinit();
    rep(i,n){
        mint t = fac[n-1];
        ll pos = topo[i];
        for(auto &to : graph[pos])if(part[to] < part[pos])t /= fac[part[to]];
        t /= fac[n - part[pos]];
        vec[pos] = t;
    }
    // print(vec);

    vector<mint> dp1(n), dp2(n, 0);
    rrep(i,n){
        ll pos = topo[i];
        mint t = fac[part[pos] - 1];
        for(auto &to : graph[pos])if(part[to] < part[pos]){
            t /= fac[part[to]];
            t *= dp1[to];
        }
        dp1[pos] = t;
    }
    used[0] = 1;
    par[0] = -1;
    dfs(graph, 0);
    dp2[0] = 1;
    rep(i,n){
        ll pos = topo[i];
        mint t = 1;
        for(auto &to : graph[pos]){
            if(part[to] > part[pos])continue;
            t *= dp1[to];
            t /= fac[part[to]];
        }
        if(par[pos] != -1){
            t *= dp2[pos];
            t /= fac[n - part[pos]];
        }

        for(auto &to : graph[pos]){
            if(part[to] > part[pos])continue;
            dp2[to] = t / dp1[to];
            dp2[to] *= fac[n - part[to] - 1] * fac[part[to]];
        }
    }
    // print(dp1);print(dp2);
    // rep(i,n)cout << par[i] << " ";
    // cout << endl;
    vector<mint> ans(n);
    rep(i,n){
        ll pos = topo[i];
        mint t = vec[pos];
        for(auto &to : graph[pos]){
            if(part[to] > part[pos])t *= dp2[pos];
            else t *= dp1[to];
        }
        ans[pos] = t;
    }
    // debug(n_max);
    print(ans);
}