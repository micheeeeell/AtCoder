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
    using psl = pair<string, ll>;
    vector<psl> v(n);
    rep(i,0,n){
        string s;cin >> s;
        ll t; cin >> t;
        v[i] = {s, t};
    }
    auto dijkstra = [&](psl p) {
        ll ans = INF;
        using T = pair<ll, psl>;
        map<psl, ll> mp;
        mp[p] = 0;
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.emplace(T{0, p});
        while(!pq.empty()){
            auto [c, sl] = pq.top();
            debug(c, sl);
            pq.pop();
            auto [str, state] = sl;
            if(str == ""){
                ans = c;
                break;
            }
            ll m1 = str.size();
            if (state == 1) {
                for(auto [s, t] : v){
                    reverse(all(s));
                    bool tmp = true;
                    ll m2 = s.size();
                    if (m1 > m2) {
                        rep(i,0,m2){
                            tmp &= s[i] == str[i];
                        }
                        if (!tmp) continue;
                        string str2 = str.substr(m2);
                        psl P = {str2, state};
                        if(!mp.count(P) || chmin(mp[P], c + t)){
                            mp[P] = c + t;
                            pq.emplace(T(c + t, P));
                        }
                    }
                    else{
                        rep(i,0,m1){
                            tmp &= s[i] == str[i];
                        }
                        if (!tmp) continue;
                        string str2 = s.substr(m1);
                        reverse(all(str2));
                        psl P = {str2, -state};
                        if (!mp.count(P) || chmin(mp[P], c + t)) {
                            mp[P] = c + t;
                            pq.emplace(T(c + t, P));
                        }
                    }
                }
            }
            else{
                reverse(all(str));
                for (auto [s, t] : v) {
                    bool tmp = true;
                    ll m2 = s.size();
                    if (m1 > m2) {
                        rep(i, 0, m2) {
                            tmp &= s[i] == str[i];
                        }
                        if (!tmp) continue;
                        string str2 = str.substr(m2);
                        reverse(all(str2));
                        psl P = {str2, state};
                        if (!mp.count(P) || chmin(mp[P], c + t)) {
                            mp[P] = c + t;
                            pq.emplace(T(c + t, P));
                        }
                    } else {
                        rep(i, 0, m1) {
                            tmp &= s[i] == str[i];
                        }
                        if (!tmp) continue;
                        string str2 = s.substr(m1);
                        psl P = {str2, -state};
                        if (!mp.count(P) || chmin(mp[P], c + t)) {
                            mp[P] = c + t;
                            pq.emplace(T(c + t, P));
                        }
                    }
                }
            }
        }

        return ans;
    };

    ll ans = INF;
    for (auto [s, c] : v) {
        ll m1 = s.size();
        rep(j,0,m1){
            bool ok = true;
            ll t = 0;
            while(1){
                if (j + t >= m1 || j - t < 0) break;
                ok &= s[j + t] == s[j - t];
                t++;
            }
            if (!ok) continue;
            if((m1 & 1) && j == m1 / 2){
                chmin(ans, c);
            }
            else if(j < m1 / 2){
                chmin(ans, c + dijkstra(psl(s.substr(j * 2 + 1), 1)));
            }
            else{
                chmin(ans,
                      c + dijkstra(psl(s.substr(0, m1 - (m1 - j) * 2 + 1), -1)));
            }
        }

        debug(s, c, ans);
        rep(j, 0, m1 - 1) {
            bool ok = true;
            ll t = 0;
            while (1) {
                if (j + t + 1>= m1 || j - t < 0) break;
                ok &= s[j + t + 1] == s[j - t];
                t++;
            }
            if (!ok) continue;
            if((~m1 & 1) && j == m1 / 2 - 1){
                chmin(ans, c);
            }
            else if(j < m1 / 2){
                chmin(ans, c + dijkstra(psl(s.substr(2 * (j + 1)), 1)));
            }
            else{
                chmin(ans, c + dijkstra(psl(s.substr(0, m1 - (m1 - j - 1) * 2),
                                            -1)));
            }
        }
        debug(s, c, ans);

        chmin(ans, c + dijkstra(psl(s, 1)));
        chmin(ans, c + dijkstra(psl(s, -1)));
        debug(s, c, ans);
    }

    cout << (ans != INF ? ans : -1) << endl;
}