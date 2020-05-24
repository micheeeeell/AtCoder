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


template<typename Monoid>
struct SlidingWindowAggregation {
    using F = function< Monoid(Monoid, Monoid) >;

    stack< Monoid > front,back;
    stack< Monoid > sum_front;
    Monoid sum_back;
    const F f;
    const Monoid M1;
    SlidingWindowAggregation (const F f, const Monoid &M1) : f(f), M1(M1) {
        sum_front.push(M1);
        sum_back = M1;
    }

    void push(Monoid x) {
        back.push(x);
        sum_back = f(sum_back, x);
    }

    void pop() {
        if(front.empty()) {
            while(! back.empty()) {
                front.push(back.top());
                sum_front.push(f(front.top(), sum_front.top()));
                back.pop();
            }
            sum_back = M1;
        }
        assert(! front.empty());
        front.pop();
        sum_front.pop();
    }

    Monoid accumulate() const {
        return f(sum_front.top(), sum_back);
    }
    
    bool empty() const {
        return front.empty() && back.empty();
    }

    size_t size() const {
        return front.size() + back.size();
    }
};


signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,p; cin >> n >> p;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> is_sorted(n);
    ll temp = 1;
    rrep(i,n-1){
        if(a[i] < a[i+1]){
            temp++;
        }
        else{
            temp = 1;
        }
        if(temp >= p)is_sorted[i] = 1;
    }

    debug(is_sorted);

    auto f = [&](ll a, ll b){return max(a, b);};
    auto g = [&](ll a, ll b){return min(a, b);};

    SlidingWindowAggregation<ll> s_min(g, INF), s_max(f, -1);
    rep(i,p){
        s_min.push(a[i]);
        s_max.push(a[i]);
    }
    ll ans = 0;
    bool sorted = false;
    for(int i = 0; i + p - 1 < n; i++){
        if(i == 0){
            ans++;
            sorted |= is_sorted[i];
            s_min.pop();
            s_max.pop();
            continue;
        }
        if(s_min.accumulate() < a[i-1] || s_max.accumulate() > a[i + p - 1]){
            if(!(sorted && is_sorted[i])){
                ans++;
                debug(i);
            }
        }
        
        s_min.pop();
        s_max.pop();
        s_min.push(a[i+p-1]);
        s_max.push(a[i+p-1]);
        sorted |= is_sorted[i];
        
    }

    cout << ans << endl;
}