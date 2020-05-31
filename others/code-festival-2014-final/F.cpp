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

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

template <class T, class U>
ll euclid_gcd(T a, U b){
    if(a < b)return euclid_gcd(b,a);
    ll r;
    while((r = a%b)){
        a = b;
        b = r;
    }
    return b;
}
template <class T>
void print(vector<T> &vec, ll k){
    ll n = vec.size();
    k = min(k, n);
    rep(i,k-1)cout << vec[i] << " ";
    cout << vec[k-1] << endl;
}
template <class T>
void print(vector<vector<T>> &vec, ll k){
    ll n = vec[0].size();
    k = min(k, n);
    for(auto &i : vec)print(i, k);
}
void print(bitset<n_max> &bs, ll k){
    ll n = bs.size();
    k = min(k, n);
    rep(i,k-1)cout << bs[i] << " ";
    cout << bs[k-1] << endl;
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    vector<ll> b(n);
    rep(i,n) cin >> b[i];
    if(n == 1){
        cout << 0 << endl;
        return 0;
    }
    if(n == 2){
        if(b[0] == b[1]){
            cout << 0 << endl;
        }
        else {
            cout << 1 << endl;
        }
        return 0;
    }
    
    vector<ll> t = b;
    copy(all(t), back_inserter(b));
    bitset<n_max> bs(0);
    reps(i,2*n-2){
        ll g = euclid_gcd(b[i-1], b[i+1]);
        if(b[i] % g != 0)bs[i-1] = 1;
    }
    // print(bs, 15);
    ll ans = INF;
    reps(s, 3){
        bitset<n_max> t = bs;
        ll temp = 0;
        for(int i = s; i < s + n; i++){
            if(t[i-1]){
                temp++;
                t[i-1] = t[i] = t[i+1] = 0;
            }
        }
        chmin(ans, temp);
    }

    cout << ans << endl;
}