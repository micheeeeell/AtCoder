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
using u32 = unsigned;
struct bitVector {
    u32 length, cnum, bnum;  // bit列の長さ、chunk数、chunkごとのblock数

    u16 bw = 16, cw = 1024;  // chunk, blockの大きさ
    vector<u16> bit;         //元データ
    vector<u32> chunk;
    vector<vector<u16>> block;

    bitVector(int N) : length(N) {
        cnum = (N + cw - 1) / cw;
        bnum = cw / bw;

        bit.assign(cnum * bnum, 0);
        chunk.assign(cnum + 1, 0);
        block.assign(cnum, vector<u16>(bnum, 0));
    }

    void set(int pos, int b) {
        int bpos = pos / bw;
        int offset = pos % bw;

        if(b == 0) {
            bit[bpos] &= ~(1 << offset);
        } else if(b == 1) {
            bit[bpos] |= (1 << offset);
        }
    }

    void build() {
        int pos = 0;
        int sum = 0, bsum = 0;
        for(int i = 0; i < cnum; i++) {
            bsum = 0;
            for(int j = 1; j < bnum; j++) {
                bsum += __builtin_popcount(bit[pos++]);
                block[i][j] = bsum;
            }
            sum += bsum + __builtin_popcount(bit[pos++]);
            chunk[i + 1] = sum;
        }
    }

    int access(int pos) {
        int bpos = pos / bw;
        int offset = pos % bw;
        return (bit[bpos] >> offset) & 1;
    }

    // [0, pos)に含まれるbの数を返す
    int rank(int pos, int b) {
        int cpos = pos / cw;
        int bpos = (pos % cw) / bw;
        int offset = pos % bw;
        u16 mask = bit[cpos * bnum + bpos] & ((1 << offset) - 1);
        int res = chunk[cpos] + block[cpos][bpos] + __builtin_popcount(mask);

        return b == 1 ? res : pos - res;
    }

    // [l, r)に含まれる1の数を返す
    int rank(int l, int r, int b) {
        return rank(r, b) - rank(l, b);
    }

    // rank(idx, b) = numなる最小のidxを返す
    // つまり、num番目のbの位置(1-indexed)を返す
    int select(int num, int b) {
        if(rank(length, b) < num) return -1;

        int ok = length;
        int ng = -1;
        while(ok - ng > 1) {
            int x = (ok + ng) / 2;
            if(rank(x, b) >= num)
                ok = x;
            else
                ng = x;
        }

        return ok;
    }
};

template <typename T>
struct WaveletMatrix {
    int LOG;
    T max_;
    vector<bitVector> bv;
    int n;
    vector<int> border;
    unordered_map<T, int> first_id, count;
    vector<vector<T>> cumulative_sum;

    WaveletMatrix(int n, vector<T> &v) : n(n) {
        max_ = *max_element(v.begin(), v.end()) + 1;
        // LOG = get_num_of_bit(max_);
        LOG = 64;

        bv.assign(LOG, bitVector(n));
        border.resize(LOG);
        cumulative_sum.resize(LOG + 1, vector<T>(n + 1, 0));
        build(v);
    }

    void build(vector<T> &v) {
        vector<T> pre, suf, vec = v;
        for(int i = 0; i < n; i++) {
            cumulative_sum[0][i + 1] = cumulative_sum[0][i] + vec[i];
        }

        for(int i = 0; i < LOG; i++) {
            for(int j = 0; j < n; j++) {
                if((vec[j] >> (LOG - i - 1)) & 1) {
                    suf.emplace_back(vec[j]);
                    bv[i].set(j, 1);
                } else {
                    pre.emplace_back(vec[j]);
                    bv[i].set(j, 0);
                }
            }
            border[i] = pre.size();
            int id = 0;
            for(auto &a : pre) vec[id++] = a;
            for(auto &a : suf) vec[id++] = a;
            for(int j = 0; j < n; j++) {
                cumulative_sum[i + 1][j + 1] =
                    cumulative_sum[i + 1][j] + vec[j];
            }
            pre.clear();
            suf.clear();
            bv[i].build();
        }
        for(int i = 0; i < n; i++) {
            count[vec[i]]++;
            if(first_id.count(vec[i])) continue;
            first_id[vec[i]] = i;
        }
    }

    // idx番目の数
    T access(int idx) {
        T res = 0;
        T tmp;
        for(int i = 0; i < LOG; i++) {
            tmp = bv[i].access(idx);
            res |= (T)tmp << (LOG - i - 1);
            idx = bv[i].rank(idx, tmp);
            idx += (tmp == 1 ? border[i] : 0);
        }
        return res;
    }

