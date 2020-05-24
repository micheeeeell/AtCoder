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

template <class T>
void print(vector<T> &vec, ll k){
    ll n = vec.size();
    k = min(k, n);
    rep(i,k-1)cout << vec[i] << " ";
    cout << vec[k-1] << endl;
}
template <class T>
void print(vector<vector<T>> &vec, ll k){
    ll n = vec[0].size();
    k = min(k, n);
    for(auto &i : vec)print(i, k);
}

void print(bitset<n_max> &vec, ll k){
    ll n = vec.size();
    k = min(k, n);
    rep(i,k-1)cout << vec[i] << " ";
    cout << vec[k-1] << endl;
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll n,m; cin >> n >> m;
    vector<vector<ll>> graph(n);
    vector<ll> from(m), to(m);
    rep(i,m) {
        ll a,b;cin >> a >> b;
        a--;b--;
        graph[a].emplace_back(b);
        // graph[b].emplace_back(a);
        from[i] = a; to[i] = b;
    }
    string s;cin >> s;
    ll root = 0;
    vector<ll> v;
    ll pos;
    rep(i,s.size()){
        if(root == 0 && s[i] == '"')continue;
        ll t = s[i] - '0';
        if(t < 10 && t >= 0){
            root = root * 10 + t;
            continue;
        }
        if(root == 0)continue;
        debug(s[i]);
        pos = i;
        break;
    }

    if(pos < s.size() && s[pos] == 'w'){
        v.emplace_back(1);
        pos++;
    }
    else {
        v.emplace_back(0);
    }
    while(pos < s.size()){
        if(pos + 1 < s.size() && s[pos+1] == 'w'){
            v.emplace_back(1);
            pos += 3;
        }
        else{
            v.emplace_back(0);
            pos++;
        }

    }

    debug(v, root);
    root--;

    bitset<n_max> bs[v.size() + 1];
    rep(i,v.size()+1)bs[i] = 0;
    bs[0][root] = 1;
    rep(i, v.size()){
        ll c = v[i];
        if(c){
            rep(j,m){
                if(bs[i][to[j]]) bs[i+1][from[j]] = 1;
            }
        }
        else{
            vector<ll> cnt(n);
            rep(j,m){
                if(bs[i][to[j]]) cnt[from[j]]++;
            }
            ll temp = bs[i].count();
            rep(k,n){
                if(cnt[k] != temp)bs[i+1][k] = 1;
            }
        }
        // print(bs[i+1], 5);
    }

    // vector<ll> ans;
    // rep(i,n){
    //     if(bs[v.size()][i])ans.emplace_back(i+1);
    // }
    // print(ans, n_max);
    cout << bs[v.size()].count() << endl;
}