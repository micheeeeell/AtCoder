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
    ll n,k; cin >> n >> k;
    vector<ll> p(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    vector<ll> c(n);
    for(int i = 0; i < n; i++) cin >> c[i];
    k--;
    auto calc = [&](ll pos, ll num){
        vector<ll> used(n);
        used[pos] = 1;
        ll res = c[pos];
        ll tmp = c[pos];
        pos = p[pos];
        // num--;
        while(!used[pos]){
            tmp += c[pos];
            chmax(res, tmp);
            used[pos] = 1;
            pos = p[pos];
            num--;
            if(num <= 0)return res;
        }
        debug(pos, res, tmp);
        ll roop_val = 0;
        ll root = pos;
        ll cnt = 1;
        roop_val = c[root];
        pos = p[pos];
        while(pos != root){
            roop_val += c[pos];
            pos = p[pos];
            cnt++;
        }
        debug(pos, root, roop_val, cnt, num);
        if(roop_val < 0)return res;
        else{
            ll d = max((num / cnt) - 1, 0LL);

            tmp += roop_val * d;
            num -= d * cnt;

            debug(num);

            ll tmp2 = 0, plus = 0;
            while(num){
                num--;
                tmp2 += c[pos];
                pos = p[pos];
                chmax(plus, tmp2);
            }
            return max(res, tmp + plus);
        }
    };

    ll ans = -INF;
    rep(i,0,n){
        ll t = calc(p[i], k);
        debug(i, t);
        chmax(ans, t);
    }

    cout << ans << "\n";
}