// #define LOCAL
#ifdef LOCAL
// #define _GLIBCXX_DEBUG
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
    ll n; cin >> n;
    priority_queue<Pll> lmax;
    priority_queue<Pll, vector<Pll>, greater<>> rmin;
    vector<Pll> v(n);
    rep(i,n){
        ll l,r; cin >> l >> r;
        lmax.emplace(l, i);
        rmin.emplace(r, i);
        v[i] = {l, r};
    }

    vector<ll> used(n);
    ll lans = 0;
    ll pos = 0;
    while(!lmax.empty() || !rmin.empty()){
        while(!lmax.empty() && used[lmax.top().second]){
            lmax.pop();
        }

        if(!lmax.empty()){
            auto l = lmax.top();lmax.pop();
            ll id = l.second;
            if(l.first > pos){
                lans += abs(l.first - pos);
                pos = l.first;
            }
            else{
                if(v[id].second < pos){
                    lans += abs(pos - v[id].second);
                    pos = v[id].second;
                }
            }
            used[id] = 1;
        }

        // debug(pos);

        while(!rmin.empty() && used[rmin.top().second]){
            rmin.pop();
        }
        
        if(!rmin.empty()){
            auto r = rmin.top();
            ll id = r.second;
            if(r.first < pos){
                lans += abs(pos - r.first);
                pos = r.first;
            }
            else{
                if(v[id].first > pos){
                    lans += abs(pos - v[id].first);
                    pos = v[id].first;
                }
            }
            used[id] = 1;
        }
        // debug(pos);
    }
    lans += abs(pos);

    pos = 0;
    fill(all(used), 0);
    rep(i,n){
        lmax.emplace(v[i].first, i);
        rmin.emplace(v[i].second, i);
    }
    ll rans = 0;
     while(!lmax.empty() || !rmin.empty()){
        
        while(!rmin.empty() && used[rmin.top().second]){
            rmin.pop();
        }
        
        if(!rmin.empty()){
            auto r = rmin.top();
            ll id = r.second;
            if(r.first < pos){
                rans += abs(pos - r.first);
                pos = r.first;
            }
            else{
                if(v[id].first > pos){
                    rans += abs(pos - v[id].first);
                    pos = v[id].first;
                }
            }
            used[id] = 1;
        }
        // debug(pos);

        while(!lmax.empty() && used[lmax.top().second]){
            lmax.pop();
        }

        if(!lmax.empty()){
            auto l = lmax.top();lmax.pop();
            ll id = l.second;
            if(l.first > pos){
                rans += abs(l.first - pos);
                pos = l.first;
            }
            else{
                if(v[id].second < pos){
                    rans += abs(pos - v[id].second);
                    pos = v[id].second;
                }
            }
            used[id] = 1;
        }

        // debug(pos);

    }
    rans += abs(pos);
    debug(lans, rans);
    cout << max(lans, rans) << endl;
}