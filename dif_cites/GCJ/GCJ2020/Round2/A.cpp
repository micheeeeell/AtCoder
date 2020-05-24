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

void Case(int x){
    cout << "Case #" << x + 1 << ": ";
}

void print() {
    cout << endl;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
    cout << head;
    if (sizeof...(tail) != 0) cout << " ";
    print(forward<Tail>(tail)...);
}

template <class T>
void print(vector<T> &vec) {
    for (auto& a : vec) {
        cout << a;
        if (&a != &vec.back()) cout << " ";
    }
    cout << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
    for (auto& vec : df) {
        print(vec);
    }
}

ll solve(ll r, ll k){
    if(r < k)return -1;
    ll ok = 0;
    ll ng = 1e9;
    while(abs(ok - ng) > 1){
        ll x = (ok + ng) / 2;
        if((2*k + 2 * x) * (x + 1) / 2 <= r)ok = x;
        else ng = x;
    }

    return ok;
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll t; cin >> t;
    rep(q, t){
        ll l,r; cin >> l >> r;
        bool flip = false;
        if(r > l){
            flip = true;
            swap(l,r);
        }
        ll ok = 1e9+1;
        ll ng = -1;
        while(abs(ok - ng) > 1){
            ll x = (ok + ng) / 2;
            if(l - r <= x * (x + 1) / 2)ok = x;
            else ng = x;
        }
        if(l < ok * (ok + 1) / 2){
            ok--;
        }
        l -= ok * (ok + 1) / 2;
        ok++;
        debug(l,r,ok);
        if(l < ok && r < ok){
            if(flip)swap(l, r);
            Case(q);
            print(ok-1, l, r);
            continue;
        }

        if(l == r){
            if(!flip)flip = true;
        }

        ll r1 = solve(r, ok);
        ll l1 = solve(l, ok + 1);
        ll ans = ok-1;
        debug(l1,r1);
        if(l1 + 1 == r1 || l1 == r1){
            ans += l1 + r1 + 2;
            l -= (ok + 1 + ok + 1 + 2 * l1) * (l1 + 1) / 2;
            r -= (ok + ok  + 2 * r1) * (r1 + 1) / 2;
        }
        else if(l1 < r1){
            ans += l1 * 2 + 3;
            l -= (ok + 1 + ok + 1 + 2 * l1) * (l1 + 1) / 2;
            r -= (ok + ok + 2 * (l1 + 1)) * (l1 + 2) / 2;
        }
        else{
            ans += r1 * 2 + 2;
            l -= (ok + 1 + ok + 1 + 2 * r1) * (r1 + 1) / 2;
            r -= (ok + ok + 2 * r1) * (r1 + 1) / 2;
        }

        if(flip)swap(l,r);
        Case(q);
        print(ans, l, r);

    }
}