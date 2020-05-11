// #define LOCAL
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
string to_string(const char* c) {return to_string((string)c);}
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

void YES(bool ok){
    cout << (ok ? "YES" : "NO") << endl;
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s[19];
    rep(i,19)cin >> s[i];
    auto c = [&](char c) -> pair<bool, bool>{
        vector<vector<ll>> used(19, vector<ll>(19,0));
        bool ok = false;
        bool d = false;
        bool al = true;
        ll dx[] = {1,1,-1,-1, 0, 0, 1, -1};
        ll dy[] = {1,-1,1,-1, 1, -1, 0, 0};
        ll dx2[4][2] = {{-1,1}, {0,0}, {1,-1}, {-1, 1}};
        ll dy2[4][2] = {{0,0}, {-1,1}, {1,-1}, {1, -1}};
        ll store = 0;
        rep(i,19)rep(j,19){
            if(s[i][j] == c){
                vector<ll> v, v2;
                bool t = false;
                bool u = false;
                rep(k,8){
                    ll nx = i, ny = j;
                    ll cnt = 0;
                    while(nx >= 0 && 19 > nx && ny >= 0 && 19 > ny && s[nx][ny] == c){
                        u |= used[nx][ny];
                        if(!(nx == i && ny == j))used[nx][ny] = 1;
                        nx += dx[k];ny += dy[k];
                        cnt++;
                    }
                    t |= cnt >= 5;
                    // cerr << c << "\n";
                    // debug(i,j,k,cnt);
                    if(cnt >= 5)v.emplace_back(cnt);
                }

                // 二つ目の数え方
                rep(k,4){
                    ll nx = i, ny = j;
                    ll cnt = 0;
                    // 戻れるだけ戻る
                    while(nx >= 0 && 19 > nx && ny >= 0 && 19 > ny && s[nx][ny] == c){
                        nx += dx2[k][0], ny += dy2[k][0];
                    }
                    while(nx >= 0 && 19 > nx && ny >= 0 && 19 > ny && s[nx][ny] == c){
                        nx += dx2[k][1], ny += dy2[k][1];
                        cnt++;
                    }
                    if(cnt >= 5)v2.emplace_back(cnt);
                }
                if(v.size() >= 2){
                    d = true;
                    store++;
                    if(*max_element(all(v)) > 5)al = false;
                }
                else if(v2.size() > 1){
                    store++;
                }
                used[i][j] = 1;
                if((u == false) && t && ok)al = false;
                ok |= t;
            }
        }
        if(store > 1)al = false;
        return {al, ok};
    };

    ll ocnt = 0, xcnt = 0;
    rep(i,19)rep(j,19){
        if(s[i][j] == 'o')ocnt++;
        if(s[i][j] == 'x')xcnt++;
    }
    bool al = true;
    if(abs(ocnt - xcnt) > 1)al = false;
    auto ob = c('o');
    auto xb = c('x');

    al &= ob.first; al &= xb.first;
    al &= !(ob.second & xb.second);
    if(ob.second)al &= ocnt > xcnt;
    if(xb.second)al &= xcnt == ocnt;
    debug(ob, xb);

    YES(al);
}