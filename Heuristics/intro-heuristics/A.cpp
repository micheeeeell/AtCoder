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

    ofstream ofstr("out.txt");
    streambuf* strbuf;
    strbuf = std::cout.rdbuf( ofstr.rdbuf() );
    ll d; cin >> d;
    vector<ll> c(26);
    for(int i = 0; i < 26; i++) cin >> c[i];
    vector s(d, vector<ll>(26));
    rep(i,0,d)rep(j,0,26){
        cin >> s[i][j];
    }
    vector<ll> t;
    vector last(d+1, vector<ll>(26,-1));
    rep(i,0,d){
        Pll temp = {-INF, -1};
        rep(j,0,26)last[i+1][j] = last[i][j];
        ll tmp;
        rep(j,0,26){
            tmp = s[i][j] + c[j] * (i - last[i+1][j]);
            chmax(temp, {tmp, j});
        }
        debug(tmp, temp);
        t.emplace_back(temp.second + 1);
        last[i+1][temp.second] = i+1;
    }

    print(t);
    vector<ll> v(d+1);
    ll ans = 0;
    rep(i,0,d){
        ans += s[i][t[i]-1];
        rep(j,0,26)last[i+1][j] = last[i][j];
        last[i+1][t[i]-1] = i;
        ll sum = 0;
        rep(j,0,26)
            sum += c[j] * (i - last[i+1][j]);
        ans -= sum;
        v[i+1] = ans;
    }
    debug(v);
 
}