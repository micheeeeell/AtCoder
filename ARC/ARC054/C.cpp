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

const int MAX_ROW = 510;
const int MAX_COL = 510;
struct BitMatrix {
    int H, W;
    bitset<MAX_COL> val[MAX_ROW];
    BitMatrix(int h = 1, int w = 1) : H(h), W(w){};
    inline bitset<MAX_COL> &operator[](int i) {
        return val[i];
    };
};

int GaussJordan(BitMatrix &A, bool is_extended = false) {
    int rank = 0;
    for(int col = 0; col < A.W; col++) {
        if(is_extended && col == A.W - 1) break;
        int pivot = -1;
        for(int row = rank; row < A.H; row++) {
            if(A[row][col]) {
                pivot = row;
                break;
            }
        }
        if(pivot == -1) continue;
        swap(A[pivot], A[rank]);
        for(int row = 0; row < A.H; row++) {
            if(row != rank && A[row][col]) A[row] ^= A[rank];
        }
        ++rank;
    }
    return rank;
}

int linear_equation(BitMatrix A, vector<int> b, vector<int> &res) {
    int m = A.H, n = A.W;
    BitMatrix M(m, n + 1);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) M[i][j] = A[i][j];
        M[i][n] = b[i];
    }
    int rank = GaussJordan(M, true);

    // no solution
    for(int row = rank; row < m; row++)
        if(M[row][n]) return -1;

    // answer
    res.assign(n, 0);
    for(int i = 0; i < rank; i++) res[i] = M[i][n];
    return rank;
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];
    BitMatrix a(n, n);
    rep(i, 0, n) {
        rep(j,0,n){
            a[i][j] = s[i][j] == '1';
        }
    }

    ll r = GaussJordan(a);
    debug(r);
    cout << (r == n ? "Odd" : "Even") << "\n";
}