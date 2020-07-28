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

vector<ll> calc(ll n, vector<ll> &a){
    vector<ll> l_cnt(n);

    rep(i,1,n){
        ll l = a[i-1], r = a[i];
        bool is_rev = false;
        ll temp;
        if(!(l > r)){
            is_rev = true;
            swap(l, r);
            temp = l / (r * 4);
        }
        else{
            temp = (l + r - 1) / r;
            temp--;
        }
        ll p = 0;
        while(temp){
            p++;
            temp /= 4;
        }
        l_cnt[i] = p * 2 * (is_rev ? -1 : 1);
    }
    
    debug(l_cnt);
    vector<ll> l_sum(n+1);
    rep(i,0,n){
        l_sum[i+1] = l_sum[i] + l_cnt[i];
        chmax(l_sum[i+1], 0LL);
    }
    vector<ll> l_sum2 = l_sum;
    rep(i,0,n)l_sum2[i+1] += l_sum2[i];
    vector<ll> l_pos(n);
    ll id = n;
    rrep(i,n,0){
        l_pos[i] = id;
        if(l_cnt[i] > 0)id = i;
    }

    debug(l_sum, l_sum2, l_pos);
    vector<ll> res;;
    rep(i,0,n+1){
        ll t = 0;
        if(i < n){
            t = l_sum2[n] - l_sum2[l_pos[i]];
            t -= l_sum[l_pos[i]] * (n-l_pos[i]);
        }
        res.emplace_back(t);
    }
    return res;
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    auto l = calc(n, a);
    reverse(all(a));
    auto r = calc(n, a);
    reverse(all(r));
    debug(l, r);
    ll ans = INF;
    rep(i,0,n+1){
        chmin(ans, l[i] + r[i] + i);
    }
    cout << ans << "\n";
}