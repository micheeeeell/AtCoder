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
    ll n = 100;
    vector<Pll> v(n);
    vector<Pll> last;
    ll h = 20, w = 20;
    vector mp(h, vector<ll>(w, INF));
    rep(i, 0, n) {
        auto& [x, y] = v[i];
        cin >> x >> y;
        mp[x][y] = i;
        
    }

    { 
        ll x = 0, y = 0;
        rep(i, 0, n) {
            last.emplace_back(Pll(x, y));

            if (i % 10 == 9) x++;
            else{
                if ((i / 10) & 1) {
                    y--;
                } else
                    y++;
            }
        }

        debug(last);
    }

    ll dx[] = {0,1,-1,0};
    ll dy[] = {1,0,0,-1};
    auto is_out = [&](ll x, ll y){
       if(x < 0 || x >= h || y < 0 || y >= w)return true;
       return false;
    };

    string ans;
    auto str = [&](const Pll now, const Pll next) {
        string res;
        auto [x, y] = now;
        auto [nx, ny] = next;
        if (nx > x)
            res += string(nx - x, 'D');
        else
            res += string(x - nx, 'U');
        if (ny > y)
            res += string(ny - y, 'R');
        else
            res += string(y - ny, 'L');

        return res;
    };
    auto hirou = [&](vector<ll> &pick) -> pair<pair<ll, ll>, string> {
        Pll now = {0, 0};

        vector<ll> used(n);
        string res;
        rep(i, 0, 100) {
            ll tmp = INF;
            Pll p;
            auto [x, y] = now;
            rep(nx, 0, h) rep(ny, 0, w) {
                if (mp[nx][ny] == INF || used[mp[nx][ny]]) continue;
                if (chmin(tmp, abs(nx - x) + abs(ny - y))){
                    p = {nx, ny};
                }
            }
            res += str(now, p);
            res += "I";
            pick.emplace_back(mp[p.first][p.second]);
            now = p;
            used[mp[p.first][p.second]] = 1;
        }

        return {now, res};
    };

    auto kubaru = [&](vector<ll> pick, Pll now) -> tuple<Pll, ll, string> {
        string res;
        reverse(all(pick));
        ll xb = min(10LL, now.first);
        for (auto id : pick) {
            res += str(now, {xb + last[id].first, last[id].second});
            res += "O";
            now = {xb + last[id].first, last[id].second};
        }
        return {now, xb, res};
    };

    auto kaisyu = [&](Pll now, ll xb) {
        string res;
        res += str(now, {xb, 0});
        ll x = xb, y = 0;
        res += "I";

        rep(i, 0, n-1) {
            if (i % 10 == 9){
                x++;
                res += "D";
            } else {
                if ((i / 10) & 1) {
                    y--;
                    res += "L";
                    
                } else {
                    y++;
                    res += "R";
                }
            }
            res += "I";
        }

        return res;
        
    };
    vector<ll> pick;
    auto [now, res] = hirou(pick);
    ans += res;

    debug(pick, now);

    auto tup = kubaru(pick, now);
    now = get<0>(tup);
    ll xb = get<1>(tup);
    res = get<2>(tup);
    ans += res;

    ans += kaisyu(now, xb);

    cout << ans << endl;
}