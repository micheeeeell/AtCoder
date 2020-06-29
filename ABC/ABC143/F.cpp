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

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    vector<ll> cnt(n+1);
    for(int i = 0; i < n; i++){
        ll a;
        cin >> a;
        cnt[a]++;
    }
    vector<ll> v;
    rep(i,0,n+1){
        if(cnt[i])v.emplace_back(cnt[i]);
    }
    sort(all(v));
    ll m = v.size();
    vector<ll> sum(m+1);
    rep(i,0,m) sum[i+1] = sum[i] + v[i];

    auto c = [&](ll x, ll k){
        ll id = upper_bound(all(v), x) - v.begin();
        ll num = min(id, m);
        ll temp = sum.back();
        temp -= sum[m] - sum[id];
        temp += x * (m-id);
        return temp >= k * x;
    };

    rep(k,1,n+1){
        ll ok = 0, ng = n/k+1;
        while(abs(ok - ng) > 1){
            ll x = (ok + ng) / 2;
            if(c(x, k))ok = x;
            else ng = x;
        }
        cout << ok << "\n";
    }

}