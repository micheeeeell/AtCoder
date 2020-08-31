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

using u16 = unsigned short;
using u32 = unsigned long;
struct bitVector{
    u32 length, cnum, bnum; //bit列の長さ、chunk数、chunkごとのblock数

    u16 bw = 16, cw = 1024; // chunk, blockの大きさ
    vector<u16> bit; //元データ
    vector<u32> chunk;
    vector<vector<u16>> block;

    bitVector(int N) : length(N) {
        cnum = (N + cw - 1) / cw;
        bnum = cw / bw;

        bit.assign(cnum * bnum, 0);
        chunk.assign(cnum + 1, 0);
        block.assign(cnum, vector<u16>(bnum, 0));
    }

    void set(int pos, int b){
        int bpos = pos / bw;
        int offset = pos % bw;

        if(b == 0){
            bit[bpos] &= ~(1 << offset);
        }
        else if(b == 1){
            bit[bpos] |= (1 << offset);
        }
    }

    void build(){
        int pos = 0;
        int sum = 0, bsum = 0;
        for(int i = 0; i < cnum; i++){
            bsum = 0;
            for(int j = 1; j < bnum; j++){
                bsum += __builtin_popcount(bit[pos++]);
                block[i][j] = bsum;
            }
            sum += bsum + __builtin_popcount(bit[pos++]);
            chunk[i + 1] = sum;
        }
    }

    int access(int pos){
        int bpos = pos / bw;
        int offset = bpos % bw;
        return (bit[bpos] >> offset) & 1;
    }

    // [0, pos)に含まれるbの数を返す
    int zero_rank(int pos, int b){
        int cpos = pos / cw;
        int bpos = (pos % cw) / bw;
        int offset = pos % bw;
        u16 mask = bit[cpos * bnum + bpos] & ((1 << offset) - 1);
        int res = chunk[cpos] + block[cpos][bpos] + __builtin_popcount(mask);

        return b == 1 ? res : pos - res;
    }

    // [l, r)に含まれる1の数を返す
    int rank(int l, int r, int b){
        return zero_rank(r, b) - zero_rank(l, b);
    }

    // zero_rank(idx) = numなる最小のidxを返す
    int select(int num, int b){
        if(zero_rank(length, b) < num)return -1;

        int ok = length;
        int ng = -1;
        while(ok - ng > 1){
            int x = (ok + ng) / 2;
            if(zero_rank(x, b) >= num)ok = x;
            else ng = x;
        }

        return ok;
    }
};

void print() {
    cout << endl;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
    cout << head;
    if (sizeof...(tail) != 0) cout << " ";
    print(forward<Tail>(tail)...);
}

template <class T>
void print(vector<T> &vec) {
    for (auto& a : vec) {
        cout << a;
        if (&a != &vec.back()) cout << " ";
    }
    cout << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
    for (auto& vec : df) {
        print(vec);
    }
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    vector<int> b = {0,0,1,1,1,0,1,1,0,0,0,1,0,1,0,1,1};
    ll n = b.size();
    bitVector V(n);
    rep(i,0,n)V.set(i, b[i]);
    V.build();
    print(V.bit);
    print(V.chunk);
    print(V.block);
    debug(V.rank(4,8,1), V.zero_rank(17,1), V.select(6,1));
    debug(V.rank(4,12,0), V.zero_rank(17,0), V.select(6,0));
    
}