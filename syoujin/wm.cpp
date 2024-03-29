#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = (a); i < ((int)b); ++i)
#define RFOR(i, a) for(int i = (a); i >= 0; --i)
#define FOE(i, a) for(auto i : a)
#define ALL(c) (c).begin(), (c).end()
#define RALL(c) (c).rbegin(), (c).rend()
#define DUMP(x) cerr << #x << " = " << (x) << endl;
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
#define BIT_ON(bit, i) (bit & (1LL << i))
#define BIT_COUNT(bit) (__builtin_popcount(bit))

typedef long long LL;
template <typename T>
using V = std::vector<T>;
template <typename T>
using VV = std::vector<std::vector<T>>;
template <typename T>
using VVV = std::vector<std::vector<std::vector<T>>>;
template <typename T>
using VVVV = std::vector<std::vector<std::vector<std::vector<T>>>>;

template <class T>
inline T ceil(T a, T b) {
    return (a + b - 1) / b;
}
template <class T>
inline void print(T x) {
    std::cout << x << std::endl;
}
template <class T>
inline void print_vec(const std::vector<T> &v) {
    for(int i = 0; i < v.size(); ++i) {
        if(i != 0) {
            std::cout << " ";
        }
        std::cout << v[i];
    }
    std::cout << "\n";
}
template <class T>
inline void print_2vec(const std::vector<std::vector<T>> &v) {
    for(int i = 0; i < v.size(); ++i) {
        for(int j = 0; j < v[0].size(); ++j) {
            if(j != 0) {
                std::cout << " ";
            }
            std::cout << std::setw(13) << std::left << v[i][j];
        }
        std::cout << "\n";
    }
}
template <class T>
inline bool inside(T y, T x, T H, T W) {
    return 0 <= y and y < H and 0 <= x and x < W;
}
template <class T>
inline double euclidean_distance(T y1, T x1, T y2, T x2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
template <class T>
inline double manhattan_distance(T y1, T x1, T y2, T x2) {
    return abs(x1 - x2) + abs(y1 - y2);
}
template <typename T>
T &chmin(T &a, const T &b) {
    if(b < a) {
        a = b;
    }
    return a;
}
template <typename T>
T &chmax(T &a, const T &b) {
    if(b > a) {
        a = b;
    }
    return a;
}
template <class T>
inline std::vector<T> unique(std::vector<T> v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    return v;
}
// 初項s, 交差dのn個の数列の和
long long sum_of_arithmetic_progression(long long s, long long d, long long n) {
    return n * (2 * s + (n - 1) * d) / 2;
}

const int INF = 1 << 30;
const double EPS = 1e-9;
const std::string YES = "YES", Yes = "Yes", NO = "NO", No = "No";
const std::vector<int> dy4 = {0, -1, 0, 1}, dx4 = {1, 0, -1, 0};
const std::vector<int> dy8 = {0, -1, 0, 1, 1, -1, -1, 1},
                       dx8 = {1, 0, -1, 0, 1, 1, -1, -1};

using namespace std;

enum { NOTFOUND = 0xFFFFFFFFFFFFFFFFLLU };

class SuccinctBitVector {
   private:
    const uint64_t size;  // ビットベクトルのサイズ
    static const uint32_t blockBitNum = 16;
    static const uint32_t LEVEL_L = 512;
    static const uint32_t LEVEL_S = 16;

    std::vector<uint64_t> L;  // 大ブロック
    std::vector<uint16_t> S;  // 小ブロック
    std::vector<uint16_t> B;  // ビットベクトル

    uint64_t numOne = 0;  // 1bitの数

   public:
    explicit SuccinctBitVector(const uint64_t n) : size(n) {
        const uint64_t s =
            (n + blockBitNum - 1) / blockBitNum + 1;  // ceil(n, blockSize)
        this->B.assign(s, 0);
        this->L.assign(n / LEVEL_L + 1, 0);
        this->S.assign(n / LEVEL_S + 1, 0);
    }

    // B[pos] = bit
    void setBit(const uint64_t bit, const uint64_t pos) {
        assert(bit == 0 or bit == 1);
        assert(pos < this->size);

        const uint64_t blockPos = pos / blockBitNum;
        const uint64_t offset = pos % blockBitNum;
        if(bit == 1) {
            B.at(blockPos) |= (1LLU << offset);
        } else {
            B.at(blockPos) &= (~(1LLU << offset));
        }
    }

    // B[pos]
    uint64_t access(const uint64_t pos) {
        assert(pos < this->size);
        const uint64_t blockPos = pos / blockBitNum;
        const uint64_t offset = pos % blockBitNum;
        return ((B.at(blockPos) >> offset) & 1);
    }

    void build() {
        uint64_t num = 0;
        for(uint64_t i = 0; i <= size; i++) {
            if(i % LEVEL_L == 0) {
                L.at(i / LEVEL_L) = num;
            }
            if(i % LEVEL_S == 0) {
                S.at(i / LEVEL_S) = num - L.at(i / LEVEL_L);
            }
            if(i != size and i % blockBitNum == 0) {
                num += this->popCount(this->B.at(i / blockBitNum));
            }
        }
        this->numOne = num;
    }

    // B[0, pos)のbitの数
    uint64_t rank(const uint64_t bit, const uint64_t pos) {
        assert(bit == 0 or bit == 1);
        assert(pos <= this->size);

        if(bit) {
            return L[pos / LEVEL_L] + S[pos / LEVEL_S] +
                   popCount(B[pos / blockBitNum] &
                            ((1 << (pos % blockBitNum)) - 1));
        } else {
            return pos - rank(1, pos);
        }
    }

    // rank番目のbitの位置 + 1(rankは1-origin)
    uint64_t select(const uint64_t bit, const uint64_t rank) {
        assert(bit == 0 or bit == 1);
        assert(rank > 0);
        if(bit == 0 and rank > this->size - this->numOne) {
            return NOTFOUND;
        }
        if(bit == 1 and rank > this->numOne) {
            return NOTFOUND;
        }

        // 大ブロックL内を検索
        uint64_t large_idx = 0;
        {
            uint64_t left = 0;
            uint64_t right = L.size();
            while(right - left > 1) {
                uint64_t mid = (left + right) / 2;
                uint64_t r = L.at(mid);
                r = (bit) ? r : mid * LEVEL_L - L.at(mid);

                if(r < rank) {
                    left = mid;
                    large_idx = mid;
                } else {
                    right = mid;
                }
            }
        }

        // 小ブロックS内を検索
        uint64_t small_idx = (large_idx * LEVEL_L) / LEVEL_S;
        {
            uint64_t left = (large_idx * LEVEL_L) / LEVEL_S;
            uint64_t right =
                std::min(((large_idx + 1) * LEVEL_L) / LEVEL_S, S.size());
            while(right - left > 1) {
                uint64_t mid = (left + right) / 2;
                uint64_t r = L.at(large_idx) + S.at(mid);
                r = (bit) ? r : mid * LEVEL_S - r;

                if(r < rank) {
                    left = mid;
                    small_idx = mid;
                } else {
                    right = mid;
                }
            }
        }

        // Bをブロック単位で順番に探索
        uint64_t rank_pos = 0;
        {
            const uint64_t begin_block_idx =
                (small_idx * LEVEL_S) / blockBitNum;
            uint64_t total_bit = L.at(large_idx) + S.at(small_idx);
            if(bit == 0) {
                total_bit = small_idx * LEVEL_S - total_bit;
            }
            for(uint64_t i = 0;; ++i) {
                uint64_t b = popCount(B.at(begin_block_idx + i));
                if(bit == 0) {
                    b = blockBitNum - b;
                }
                if(total_bit + b >= rank) {
                    uint64_t block = (bit) ? B.at(begin_block_idx + i)
                                           : ~B.at(begin_block_idx + i);
                    rank_pos = (begin_block_idx + i) * blockBitNum +
                               selectInBlock(block, rank - total_bit);
                    break;
                }
                total_bit += b;
            }
        }

        return rank_pos + 1;
    }

    uint64_t getNumOne() const {
        return numOne;
    }

    void debug() {
        std::cout << "LEVEL_L(" << L.size() << ")" << std::endl;
        for(uint64_t i = 0; i < L.size(); ++i) {
            std::cout << L.at(i) << ", ";
        }
        std::cout << std::endl;
        std::cout << "LEVEL_S(" << S.size() << ")" << std::endl;
        for(uint64_t i = 0; i < S.size(); ++i) {
            std::cout << S.at(i) << ", ";
        }
        std::cout << std::endl;
    }

   private:
    uint64_t popCount(uint64_t x) {
        x = (x & 0x5555555555555555ULL) + ((x >> 1) & 0x5555555555555555ULL);
        x = (x & 0x3333333333333333ULL) + ((x >> 2) & 0x3333333333333333ULL);
        x = (x + (x >> 4)) & 0x0f0f0f0f0f0f0f0fULL;
        x = x + (x >> 8);
        x = x + (x >> 16);
        x = x + (x >> 32);
        return x & 0x7FLLU;
    }

    uint64_t selectInBlock(uint64_t x, uint64_t rank) {
        uint64_t x1 = x - ((x & 0xAAAAAAAAAAAAAAAALLU) >> 1);
        uint64_t x2 =
            (x1 & 0x3333333333333333LLU) + ((x1 >> 2) & 0x3333333333333333LLU);
        uint64_t x3 = (x2 + (x2 >> 4)) & 0x0F0F0F0F0F0F0F0FLLU;

        uint64_t pos = 0;
        for(;; pos += 8) {
            uint64_t rank_next = (x3 >> pos) & 0xFFLLU;
            if(rank <= rank_next) break;
            rank -= rank_next;
        }

        uint64_t v2 = (x2 >> pos) & 0xFLLU;
        if(rank > v2) {
            rank -= v2;
            pos += 4;
        }

        uint64_t v1 = (x1 >> pos) & 0x3LLU;
        if(rank > v1) {
            rank -= v1;
            pos += 2;
        }

        uint64_t v0 = (x >> pos) & 0x1LLU;
        if(v0 < rank) {
            rank -= v0;
            pos += 1;
        }

        return pos;
    }
};

class WaveletMatrix {
    public:
    std::vector<SuccinctBitVector> bit_arrays;
    std::vector<uint64_t> begin_one;  // 各bitに着目したときの1の開始位置
    std::map<uint64_t, uint64_t>
        begin_alphabet;  // 最後のソートされた配列で各文字の開始位置
    std::vector<std::vector<uint64_t>>
        cumulative_sum;  // 各bitに着目したときの累積和

    uint64_t size;             // 与えられた配列のサイズ
    uint64_t maximum_element;  // 文字数
    uint64_t bit_size;         // 文字を表すのに必要なbit数

    WaveletMatrix(const std::vector<uint64_t> &array) {
        assert(array.size() > 0);
        size = array.size();
        maximum_element = *max_element(array.begin(), array.end()) + 1;
        bit_size = get_num_of_bit(maximum_element);
        if(bit_size == 0) {
            bit_size = 1;
        }

        for(uint64_t i = 0; i < bit_size; ++i) {
            SuccinctBitVector sv(size);
            bit_arrays.push_back(sv);
        }
        this->begin_one.resize(bit_size);
        this->cumulative_sum.resize(bit_size + 1,
                                    std::vector<uint64_t>(size + 1, 0));

        for(uint64_t j = 0; j < array.size(); ++j) {
            this->cumulative_sum.at(0).at(j + 1) =
                this->cumulative_sum.at(0).at(j) + array[j];
        }

        std::vector<uint64_t> v(array);
        for(uint64_t i = 0; i < bit_size; ++i) {
            std::vector<uint64_t> temp;
            // 0をtempにいれてく
            for(uint64_t j = 0; j < v.size(); ++j) {
                uint64_t c = v.at(j);
                uint64_t bit =
                    (c >> (bit_size - i - 1)) & 1;  //　上からi番目のbit
                if(bit == 0) {
                    temp.push_back(c);
                    bit_arrays.at(i).setBit(0, j);
                }
            }

            this->begin_one.at(i) = temp.size();

            // 1をtempにいれてく
            for(uint64_t j = 0; j < v.size(); ++j) {
                uint64_t c = v.at(j);
                uint64_t bit =
                    (c >> (bit_size - i - 1)) & 1;  //　上からi番目のbit
                if(bit == 1) {
                    temp.push_back(c);
                    bit_arrays.at(i).setBit(1, j);
                }
            }

            for(uint64_t j = 0; j < temp.size(); ++j) {
                this->cumulative_sum.at(i + 1).at(j + 1) =
                    this->cumulative_sum.at(i + 1).at(j) + temp.at(j);
            }

            bit_arrays.at(i).build();
            v = temp;
        }

        // ソートされた配列内での各文字の位置を取得
        for(int i = v.size() - 1; i >= 0; --i) {
            this->begin_alphabet[v.at(i)] = i;
        }
    }

    // v[pos]
    uint64_t access(uint64_t pos) {
        if(pos >= this->size) {
            return NOTFOUND;
        }

        uint64_t c = 0;
        for(uint64_t i = 0; i < bit_arrays.size(); ++i) {
            uint64_t bit =
                bit_arrays.at(i).access(pos);  // もとの数値がのi番目のbit
            c = (c <<= 1) | bit;
            pos = bit_arrays.at(i).rank(bit, pos);
            if(bit) {
                pos += this->begin_one.at(i);
            }
        }
        return c;
    }

    // i番目のcの位置 + 1を返す。rankは1-origin
    uint64_t select(uint64_t c, uint64_t rank) {
        assert(rank > 0);
        if(c >= maximum_element) {
            return NOTFOUND;
        }
        if(this->begin_alphabet.find(c) == this->begin_alphabet.end()) {
            return NOTFOUND;
        }

        uint64_t index = this->begin_alphabet.at(c) + rank;
        for(uint64_t i = 0; i < bit_arrays.size(); ++i) {
            uint64_t bit = ((c >> i) & 1);  // 下からi番目のbit
            if(bit == 1) {
                index -= this->begin_one.at(bit_size - i - 1);
            }
            index = this->bit_arrays.at(bit_size - i - 1).select(bit, index);
        }
        return index;
    }

    // v[begin_pos, end_pos)で最大値のindexを返す
    uint64_t maxRange(uint64_t begin_pos, uint64_t end_pos) {
        return quantileRange(begin_pos, end_pos, end_pos - begin_pos - 1);
    }

    // v[begin_pos, end_pos)で最小値のindexを返す
    uint64_t minRange(uint64_t begin_pos, uint64_t end_pos) {
        return quantileRange(begin_pos, end_pos, 0);
    }

    // v[begin_pos, end_pos)でk番目に小さい数値のindexを返す(kは0-origin)
    // つまり小さい順に並べてk番目の値
    uint64_t quantileRange(uint64_t begin_pos, uint64_t end_pos, uint64_t k) {
        if((end_pos > size || begin_pos >= end_pos) ||
           (k >= end_pos - begin_pos)) {
            return NOTFOUND;
        }

        uint64_t val = 0;
        for(uint64_t i = 0; i < bit_size; ++i) {
            const uint64_t num_of_zero_begin =
                bit_arrays.at(i).rank(0, begin_pos);
            const uint64_t num_of_zero_end = bit_arrays.at(i).rank(0, end_pos);
            const uint64_t num_of_zero =
                num_of_zero_end -
                num_of_zero_begin;  // beginからendまでにある0の数
            const uint64_t bit =
                (k < num_of_zero) ? 0
                                  : 1;  // k番目の値の上からi番目のbitが0か1か

            if(bit) {
                k -= num_of_zero;
                begin_pos =
                    this->begin_one.at(i) + begin_pos - num_of_zero_begin;
                end_pos = this->begin_one.at(i) + end_pos - num_of_zero_end;
            } else {
                begin_pos = num_of_zero_begin;
                end_pos = num_of_zero_begin + num_of_zero;
            }

            val = ((val << 1) | bit);
        }

        uint64_t left = 0;
        for(uint64_t i = 0; i < bit_size; ++i) {
            const uint64_t bit =
                (val >> (bit_size - i - 1)) & 1;  // 上からi番目のbit
            left = bit_arrays.at(i).rank(bit,
                                         left);  // cのi番目のbitと同じ数値の数
            if(bit) {
                left += this->begin_one.at(i);
            }
        }

        const uint64_t rank = begin_pos + k - left + 1;
        return select(val, rank) - 1;
    }

    // v[0, pos)のcの数
    uint64_t rank(uint64_t c, uint64_t pos) {
        assert(pos < size);
        if(c >= maximum_element) {
            return 0;
        }
        if(this->begin_alphabet.find(c) == this->begin_alphabet.end()) {
            return 0;
        }

        for(uint64_t i = 0; i < bit_size; ++i) {
            uint64_t bit = (c >> (bit_size - i - 1)) & 1;  // 上からi番目のbit
            pos =
                bit_arrays.at(i).rank(bit, pos);  // cのi番目のbitと同じ数値の数
            if(bit) {
                pos += this->begin_one.at(i);
            }
        }

        uint64_t begin_pos = this->begin_alphabet.at(c);
        return pos - begin_pos;
    }

    // v[begin_pos, end_pos)で[min, max)に入る値の個数
    uint64_t rangeFreq(uint64_t begin_pos, uint64_t end_pos, uint64_t min_c,
                       uint64_t max_c) {
        if((end_pos > size || begin_pos >= end_pos) || (min_c >= max_c) ||
           min_c >= maximum_element) {
            return 0;
        }

        const auto maxi_t = rankAll(max_c, begin_pos, end_pos);
        const auto mini_t = rankAll(min_c, begin_pos, end_pos);
        return std::get<1>(maxi_t) - std::get<1>(mini_t);
    }

    // v[0, pos)でcより小さい文字の数
    uint64_t rankLessThan(uint64_t c, uint64_t begin, uint64_t end) {
        auto t = rankAll(c, begin, end);
        return std::get<1>(t);
    }

    // v[0, pos)でcより大きい文字の数
    uint64_t rankMoreThan(uint64_t c, uint64_t begin, uint64_t end) {
        auto t = rankAll(c, begin, end);
        return std::get<2>(t);
    }

    // v[begin,
    // end)で(cと同じ値の数、cより小さい値の数、cより大きい値の数)を求める
    std::tuple<uint64_t, uint64_t, uint64_t> rankAll(const uint64_t c,
                                                     uint64_t begin,
                                                     uint64_t end) {
        assert(end <= size);
        const uint64_t num = end - begin;

        if(begin >= end) {
            return std::make_tuple(0, 0, 0);
        }
        if(c >= maximum_element || end == 0) {
            return std::make_tuple(0, num, 0);
        }

        uint64_t rank_less_than = 0, rank_more_than = 0;
        for(size_t i = 0; i < bit_size && begin < end; ++i) {
            const uint64_t bit = (c >> (bit_size - i - 1)) & 1;

            const uint64_t rank0_begin = this->bit_arrays.at(i).rank(0, begin);
            const uint64_t rank0_end = this->bit_arrays.at(i).rank(0, end);
            const uint64_t rank1_begin = begin - rank0_begin;
            const uint64_t rank1_end = end - rank0_end;

            if(bit) {
                rank_less_than +=
                    (rank0_end -
                     rank0_begin);  // i番目のbitが0のものは除外される
                begin = this->begin_one.at(i) + rank1_begin;
                end = this->begin_one.at(i) + rank1_end;
            } else {
                rank_more_than +=
                    (rank1_end -
                     rank1_begin);  // i番目のbitが1のものは除外される
                begin = rank0_begin;
                end = rank0_end;
            }
        }

        const uint64_t rank = num - rank_less_than - rank_more_than;
        return std::make_tuple(rank, rank_less_than, rank_more_than);
    }

    // T[s, e)で出現回数が多い順にk個の(値，頻度)を返す
    // 頻度が同じ場合は値が小さいものが優先される
    std::vector<std::pair<uint64_t, uint64_t>> topk(uint64_t s, uint64_t e,
                                                    uint64_t k) {
        assert(s < e);
        std::vector<std::pair<uint64_t, uint64_t>> result;

        // (頻度，深さ，値)の順でソート
        auto c = [](const std::tuple<uint64_t, uint64_t, uint64_t, uint64_t,
                                     uint64_t> &l,
                    const std::tuple<uint64_t, uint64_t, uint64_t, uint64_t,
                                     uint64_t> &r) {
            // width
            if(std::get<0>(l) != std::get<0>(r)) {
                return std::get<0>(l) < std::get<0>(r);
            }
            // depth
            if(std::get<3>(l) != std::get<3>(r)) {
                return std::get<3>(l) > std::get<3>(r);
            }
            // value
            if(std::get<4>(l) != std::get<4>(r)) {
                return std::get<4>(l) > std::get<4>(r);
            }
            return true;
        };

        std::priority_queue<
            std::tuple<uint64_t, uint64_t, uint64_t, uint64_t, uint64_t>,
            std::vector<
                std::tuple<uint64_t, uint64_t, uint64_t, uint64_t, uint64_t>>,
            decltype(c)>
            que(c);  // width, left, right, depth, value
        que.push(std::make_tuple(e - s, s, e, 0, 0));

        while(not que.empty()) {
            auto element = que.top();
            que.pop();
            uint64_t width, left, right, depth, value;
            std::tie(width, left, right, depth, value) = element;

            if(depth >= this->bit_size) {
                result.emplace_back(std::make_pair(value, right - left));
                if(result.size() >= k) {
                    break;
                }
                continue;
            }

            // 0
            const uint64_t left0 = this->bit_arrays.at(depth).rank(0, left);
            const uint64_t right0 = this->bit_arrays.at(depth).rank(0, right);
            if(left0 < right0) {
                que.push(std::make_tuple(right0 - left0, left0, right0,
                                         depth + 1, value));
            }

            // 1
            const uint64_t left1 = this->begin_one.at(depth) +
                                   this->bit_arrays.at(depth).rank(1, left);
            const uint64_t right1 = this->begin_one.at(depth) +
                                    this->bit_arrays.at(depth).rank(1, right);
            if(left1 < right1) {
                que.push(
                    std::make_tuple(right1 - left1, left1, right1, depth + 1,
                                    value | (1 << (bit_size - depth - 1))));
            }
        }

        return result;
    };

    // T[begin_pos, end_pos)でx <= c < yを満たすcの和を返す
    uint64_t rangeSum(const uint64_t begin, const uint64_t end,
                      const uint64_t x, const uint64_t y) {
        return rangeSum(begin, end, 0, 0, x, y);
    }

    // T[begin_pos, end_pos)でx <= c < yを満たす最大のcを返す
    uint64_t prevValue(const uint64_t begin_pos, const uint64_t end_pos,
                       const uint64_t x, uint64_t y) {
        assert(end_pos <= size);
        const uint64_t num = end_pos - begin_pos;

        if(x >= y or y == 0) {
            return NOTFOUND;
        }
        if(y > maximum_element) {
            y = maximum_element;
        }

        if(begin_pos >= end_pos) {
            return NOTFOUND;
        }
        if(x >= maximum_element || end_pos == 0) {
            return NOTFOUND;
        }

        y--;  // x <= c <= yにする

        std::stack<std::tuple<uint64_t, uint64_t, uint64_t, uint64_t, bool>>
            s;  // (begin, end, depth, c, tight)
        s.emplace(std::make_tuple(begin_pos, end_pos, 0, 0, true));

        while(not s.empty()) {
            uint64_t b, e, depth, c;
            bool tight;
            std::tie(b, e, depth, c, tight) = s.top();
            s.pop();

            if(depth == bit_size) {
                if(c >= x) {
                    return c;
                }
                continue;
            }

            const uint64_t bit = (y >> (bit_size - depth - 1)) & 1;

            const uint64_t rank0_begin = this->bit_arrays.at(depth).rank(0, b);
            const uint64_t rank0_end = this->bit_arrays.at(depth).rank(0, e);
            const uint64_t rank1_begin = b - rank0_begin;
            const uint64_t rank1_end = e - rank0_end;

            // d番目のbitが0のものを使う
            const uint64_t b0 = rank0_begin;
            const uint64_t e0 = rank0_end;
            if(b0 != e0) {  // 範囲がつぶれてない
                const uint64_t c0 = ((c << 1) | 0);
                s.emplace(
                    std::make_tuple(b0, e0, depth + 1, c0, tight and bit == 0));
            }

            // d番目のbitが1のものを使う
            const uint64_t b1 = this->begin_one.at(depth) + rank1_begin;
            const uint64_t e1 = this->begin_one.at(depth) + rank1_end;
            if(b1 != e1) {
                if(not tight or bit == 1) {
                    const auto c1 = ((c << 1) | 1);
                    s.emplace(std::make_tuple(b1, e1, depth + 1, c1, tight));
                }
            }
        }

        return NOTFOUND;
    }

    // T[begin_pos, end_pos)でx <= c < yを満たす最小のcを返す
    uint64_t nextValue(const uint64_t begin_pos, const uint64_t end_pos,
                       const uint64_t x, const uint64_t y) {
        assert(end_pos <= size);
        const uint64_t num = end_pos - begin_pos;

        if(x >= y or y == 0) {
            return NOTFOUND;
        }

        if(begin_pos >= end_pos) {
            return NOTFOUND;
        }
        if(x >= maximum_element || end_pos == 0) {
            return NOTFOUND;
        }

        std::stack<std::tuple<uint64_t, uint64_t, uint64_t, uint64_t, bool>>
            s;  // (begin, end, depth, c, tight)
        s.emplace(std::make_tuple(begin_pos, end_pos, 0, 0, true));

        while(not s.empty()) {
            uint64_t b, e, depth, c;
            bool tight;
            std::tie(b, e, depth, c, tight) = s.top();
            s.pop();

            if(depth == bit_size) {
                if(c < y) {
                    return c;
                }
                continue;
            }

            const uint64_t bit = (x >> (bit_size - depth - 1)) & 1;

            const uint64_t rank0_begin = this->bit_arrays.at(depth).rank(0, b);
            const uint64_t rank0_end = this->bit_arrays.at(depth).rank(0, e);
            const uint64_t rank1_begin = b - rank0_begin;
            const uint64_t rank1_end = e - rank0_end;

            // d番目のbitが1のものを使う
            const uint64_t b1 = this->begin_one.at(depth) + rank1_begin;
            const uint64_t e1 = this->begin_one.at(depth) + rank1_end;
            if(b1 != e1) {
                const auto c1 = ((c << 1) | 1);
                s.emplace(
                    std::make_tuple(b1, e1, depth + 1, c1, tight and bit == 1));
            }

            // d番目のbitが0のものを使う
            const uint64_t b0 = rank0_begin;
            const uint64_t e0 = rank0_end;
            if(b0 != e0) {
                if(not tight or bit == 0) {
                    const uint64_t c0 = ((c << 1) | 0);
                    s.emplace(std::make_tuple(b0, e0, depth + 1, c0, tight));
                }
            }
        }

        return NOTFOUND;
    }

    // T[s1, e1)とT[s2, e2)に共通して出現する要素を求める
    std::vector<std::tuple<uint64_t, uint64_t, uint64_t>> intersect(
        uint64_t _s1, uint64_t _e1, uint64_t _s2, uint64_t _e2) {
        assert(_s1 < _e1);
        assert(_s2 < _e2);

        std::vector<std::tuple<uint64_t, uint64_t, uint64_t>> intersection;

        std::queue<std::tuple<uint64_t, uint64_t, uint64_t, uint64_t, uint64_t,
                              uint64_t>>
            que;  // s1, e1, s2, e2, depth, value
        que.push(std::make_tuple(_s1, _e1, _s2, _e2, 0, 0));
        while(not que.empty()) {
            auto e = que.front();
            que.pop();
            uint64_t s1, e1, s2, e2, depth, value;
            std::tie(s1, e1, s2, e2, depth, value) = e;

            if(depth >= this->bit_size) {
                intersection.emplace_back(
                    std::make_tuple(value, e1 - s1, e2 - s2));
                continue;
            }

            // 0
            uint64_t s1_0 = this->bit_arrays.at(depth).rank(0, s1);
            uint64_t e1_0 = this->bit_arrays.at(depth).rank(0, e1);
            uint64_t s2_0 = this->bit_arrays.at(depth).rank(0, s2);
            uint64_t e2_0 = this->bit_arrays.at(depth).rank(0, e2);

            if(s1_0 != e1_0 and s2_0 != e2_0) {
                que.push(
                    std::make_tuple(s1_0, e1_0, s2_0, e2_0, depth + 1, value));
            }

            // 1
            uint64_t s1_1 = this->begin_one.at(depth) +
                            this->bit_arrays.at(depth).rank(1, s1);
            uint64_t e1_1 = this->begin_one.at(depth) +
                            this->bit_arrays.at(depth).rank(1, e1);
            uint64_t s2_1 = this->begin_one.at(depth) +
                            this->bit_arrays.at(depth).rank(1, s2);
            uint64_t e2_1 = this->begin_one.at(depth) +
                            this->bit_arrays.at(depth).rank(1, e2);

            if(s1_1 != e1_1 and s2_1 != e2_1) {
                que.push(std::make_tuple(s1_1, e1_1, s2_1, e2_1, depth + 1,
                                         value | (1 << bit_size - depth - 1)));
            }
        }

        return intersection;
    };

   private:
    uint64_t get_num_of_bit(uint64_t x) {
        if(x == 0) return 0;
        x--;
        uint64_t bit_num = 0;
        while(x >> bit_num) {
            ++bit_num;
        }
        return bit_num;
    }

    uint64_t rangeSum(const uint64_t begin, const uint64_t end,
                      const uint64_t depth, const uint64_t c, const uint64_t x,
                      const uint64_t y) {
        if(begin == end) {
            return 0;
        }

        if(depth == bit_size) {
            if(x <= c and c < y) {
                return c * (end - begin);  // 値 * 頻度
            }
            return 0;
        }

        const uint64_t next_c = ((uint64_t)1 << (bit_size - depth - 1)) |
                                c;  // 上からdepth番目のbitを立てる
        const uint64_t all_one_c =
            (((uint64_t)1 << (bit_size - depth - 1)) - 1) |
            next_c;  // depth以降のbitをたてる(これ以降全部1を選んだときの値)
        if(all_one_c < x or y <= c) {
            return 0;
        }

        // [begin, pos)のすべての要素は[x, y)
        if(x <= c and all_one_c < y) {
            return this->cumulative_sum.at(depth).at(end) -
                   this->cumulative_sum.at(depth).at(begin);
        }

        const uint64_t rank0_begin = this->bit_arrays.at(depth).rank(0, begin);
        const uint64_t rank0_end = this->bit_arrays.at(depth).rank(0, end);
        const uint64_t rank1_begin = begin - rank0_begin;
        const uint64_t rank1_end = end - rank0_end;

        return rangeSum(rank0_begin, rank0_end, depth + 1, c, x, y) +
               rangeSum(this->begin_one.at(depth) + rank1_begin,
                        this->begin_one[depth] + rank1_end, depth + 1, next_c,
                        x, y);
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

uint64_t solve(int N, int K, V<uint64_t> &A) {
    WaveletMatrix wm(A);
    print(wm.cumulative_sum);

    uint64_t ans = LONG_LONG_MAX;
    FOR(i, 0, N - K + 1) {
        uint64_t begin = i;
        uint64_t end = i + K;
        uint64_t idx = wm.quantileRange(begin, end, K / 2);
        uint64_t m = wm.access(idx);

        auto less_sum = wm.rangeSum(begin, end, 0, m);
        auto more_sum = wm.rangeSum(begin, end, m, 1000000010);

        auto less_freq = wm.rangeFreq(begin, end, 0, m);
        auto more_freq = wm.rangeFreq(begin, end, m, 1000000010);

        auto a = m * less_freq - less_sum;
        auto b = more_sum - m * more_freq;

        chmin(ans, a + b);
    }

    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    V<uint64_t> A(N);
    FOR(i, 0, N) {
        cin >> A[i];
    }

    print(solve(N, K, A));
}