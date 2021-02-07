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

template <typename T>
int comp(T a){
    if (abs(a) < eps) return 0;
    return a > 0 ? 1 : -1;
}

template <typename T>
int comp(T a, T b){
    // a > b -> 1, a < b -> -1
    return comp(a - b);
}
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

struct BigInt {
    vector<ll> v;
    int digit = 18;
    int max_ = pow(10, digit);
    BigInt(){
        v = {0};
    };
    BigInt(const int i){
        int n = i;
        while (n) {
            v.emplace_back(n % max_);
            n /= max_;
        }
        reverse(v.begin(), v.end());
        if (v.empty()) v.emplace_back(0);
    }
    BigInt(const string &s) {
        int n = s.size();
        if(n == 0){
            v.emplace_back(0);
        }
        else{
            int r = (n + digit - 1) % digit + 1;
            v.emplace_back(stoll(s.substr(0, r)));
            while (r< n) {
                v.emplace_back(stoll(s.substr(r, digit)));
                r += digit;
            }
        }
    }

    BigInt operator+(const BigInt rhs){
        return BigInt(*this) += rhs;
    }
    BigInt operator-(const BigInt rhs){
        return BigInt(*this) -= rhs;
    }
    BigInt &operator+=(BigInt rhs){
        int t = 0;
        reverse(v.begin(), v.end());
        vector<int> tmp = rhs.v;
        reverse(tmp.begin(), tmp.end());
        int n = max(v.size(), tmp.size());
        v.resize(n);
        tmp.resize(n);
        for (int i = 0; i < n; i++) {
            v[i] = v[i] + tmp[i] + t;
            if(v[i] >= max_){
                t = 1;
                v[i] -= max_;
            }
            else
                t = 0;
        }
        if (t) v.emplace_back(1);
        reverse(v.begin(), v.end());
        return *this;
    }
    BigInt &operator-=(BigInt rhs){
        vector<int> tmp = rhs.v;
        reverse(v.begin(), v.end());
        reverse(tmp.begin(), tmp.end());
        int n = max(v.size(), tmp.size());
        v.resize(n);
        tmp.resize(n);
        reverse(tmp.begin(), tmp.end());
        reverse(v.begin(), v.end());
        for (int i = 0; i < n; i++){
            v[i] -= tmp[i];
            if(v[i] < 0 && i != 0){
                v[i] += max_;
                rrep(j, i, 0){
                    if (v[j] == 0 && j != 0) v[j] = max_ - 1;
                    else{
                        v[j]--;
                        break;
                    }
                }
            }
        }
        reverse(v.begin(), v.end());
        while(v.size() > 1 && v.back() == 0){
            v.pop_back();
        }
        reverse(v.begin(), v.end());
        return *this;
    }

    string val(){
        string res;
        int n = v.size();
        rep(i,0,n){
            if(!i)res += to_string(v[i]);
            else{
                string r = to_string(max_ + v[i]);
                res += r.substr(1);
            }
        }
        return res;
    }
};
signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;cin >> s;
    if(s[0] == '0'){
        s = "1" + s;
    }
    if(s.size() == 1){
        cout << s << " " << 1 << endl;
        return 0;
    }
    ll n = s.size();
    BigInt a = 0;
    ll j = 1;
    while (j < n && s[j] == '0') {
        j++;
    }
    if (j == n) {
        cout << s << " " << 1 << endl;
        return 0;
    }

    a = BigInt(s.substr(0, j));
    debug(a.v, j, s);

    while (s.size() <= j * 2) s += '0';
    debug(s);
    ll m = s.size();
    rep(i, j + 1, m + 1){
        BigInt r = s.substr(j, i - j);
        debug(r.v);
        string tmp = a.val();
        r -= a;
        debug(r.v);
        if (r.v[0] < 0) continue;
        if (r.v[0] == 0) r.v[0] = 1;
        BigInt t = a;
        while(tmp.size() < n){
            t += r;
            tmp += t.val();
        }
        debug(tmp);
        debug(s);
        if (tmp.substr(0, n) == s.substr(0, n)) {
            cout << a.val() << " " << r.val() << "\n";
            return 0;
        }
    }
}