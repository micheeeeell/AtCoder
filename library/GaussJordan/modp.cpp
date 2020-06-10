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

long long modinv(long long a, long long mod) {
    long long b = mod, u = 1, v = 0;
    while(b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= mod;
    if(u < 0)u += mod;
    return u;
}

template< int MOD >
struct Matrix {
    vector< vector< long long > > val;
    Matrix(int m, int n, long long x = 0): val(m, vector<long long>(n, x)) {}
    void init(int m, int n, long long x = 0) {
        val.assign(m, vector<ll>(n, x));
    }
    size_t size() const {return val.size();}
    inline vector<long long> &operator[] (int i) {
        return val[i];
    }
};

template< int MOD >
int GaussJordan(Matrix<MOD> &A, bool is_extended = false) {
    int m = A.size(), n = A[0].size();
    for(int row = 0; row < m; row++) 
        for(int col = 0; col < n; col++)
            A[row][col] = (A[row][col] % MOD + MOD) % MOD;

    int rank = 0;
    for(int col = 0; col < n; col++) {
        if(is_extended && col == n-1)break;
        int pivot = -1;
        for(row = rank; row < m; row++){
            if(A[row][col] != 0) {
                pivot = row;
                break;
            }
        }
        if(pivot == -1) continue;
        swap(A[pivot], A[rank]);
        auto inv = modinv(A[rank][col], MOD);
        for(int col2 = 0; col2 < n; col2++)
            A[rank][col2] = A[rank][col2] * inv % MOD;
        for(int row = 0; row < m; row++){
            if(row == rank || A[row][col] == 0)continue;
            auto fac = A[row][cal];
            for(int col2 = 0; col2 < n; col2++){
                A[row][col2] -= A[rank][col2] * fac % MOD;
                if(A[row][col2] < 0) A[row][col2] += MOD;
            }
        }
        ++rank;
    }
    return rank;
}

template< int MOD >
int linear_equation(Matrix<MOD> A, vector<long long> b, vector<long long> &res){
    int m = A.size(), n = A[0].size();
    Matrix M(m, n+1);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++) M[i][j] = A[i][j];
        M[i][n] = b[i];
    }
    int rank = GaussJordan(M, true);

    for(int row = rank; row < m; row++) if(M[row][n]) return -1;

    res.assign(n, 0);
    for(int i = 0; i < rank; i++) res[i] = M[i][n];
    return rank;
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
}