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
    vector<ll> a(n * 3);
    for(int i = 0; i < n * 3; i++) {
        cin >> a[i];
        a[i]--;
    }
    vector<ll> cnt(n);
    ll ans = 0;
    auto update = [&](vector<ll> &v){
        sort(all(v));
        if(v[0] != v[1] && v[1] != v[2]){
            bool ok = false;
            vector<ll> can(3);
            rep(i,0,3){
                if(cnt[v[i]] >= 2){
                    ok = true;
                    can[i] = 1;
                }
            }
            if(ok){
                ans++;
                fill(all(cnt), 0);
                rep(i,0,3){
                    if(can[i]){
                        rep(j,0,3){
                            if(i != j)cnt[v[j]] = 1;
                        }
                    }
                }
            }
            else{
                rep(i,0,3){
                    cnt[v[i]]++;
                }
            }
            return ;
        }
        if(v[0] == v[1] && v[1] == v[2]){
            ans++;
            return ;
        }
        if(v[1] == v[2]){
            swap(v[0], v[2]);
        }
        if(v[0] == v[1]){
            ll state = 0;
            if(cnt[v[0]]){
                state++;
            }
            if(cnt[v[2]] >= 2){
                state += 2;
            }

            debug(v, state);

            if(state == 0){
                cnt[v[0]] += 2;
                cnt[v[2]]++;
            }
            if(state == 1){
                ans++;
                cnt[v[0]]--;
                rep(i,0,n)chmin(cnt[i], 1LL);
                cnt[v[2]]++;
            }
            if(state == 2){
                ans++;
                fill(all(cnt), 0);
                cnt[v[0]] = 2;
            }
            if(state == 3){
                ans++;
                cnt[v[0]]--;
                rep(i, 0, n) chmin(cnt[i], 1LL);
                cnt[v[2]]++;
                cnt[v[0]] = 2;
            }
            return ;
        }
    };
    vector<ll> v(3);
    cnt[a[0]]++;cnt[a[1]]++;
    debug(cnt);
    rep(i,0,n-1){
        rep(j,0,3){
            v[j] = a[i * 3 + 2 + j];
        }
        update(v);
        debug(v, cnt);
    }
    if(cnt[a.back()] >= 2)ans++;

    cout << ans <<"\n";
}