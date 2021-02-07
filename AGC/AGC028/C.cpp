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

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    vector<Pll> v(n);
    vector<Pll> x;
    rep(i, 0, n) {
        ll a,b; cin >> a >> b;
        v[i] = {a, b};
        x.emplace_back(Pll(a, (i << 1)));
        x.emplace_back(Pll(b, (i << 1) | 1));
    }
    sort(all(x));

    ll res = INF;

    {
        ll ta = 0, tb = 0;
        rep(i, 0, n){
            ta += v[i].first;
            tb += v[i].second;
        }
        chmin(res, ta);
        chmin(res, tb);
    }
    debug(res);
    vector used(n, vector<ll>(2));
    priority_queue<Pll> pq;
    ll sum = 0;
    rep(i, 0, n) {
        auto [val, flag] = x[i];
        debug(val, flag);
        used[flag >> 1][flag & 1] = 1;
        pq.emplace(x[i]);
        sum += val;
    }
    debug(used);
    rep(i, 0, n) {
        if (used[i][0] && used[i][1]) {
            chmin(res, sum);
            continue;
        }
        if(used[i][0] + used[i][1] == 0){
            Pll t1 = pq.top();
            pq.pop();
            Pll t2 = pq.top();
            pq.pop();
            ll tmp = sum - t1.first - t2.first;
            chmin(res, tmp + v[i].first + v[i].second);
            pq.emplace(t1);
            pq.emplace(t2);
        }
        else if(used[i][0] == 0){
            Pll t1 = pq.top();
            pq.pop();
            Pll t2 = pq.top();
            pq.pop();
            if((t1.second >> 1) != i){
                chmin(res, sum - t1.first + v[i].first);
            }
            else{
                chmin(res, sum - t2.first + v[i].first);
            }
            pq.emplace(t1);
            pq.emplace(t2);
        }
        else {
            Pll t1 = pq.top();
            pq.pop();
            Pll t2 = pq.top();
            pq.pop();
            debug(t1, t2);
            if ((t1.second >> 1) != i) {
                chmin(res, sum - t1.first + v[i].second);
            } else {
                chmin(res, sum - t2.first + v[i].second);
            }
            pq.emplace(t1);
            pq.emplace(t2);
        }
        debug(i, res, sum);
    }

    cout << res << endl;
}