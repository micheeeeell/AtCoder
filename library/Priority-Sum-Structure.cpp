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

// スライドする区間の昇順(降順) k 個の総和を効率良く求めるデータ構造
// MinimumSum(k):昇順 k 個に指定
// MaximumSum(k): 降順 k 個に指定
// insert(x): 要素 x を追加する
// erase(x): 要素 x を削除する
// query(): 上位 k 個の和(要素数が k に満たないとき, 要素すべての和) を返す
// set_k(): k を指定しなおす
// get_k(): k を返す
// size(): 全体の要素数を返す
// verify: https://codeforces.com/contest/1398/problem/E
template <typename T, typename Compare = less<T>,typename Rcompare = greater<T> >
struct PrioritySumStructure {
    size_t k;
    T sum;

    priority_queue< T, vector<T>, Compare > in, d_in;
    priority_queue< T, vector<T>,  Rcompare > out, d_out;

    PrioritySumStructure(int k) :k(k), sum(0){}

    void modify(){
        while(in.size() - d_in.size() < k && !out.empty()){
            auto p = out.top();out.pop();
            if(!d_out.empty() && p == d_out.top()){
                d_out.pop();
            }
            else {
                sum += p;
                in.emplace(p);
            }
        }
        while(in.size() - d_in.size() > k){
            auto p = in.top();
            in.pop();
            if(!d_in.empty() && p == d_in.top()){
                d_in.pop();
            }
            else{
                sum -= p;
                out.emplace(p);
            }
        }
        while(!d_in.empty() && in.top() == d_in.top()){
            in.pop();
            d_in.pop();
        }
    }

    T query() const {
        return sum;
    }

    void insert(T x){
        in.emplace(x);
        sum += x;
        modify();
    }

    void erase(T x){
        assert(size());
        if(!in.empty() && in.top() == x) {
            sum -= x;
            in.pop();
        }
        else if(!in.empty() && Rcompare()(in.top(), x)){
            sum -= x;
            d_in.emplace(x);
        }
        else{
            d_out.emplace(x);
        }
        modify();
    }
    void set_k(size_t kk){
        k = kk;
        modify();
    }

    size_t get_k() const {
        return k;
    }

    size_t size() const {
        return in.size() + out.size() - d_in.size() - d_out.size();
    }
};

template <typename T>
using MaximumSum = PrioritySumStructure< T, greater<T>, less<T> >;

template <typename T>
using MinimumSum = PrioritySumStructure< T, less<T>, greater<T> >;

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    MaximumSum<ll> psum(0);
    multiset<ll> tw;
    ll sum = 0;
    rep(i,0,n){
        ll t,d; cin >> t >> d;
        sum += d;
        if(d > 0){
            if(t){
                psum.set_k(psum.get_k() + 1);
                if(tw.empty()){
                    tw.insert(d);
                }
                else{
                    if(*tw.begin() > d){
                        psum.insert(*tw.begin());
                    }
                    else{
                        psum.insert(d);
                    }
                    tw.insert(d);
                }
            }
            else{
                psum.insert(d);
            }
        }
        else{
            if(!t){
                psum.erase(-d);
            }
            else{
                psum.set_k(psum.get_k() - 1);
                if(-d == *tw.begin()){
                    tw.erase(tw.begin());
                    if(!tw.empty())psum.erase(*tw.begin());
                }
                else{
                    tw.erase(-d);
                    psum.erase(-d);
                }
            }
        }

        cout << psum.query() + sum << "\n";
    }
}