    // [0, idx)に数値cが現れた回数
    int rank(int idx, T c) {
        if(!first_id.count(c)) return 0;
        int tmp = 0;
        for(int i = 0; i < LOG; i++) {
            tmp = c >> (LOG - i - 1) & 1;
            idx = bv[i].rank(idx, tmp);
            idx += (tmp == 1 ? border[i] : 0);
        }
        return idx - first_id[c];
    }
    // [l, r)に数値cが現れた回数
    int rank(int l, int r, T c) {
        return rank(r, c) - rank(l, c);
    }

    // 前からnum番目のcのidx(1-indexed)（無いときは-1）
    int select(int num, T c) {
        if(num == 0 || !first_id.count(c) || count[c] < num) {
            return -1;
        }
        int idx = first_id[c] + num;
        int tmp = 0;
        for(int i = LOG - 1; 0 <= i; i--) {
            tmp = c >> (LOG - i - 1) & 1;
            idx = bv[i].select((tmp ? idx - border[i] : idx), tmp);
        }

        return idx;
    }

    // [l, r)の中でnum番目に小さい値
    T quantile(int l, int r, int num) {
        assert(r > l && num <= r - l);
        int tmp, cnt0, cnt1;
        T res = 0;
        for(int i = 0; i < LOG; i++) {
            cnt0 = bv[i].rank(l, r, 0);
            cnt1 = r - l - cnt0;
            tmp = (num <= cnt0 ? 0 : 1);
            l = bv[i].rank(l, tmp);
            r = bv[i].rank(r, tmp);
            if(tmp) {
                l += border[i];
                r += border[i];
                num -= cnt0;
            }
            res |= (T)tmp << (LOG - i - 1);
            // debug(l, r, cnt0, cnt1, tmp);
        }
        return res;
    }

    // [l, r)の中で出現頻度の高い順にk個の(値、出現回数)を返す
    vector<pair<T, int>> topk(int l, int r, int k) {
        vector<pair<T, int>> res;
        // 順に頻度、左端、深さ、値
        using tp = tuple<int, int, int, T>;

        auto comp = [](const tp &l, const tp &r) {
            if(get<0>(l) != get<0>(r)) {
                return get<0>(l) < get<0>(r);
            }
            if(get<2>(l) != get<2>(r)) {
                return get<2>(l) > get<2>(r);
            }
            return get<3>(l) < get<3>(r);
        };

        priority_queue<tp, vector<tp>, decltype(comp)> pq(comp);
        pq.emplace(r - l, l, 0, 0);
        while(!pq.empty()) {
            auto [width, l, depth, value] = pq.top();
            pq.pop();
            if(depth == LOG) {
                res.emplace_back(value, width);
                if(res.size() >= k) {
                    break;
                }
            } else {
                int cnt, l2;
                for(int i = 0; i < 2; i++) {
                    cnt = bv[depth].rank(l, l + width, i);
                    if(!cnt) continue;
                    l2 = bv[depth].rank(l, i);
                    if(i) l2 += border[depth];
                    pq.emplace(cnt, l2, depth + 1,
                               value | ((T)i << (LOG - depth - 1)));
                }
            }
        }

        return res;
    }

    // [l, r)の中に出現する値を大きい順にk個、頻度とともに列挙
    vector<pair<T, int>> rangeMaxk(int l, int r, int k) {
        using tp = tuple<int, int, int, T>;
        vector<tp> v;
        v.emplace_back(0, l, r, 0);
        vector<pair<T, int>> res;

        int tmp, l0, r0, l1, r1;
        while(!v.empty()) {
            auto [depth, left, right, value] = v.back();
            v.pop_back();

            if(depth == LOG) {
                res.emplace_back(value, right - left);
                if(res.size() >= k) break;
                continue;
            }

            l0 = bv[depth].rank(left, 0);
            r0 = bv[depth].rank(right, 0);
            l1 = left - l0 + border[depth];
            r1 = right - r0 + border[depth];

            if(r0 - l0) {
                v.emplace_back(depth + 1, l0, r0, value);
            }

            if(r1 - l1) {
                v.emplace_back(depth + 1, l1, r1,
                               value | ((T)1 << (LOG - depth - 1)));
            }
        }

        return res;
    }
    // [l, r)の中に出現する値を小さい順にk個、頻度とともに列挙
    vector<pair<T, int>> rangeMink(int l, int r, int k) {
        using tp = tuple<int, int, int, T>;
        vector<tp> v;
        v.emplace_back(0, l, r, 0);
        vector<pair<T, int>> res;

        int tmp, l0, r0, l1, r1;
        while(!v.empty()) {
            auto [depth, left, right, value] = v.back();
            v.pop_back();

            if(depth == LOG) {
                res.emplace_back(value, right - left);
                if(res.size() >= k) break;
                continue;
            }

            l0 = bv[depth].rank(left, 0);
            r0 = bv[depth].rank(right, 0);
            l1 = left - l0 + border[depth];
            r1 = right - r0 + border[depth];

            if(r1 - l1) {
                v.emplace_back(depth + 1, l1, r1,
                               value | ((T)1 << (LOG - depth - 1)));
            }
            if(r0 - l0) {
                v.emplace_back(depth + 1, l0, r0, value);
            }
        }

        return res;
    }

