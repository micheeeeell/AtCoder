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
    vector<ll> v(n+1), w(n+1);
    for(int i = 0; i < n; i++) cin >> v[i+1] >> w[i+1];
    ll q; cin >> q;
    ll cnt = 0;
    vector<Pll> tmp, tmp2;
    vector<Pll> sum, sum2;

    rep(_,0,q){
        ll V, L; cin >> V >> L;
        cnt = 0;
        tmp.clear();tmp2.clear();
        sum.clear();sum2.clear();
        while(V){
            if(cnt & 1)tmp.emplace_back(Pll(v[V], w[V]));
            else tmp2.emplace_back(Pll(v[V], w[V]));
            V /= 2;
            cnt++;
        }
        ll n1 = tmp.size(), n2 = tmp2.size();
        ll sv, sw;
        rep(i,0,1LL << n1) {
            sv = 0, sw = 0;
            rep(j,0,n1){
                if((i >> j) & 1){
                    sv += tmp[j].first;
                    sw += tmp[j].second;
                }
            }
            if(sw <= L)sum.emplace_back(Pll(sw, sv));
        }
        rep(i,0,1LL << n2) {
            sv = 0, sw = 0;
            rep(j,0,n2){
                if((i >> j) & 1){
                    sv += tmp2[j].first;
                    sw += tmp2[j].second;
                }
            }
            if(sw <= L)sum2.emplace_back(Pll(sw, sv));
        }
        sort(all(sum2));
        rep(i,1,sum2.size()){
            chmax(sum2[i].second, sum2[i-1].second);
        }

        ll ans = 0;
        for(auto &p : sum){
            ll id = upper_bound(all(sum2), Pll(L - p.first, INF)) - sum2.begin();
            if(id)chmax(ans, p.second + sum2[id-1].second);
            else chmax(ans, p.second);
        }
        for(auto &p2: sum2){
            chmax(ans, p2.second);
        }
        cout << ans << "\n";
    }
}