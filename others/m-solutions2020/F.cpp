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
    vector<tuple<ll, ll, char>> v(n);
    vector<vector<tuple<ll,ll,char>>> xv(n_max), yv(n_max);
    rep(i,0,n){
        auto &[x,y,c] = v[i];
        cin >> x >> y >> c;
        xv[x].emplace_back(v[i]);
        yv[y].emplace_back(v[i]);
    }
    rep(i,0,n_max){
        sort(all(xv[i]));
        sort(all(yv[i]));
    }

    ll ans = INF;
    rep(i,0,n_max){
        ll pre = -INF;
        for(auto &[x,y,c] : xv[i]){
            if(c == 'U')pre = y;
            if(c == 'D' && pre != -INF){
                chmin(ans, (y - pre) * 5);
            }
        }

        pre = -INF;
        for(auto &[x,y,c] : yv[i]){
            if(c == 'R')pre = x;
            if(c == 'L' && pre != -INF){
                chmin(ans, (x - pre) * 5);
            }
        }
    }

    auto calc1 = [&](){
        vector<vector<tuple<ll, ll, char>>> tv(n_max * 2);
        rep(i,0,n){
            auto &[x,y,c] = v[i];
            tv[x + y].emplace_back(v[i]);
        }

        for(auto &t : tv){
            sort(all(t));
            ll rpre = -INF, dpre= -INF;
            for(auto &[x,y,c] : t){
                if(c == 'R')rpre = x;
                if(c == 'U' && rpre != -INF)chmin(ans, abs(rpre - x) * 10);
                if(c == 'D')dpre = y;
                if(c == 'L' && dpre != -INF)chmin(ans, abs(dpre - y) * 10);
            }
        }
    };

    auto calc2 = [&](){
        ll base = n_max;
        vector<vector<tuple<ll, ll, char>>> tv(n_max * 2);
        rep(i,0,n){
            auto &[x,y,c] = v[i];
            tv[y-x+base].emplace_back(v[i]);
        }

        for(auto &t : tv){
            sort(all(t));
            ll upre = -INF, rpre= -INF;
            for(auto &[x,y,c] : t){
                if(c == 'U')upre = y;
                if(c == 'L' && upre != -INF)chmin(ans, abs(upre - y) * 10);
                if(c == 'R')rpre = x;
                if(c == 'D' && rpre != -INF)chmin(ans, abs(rpre - x) * 10);
            }
        }
    };

    auto rotate = [&](){
        ll xt, yt;
        for(auto &[x,y,c] : v){
            if(c == 'L')c = 'U';
            if(c == 'U')c = 'R';
            if(c == 'R')c = 'D';
            if(c == 'D')c = 'L';
            xt = x, yt = y;
            x = yt;
            y = 2e5 - xt;
        }
    };

    rep(i,0,4){
        calc1();
        calc2();
        rotate();
    }
    if(ans == INF){
        cout << "SAFE" << "\n";
    }
    else{
        cout << ans << "\n";
    }
}