    // [l, r)においてx <= c < yを満たすcの値と出現頻度を列挙
    vector<pair<T, int>> rangeList(int l, int r, T x, T y) {
        if(x >= y || l >= r || y == 0 || r == 0) {
            return {};
        }
        using tp = tuple<int, int, int, int, T>;
        vector<tp> v;
        vector<pair<T, int>> res;
        y--;  // x <= c <= y
        v.emplace_back(0, l, r, 0, 0);

        int tmp, l0, l1, r0, r1;
        while(!v.empty()) {
            auto [depth, left, right, is_small, value] = v.back();
            // debug(depth, left, right, is_small, value);
            v.pop_back();
            if(depth == LOG) {
                if(value >= x) {
                    res.emplace_back(value, right - left);
                }
            } else {
                tmp = y >> (LOG - depth - 1) & 1;

                l0 = bv[depth].rank(left, 0);
                r0 = bv[depth].rank(right, 0);
                l1 = left - l0 + border[depth];
                r1 = right - r0 + border[depth];

                if(r0 - l0) {
                    v.emplace_back(depth + 1, l0, r0, is_small | (tmp == 1),
                                   value);
                }

                if(is_small || tmp == 1) {
                    if(r1 - l1) {
                        v.emplace_back(depth + 1, l1, r1, is_small,
                                       value | ((T)1 << (LOG - depth - 1)));
                    }
                }
            }
        }

        return res;
    }

    // [l, r)の値の合計
    T rangeSum(int l, int r) {
        assert(r > l);
        auto v = rangeMaxk(l, r, r - l);
        T res = 0;
        for(auto &[val, freq] : v) {
            res += val * (T)freq;
        }
        return res;
    }

    T rangeSum(int l, int r, T x, T y) {
        return rangeSum(l, r, 0, 0, x, y);
    }

    T rangeSum(int l, int r, int depth, T c, T x, T y) {
        if(l == r) return 0;
        if(depth == LOG) {
            if(x <= c && c < y) {
                return c * (r - l);
            }
            return 0;
        }

        T next_c = (T)1 << (LOG - depth - 1) | c;
        T all_one_c = (((T)1 << (LOG - depth - 1)) - 1) | next_c;
        if(all_one_c < x || y <= c) {
            return 0;
        }

        if(x <= c && all_one_c < y) {
            return cumulative_sum[depth][r] - cumulative_sum[depth][l];
        }

        int l0 = bv[depth].rank(l, 0);
        int r0 = bv[depth].rank(r, 0);
        int l1 = l - l0 + border[depth];
        int r1 = r - r0 + border[depth];

        return rangeSum(l0, r0, depth + 1, c, x, y) +
               rangeSum(l1, r1, depth + 1, next_c, x, y);
    }

    // [l, r)でxより小さい数の出現回数
    int rangeFreq(int l, int r, T x) {
        int res = 0;
        T tmp;
        int cnt;
        for(int i = 0; i < LOG; i++) {
            tmp = x >> (LOG - i - 1) & 1;
            cnt = bv[i].rank(l, r, 0);
            l = bv[i].rank(l, tmp);
            r = bv[i].rank(r, tmp);
            if(tmp) {
                res += cnt;
                l += border[i];
                r += border[i];
            }
        }
        return res;
    }
    // [l, r)で x <= c < yを満たすcの出現回数
    int rangeFreq(int l, int r, T x, T y) {
        return rangeFreq(l, r, y) - rangeFreq(l, r, x);
    }

