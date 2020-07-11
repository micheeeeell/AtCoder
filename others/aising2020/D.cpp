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
    ll n; cin >> n;
    string x;cin >> x;
    ll sum = 0;
    rep(i,0,n)sum += x[i] == '1';
    vector<ll> ans(n);
    if(sum == 1){
        rep(i,0,n){
            if(x[i] == '1')ans[i] = 0;
            else{
                if(i != n-1)ans[i] = 1;
                else ans[i] = 2;
            }
        }
        print(ans);
        return 0;
    }
    if(sum == 0){
        rep(i,0,n){
            cout << 1 << "\n";
        }
        return 0;
    }
    vector<ll> mod1(n), mod2(n);
    mod1[0] = 1 % (sum+1);
    mod2[0] = 1 % (sum-1);
    rep(i,0,n-1){
        mod1[i+1] = (mod1[i] * 2) % (sum+1);
        mod2[i+1] = (mod2[i] * 2) % (sum-1);
    }
    reverse(all(mod1));
    reverse(all(mod2));
    debug(sum,mod1, mod2);
    ll sum1 = 0, sum2 = 0;
    rep(i,0,n){
        sum1 += mod1[i] * (x[i] == '1');
        sum2 += mod2[i] * (x[i] == '1');
        sum1 %= (sum+1);
        sum2 %= (sum-1);
    }
    debug(sum1, sum2);

    rep(i,0,n){
        ll t = 0, cnt = 1;
        if(x[i] == '1'){
            t = sum2 - mod2[i];
            t %= sum-1;
            while(t < 0)t += sum-1;
        }
        else{
            t = sum1 + mod1[i];
            t %= sum+1;
        }
        debug(t);
        while(t){
            t %= __builtin_popcountll(t);
            cnt++;
        }
        cout << cnt << "\n";
    }
}