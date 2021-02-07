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
const long double pi = 3.14159265358979323846;
const long double eps = 1e-12;

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
        if (&a != &vec.back()) cout << "\n";
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
    ll base = 10;
    vector table(21, vector<ll>(21, INF));
    using state = tuple<ll, Pll, Pll, Pll>;
    queue<state> que;
    que.emplace(state{  0,
                        {1,0}, 
                        {0,0}, 
                        {0,1}});

    table[base + 1][base + 1] = 0;

    while(!que.empty()){
        auto [c, i, j, k] = que.front();
        if (c > 5) break;
        que.pop();
        if(j.first != k.first){
            if(i.first == k.first){
                swap(i, j);
            }
            else
                swap(i, k);
        }
        if (j.second != i.second) swap(j, k);
        debug(c, i, j, k);

        {
            ll x = j.first + k.first + base;
            ll y = j.second + k.second + base;
            if (chmin(table[x + j.first - 1][y + j.second], c + 1)) {
                que.emplace(state{c + 1, {j.first - 1, j.second}, j, k});
            }
            if (chmin(table[x + j.first - 1][y + k.second], c + 1)) {
                que.emplace(state{c + 1, {j.first - 1, k.second}, j, k});
            }
            if (chmin(table[x + j.first + 1][y + j.second], c + 1)) {
                que.emplace(state{c + 1, {j.first + 1, j.second}, j, k});
            }
            if (chmin(table[x + j.first + 1][y + k.second], c + 1)) {
                que.emplace(state{c + 1, {j.first + 1, k.second}, j, k});
            }
        }
        {
            ll x = i.first + j.first + base;
            ll y = i.second + j.second + base;
            if(chmin(table[x + i.first][y + i.second - 1], c + 1)){
                que.emplace(state{c + 1, i, j, {i.first, i.second - 1}});
            }
            if(chmin(table[x + j.first][y + i.second - 1], c + 1)){
                que.emplace(state{c + 1, i, j, {j.first, i.second - 1}});
            }
            if (chmin(table[x + i.first][y + i.second + 1], c + 1)) {
                que.emplace(state{c + 1, i, j, {i.first, i.second + 1}});
            }
            if (chmin(table[x + j.first][y + i.second + 1], c + 1)) {
                que.emplace(state{c + 1, i, j, {j.first, i.second + 1}});
            }
        }
        { 
            ll x = i.first + k.first + base;
            ll y = i.second + k.second + base;
            if(chmin(table[x + i.first][y + k.second], c +1)){
                que.emplace(state{c + 1, i, {i.first, k.second}, k});
            }
        }
        
    }
    vector<string> v(21, string(21, '.'));

    rep(i,0,21)rep(j,0,21){
        if(table[i][j] != INF){
            v[i][j] = '0' + table[i][j];
        }
    }
    print(v);
}