    // [l, r)で（cと同じ値の数、cより小さい値の数、cより大きい値のか数）
    tuple<int, int, int> rankAll(int l, int r, T c) {
        int num = r - l;

        int rank_less = 0, rank_more = 0;
        int tmp, l0, l1, r0, r1;
        for(int i = 0; i < LOG; i++) {
            tmp = c >> (LOG - i - 1) & 1;

            l0 = bv[i].rank(l, 0);
            r0 = bv[i].rank(r, 0);
            l1 = l - l0;
            r1 = r - r0;

            if(tmp) {
                rank_less += (r0 - l0);
                l = l1 + border[i];
                r = r1 + border[i];
            } else {
                rank_more += (r1 - l1);
                l = l0;
                r = r0;
            }
        }

        int rank = num - rank_less - rank_more;
        return make_tuple(rank, rank_less, rank_more);
    }

    int rankLess(int l, int r, T c) {
        auto t = rankAll(l, r, c);
        return get<1>(t);
    }
    int rankMore(int l, int r, T c) {
        auto t = rankAll(l, r, c);
        return get<2>(t);
    }

    // [l, r)でx <= c < yを満たす数の内、最大のもの
    T prevValue(int l, int r, T x, T y) {
        if(x >= y || l >= r || y == 0 || r == 0) {
            return -1;
        }
        using tp = tuple<int, int, int, int, T>;
        vector<tp> v;
        y--;  // x <= c <= y
        v.emplace_back(0, l, r, 0, 0);

        int tmp, l0, l1, r0, r1;
        while(!v.empty()) {
            auto [depth, left, right, is_small, value] = v.back();
            // debug(depth, left, right, is_small, value);
            v.pop_back();
            if(depth == LOG) {
                if(value >= x) {
                    return value;
                }
            } else {
                tmp = y >> (LOG - depth - 1) & 1;

                l0 = bv[depth].rank(left, 0);
                r0 = bv[depth].rank(right, 0);
                l1 = left - l0 + border[depth];
                r1 = right - r0 + border[depth];

                if(r0 - l0) {
                    v.emplace_back(depth + 1, l0, r0, is_small | (tmp == 1),
                                   value);
                }

                if(is_small || tmp == 1) {
                    if(r1 - l1) {
                        v.emplace_back(depth + 1, l1, r1, is_small,
                                       value | ((T)1 << (LOG - depth - 1)));
                    }
                }
            }
        }

        return -1;
    }

    // [l, r)でx <= c < yを満たす数の内、最小のもの
    T nextValue(int l, int r, T x, T y) {
        if(x >= y || l >= r || y == 0 || r == 0) {
            return -1;
        }
        using tp = tuple<int, int, int, int, T>;
        vector<tp> v;

        v.emplace_back(0, l, r, 0, 0);

        int tmp, l0, r0, l1, r1;
        while(!v.empty()) {
            auto [depth, left, right, is_large, value] = v.back();
            v.pop_back();
            if(depth == LOG) {
                if(value < y) {
                    return value;
                }
            }

            tmp = x >> (LOG - depth - 1) & 1;
            l0 = bv[depth].rank(left, 0);
            r0 = bv[depth].rank(right, 0);
            l1 = left - l0 + border[depth];
            r1 = right - r0 + border[depth];

            if(r1 - l1) {
                v.emplace_back(depth + 1, l1, r1, is_large | (tmp == 0),
                               value | ((T)1 << (LOG - depth - 1)));
            }

            if(is_large || tmp == 0) {
                if(r0 - l0) {
                    v.emplace_back(depth + 1, l0, r0, is_large, value);
                }
            }
        }

        return -1;
    }

    int get_num_of_bit(T x) {
        if(x == 0) return 0;
        x--;
        uint64_t bit_num = 0;
        while(x >> bit_num) {
            ++bit_num;
        }
        return bit_num;
    }
};

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,t; cin >> n >> t;
    ll min_ = 0;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> sum(n + 1);
    rep(i,0,n){
        sum[i + 1] = sum[i] + a[i];
        chmin(min_, sum[i+1]);
    }
    rep(i,0,n+1){
        sum[i] -= min_;
        if(t < 0)sum[i] += abs(t);
    }
    debug(sum);
    WaveletMatrix<ll> wm(n+1, sum);
    ll ans = 0;
    rep(i,0,n){
        ans += wm.rankLess(i+1, n+1, sum[i] + t);
        debug(i, ans);
    }

    cout << ans << "\n";
}