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
    ll n,l,t; cin >> n >> l >> t;
    vector<Pll> pos(n);
    vector<Pll> u, v;
    bool is_p = true;
    rep(i, 0, n) {
        ll x,w; cin >> x >> w;
        if(i == 0){
            is_p = w == 1;
        }
        if(w == 1){
            u.emplace_back(Pll{i, x});
        }
        else
            v.emplace_back(Pll{i, x});
        pos[i] = {x, w};
    }

    if(u.size() == 0 || v.size() == 0){
        if(u.size()){
            for(auto &x : pos){
                cout << (x.first + t) % l << "\n";
            }
        }
        else{
            for(auto &x : pos){
                ll res = (x.first - t) % l;
                cout << (res + l) % l << "\n";
            }
        }
        return 0;
    }

    ll us = u.size(), vs = v.size();

    vector<ll> usum(us + 1), vsum(vs + 1);
    rep(i,0,us){
        usum[i + 1] =
            usum[i] +
            (u[(us - i) % us].second + l - u[(2 * us - i - 1) % us].second) % l;
    }
    rep(j,0,vs){
        vsum[j + 1] = vsum[j] + (v[(j + 1) % vs].second + l - v[j].second) % l;
    }

    auto check = [&](ll x) {
        ll time = 0;
        ll ux = is_p ? (x + 1) / 2 : x / 2;
        ll vx = x - ux;
        if(INF / l > (ux / us))
            time += l * (ux / us);
        else
            time = INF;
        ux %= us;
        if((INF - time) / l > (vx / vs))
            time += l * (vx / vs);
        else
            time = INF;
        vx %= vs;

        if(time >= INF){
            return false;
        }

        time += usum[ux];
        time += vsum[vx];
        debug(x, time);
        return time <= t;
    };

    ll ok = 0, ng = 1e9 + 10;

    while(abs(ok - ng) > 1){
        ll x = (ok + ng) / 2;
        if (check(x)) ok = x;
        else
            ng = x;
    }
    debug(ok);
    ll last = 0;
    if (ok & 1) {
        if(is_p){
            ll ux = (ok + 1) / 2;
            ux %= us;
            last = (us - ux) % us;
            last = u[ux].first;
        }
        else{
            ll vx = (ok + 1) / 2;
            vx %= vs;
            last = (vs + vx) % vs;
            last = v[vx].first;
        }
    }
    else{
        if(is_p){
            ll vx = ok / 2;
            vx %= vs;
            last = (vs + vx) % vs;
            last = v[vx].first;
        }
        else{
            ll ux = ok / 2;
            ux %= us;
            last = (us - ux) % us;
            last = u[ux].first;
        }
    }


    for(auto &x : pos){
        if(x.second == 1){
            x.first += t;
        }
        else
            x.first -= t;
        x.first %= l;
        if (x.first < 0) x.first += l;
    }
    ll lpos = pos[last].first;

    sort(all(pos));
    ll id = lower_bound(all(pos), Pll{lpos, 0}) - pos.begin();
    rep(i,0,n){
        cout << pos[(id + i) % n].first << "\n";
    }
}