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

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}
using Plll = pair<ll, Pll>;

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
        if (&a != &vec.back()) cout << "\n";
    }
    cout << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
    for (auto& vec : df) {
        print(vec);
    }
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    vvl table(n);
    vector<ll> cnt(n);
    rep(i,n){
        ll k; cin >> k;
        cnt[i] = k;
        table[i].resize(k);
        rep(j,k){
            ll t; cin >> t;
            table[i][j] = t;
        }
    }
    // id管理,1列に1個しかないときに注意
    vvl v(n, vl(2));
    rep(i,n){
        v[i][0] = 0;
        v[i][1] = 1;
    }

    priority_queue<Plll> pq1, pq2;
    rep(i,n){
        pq1.emplace(table[i][0], Pll(i, 0));
        if(cnt[i] > 1)pq2.emplace(table[i][1], Pll(i, 1));
    }

    ll m; cin >> m;
    vector<ll> a(m), ans(m);
    rep(i,m) cin >> a[i];
    rep(i,m){
        if(a[i] == 1){
            auto [val, p]= pq1.top();pq1.pop();
            ll id = p.first;
            ans[i] = val;
            v[id][0] = v[id][1];v[id][1]++;
            if(v[id][0] < cnt[id])pq1.emplace(table[id][v[id][0]], Pll(id, v[id][0]));
            if(v[id][1] < cnt[id])pq2.emplace(table[id][v[id][1]], Pll(id, v[id][1]));
        }
        else{
            auto [val1, p] = pq1.top();
            ll id1 = p.first;
            while(!pq2.empty() && v[pq2.top().second.first][1] != pq2.top().second.second){
                pq2.pop();
            }
            ll val2, id2, jd2;
            if(!pq2.empty()){
                auto p = pq2.top();
                val2 = p.first;
                id2 = p.second.first;
                jd2 = p.second.second;
            }
            else{
                val2 = 0;
            }

            if(val1 > val2){
                pq1.pop();
                ans[i] = val1;
                v[id1][0] = v[id1][1];v[id1][1]++;
                if(v[id1][0] < cnt[id1])pq1.emplace(table[id1][v[id1][0]], Pll(id1, v[id1][0]));
                if(v[id1][1] < cnt[id1])pq2.emplace(table[id1][v[id1][1]], Pll(id1, v[id1][1]));
            }
            else{
                pq2.pop();
                ans[i] = val2;
                v[id2][1]++;
                if(v[id2][1] < cnt[id2])pq2.emplace(table[id2][v[id2][1]], Pll(id2, v[id2][1]));
            }
        }

        debug(v);
    }

    print(ans);
}