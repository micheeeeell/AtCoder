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
struct item{
    ll i, l, r;
    item(){}
    item(ll i, ll l, ll r):i(i),l(l),r(r){};
    bool operator< (const item &rhs) const {
        return l - r < rhs.l - rhs.r;
    };
    bool operator> (const item &rhs) const {
        return l - r > rhs.l - rhs.r;
    };
};

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<item> le, ri;
        rep(_,0,n){
            ll i,l,r; cin >> i >> l >> r;
            if(l >= r)le.emplace_back(i,l,r);
            else ri.emplace_back(i,l,r);
        }
        sort(all(le),[&](const auto &a, const auto &b){
            return a.i < b.i;
        });
        sort(all(ri),[&](const auto &a, const auto &b){
            return a.i > b.i;
        });

        ll ans = 0;
        vector<item> rest,clear;
        using Plll = pair<ll, Pll>;
        priority_queue<item, vector<item>, greater<item>> pq;
        for(auto &i : le){
            if(pq.size() < i.i)pq.emplace(i);
            else{
                auto p = pq.top();pq.pop();
                if(p > i){
                    pq.emplace(p);
                    rest.emplace_back(i);
                }
                else {
                    pq.emplace(i);
                    rest.emplace_back(p);
                }
            }
        }

        while(!pq.empty()){
            auto p = pq.top();pq.pop();
            ans += p.l;
        }
        for(auto &i : rest) ans += i.r;
        rest=clear;
        priority_queue<item> ppq;
        for(auto &i : ri){
            if(i.i == n){
                rest.emplace_back(i);
                continue;
            }
            if(ppq.size() < n-i.i)ppq.emplace(i);
            else{
                auto p = ppq.top();ppq.pop();
                if(p < i){
                    ppq.emplace(p);
                    rest.emplace_back(i);
                }
                else {
                    ppq.emplace(i);
                    rest.emplace_back(p);
                }
            }
        }

        while(!ppq.empty()){
            auto p = ppq.top();ppq.pop();
            ans += p.r;
        }
        for(auto &i : rest) ans += i.l;
        rest.clear();
        cout << ans << "\n";
    }
}