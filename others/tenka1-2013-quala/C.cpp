#define LOCAL
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

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll n,m; cin >> n >> m;
    n = (n + 3) % 4 + 1;
    m = (m + 3) % 4 + 1;
    debug(n,m);
    vector<vector<ll>> t(n, vl(m));
    auto make = [&](ll k){
        // t.clear();
        vector<ll> vec(n * m);
        rep(i,n*m){
            vec[i] = k % 3 + 1;
            k /= 3;
        }
        rep(i,n){
            rep(j,m){
                t[i][j] = vec[i * m + j];
            }
        }
    };
    ll dx[] = {0,1,0,2,0,3};
    ll dy[] = {1,0,2,0,3,0};
    auto out = [&](ll x, ll y){
        if(x >= n || x < 0 || y >= m || y < 0)return true;
        return false;
    };
    auto check = [&](){
        bool ok = true;
        rep(i,n){
            rep(j,m){
                if(t[i][j] == 1){
                    rep(k,2){
                        ll nx = i + dx[k];
                        ll ny = j + dy[k];
                        if(out(nx,ny))continue;
                        ok &= t[nx][ny] != 1;
                    }
                }
                if(t[i][j] == 2){
                    rep(k,4){
                        ll nx = i + dx[k];
                        ll ny = j + dy[k];
                        if(out(nx,ny))continue;
                        ok &= t[nx][ny] != 2;
                    }
                }
                if(t[i][j] == 3){
                    rep(k,6){
                        ll nx = i + dx[k];
                        ll ny = j + dy[k];
                        if(out(nx,ny))continue;
                        ok &= t[nx][ny] != 3;
                    }
                }
            }
        }

        return ok;
    };

    ll ans = 0;
    rep(i,pow(3, n*m)){
        make(i);
        if(check())ans++;
        debug(i);
    }

    cout << ans << endl;
}