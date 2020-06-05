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
const ld pi = acos(-1LL);
struct state{
    ll x, y;
    ld theta;
    state(){}
    state(ll x, ll y): x(x), y(y){
        theta = atan2l(y, x);
    }
    const bool operator>(state &rhs){
        return theta > rhs.theta;
    }
    const bool operator<(state &rhs){
        return theta < rhs.theta;
    }
};

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    vector<state> v(n);
    rep(i,n){
        ll x,y; cin >> x >> y;
        v[i] = state(x, y);
    }
    sort(all(v));
    rep(i,n){
        state temp = v[i];
        temp.theta += 2 * pi;
        v.emplace_back(temp);
    }
    for(auto &i : v){
        cerr << i.x << " " << i.y << " " << i.theta << endl;
    }
    vector<Pll> sum(2*n + 1);
    rep(i,2*n){
        sum[i+1].first = sum[i].first + v[i].x;
        sum[i+1].second = sum[i].second + v[i].y;
    }
    debug(sum);
    auto ub = [&](ld theta){
        ll ok = 0;
        ll ng = 2*n;
        while(abs(ok - ng) > 1){
            ll mid = (ok + ng) / 2;
            if(v[mid].theta <= theta)ok = mid;
            else ng = mid;
        }

        return ok;
    };
    ld ans = 0.0;
    // 誤差が怖いのでにぶたん→しゃくとりにする
    ll right = 0;
    Pll temp = {0,0};
    rep(left, n){
        while(right < (left+n) && hypot(v[right].x + temp.first, v[right].y + temp.second) >= hypot(temp.first, temp.second)){
            temp.first += v[right].x;
            temp.second += v[right].y;
            ++right;
        }
        debug(temp, left, right);
        ld t = hypot(temp.first, temp.second);
        chmax(ans, t);
        if(right == left) ++right;
        else{
            temp.first -= v[left].x;
            temp.second -= v[left].y;
        }
    }
    cout << fixed << setprecision(20);
    cout << ans << endl;
}