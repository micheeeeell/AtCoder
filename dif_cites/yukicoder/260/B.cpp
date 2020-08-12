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
    ll s,t; cin >> s >> t;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    s--;t--;
    vector<ll> used(n);
    ll ans = 0;
    if(n & 1){
        ll lp = s, rp = t;
        while(!used[lp]){
            used[lp] = used[rp] = 1;
            ans += a[lp] - a[rp];
            lp = (lp + 1) % n;
            rp = (rp - 1 + n) % n;
            if(lp == rp){
                ans += a[lp];
                used[lp] = 1;
                break;
            }
        }
        lp = (s + n - 1) % n, rp = (t + 1) % n;
        while(!used[lp]){
            if(lp == rp){
                ans += a[lp];
                used[lp] = 1;
                break;
            }
            used[lp] = used[rp] = 1;
            ans += a[lp] - a[rp];
            lp = (lp - 1 + n) % n;
            rp = (rp + 1) % n;
        }
    }
    else{
        if((s + t) & 1){
            ll lp = s, rp = t;
            while(!used[lp]){
                used[lp] = used[rp] = 1;
                ans += a[lp] - a[rp];
                lp = (lp + 1) % n;
                rp = (rp - 1 + n) % n;
                if(lp == rp){
                    ans += a[lp];
                    used[lp] = 1;
                    break;
                }
            }
            lp = (s + n - 1) % n, rp = (t + 1) % n;
            while(!used[lp]){
                if(lp == rp){
                    ans += a[lp];
                    used[lp] = 1;
                    break;
                }
                used[lp] = used[rp] = 1;
                ans += a[lp] - a[rp];
                lp = (lp - 1 + n) % n;
                rp = (rp + 1) % n;
            }
        }
        else{
            ll temp = 0;
            ll lp = s, rp = t;
            while(!used[lp]){
                used[lp] = used[rp] = 1;
                temp += a[lp] - a[rp];
                lp = (lp + 1) % n;
                rp = (rp - 1 + n) % n;
                if(lp == rp){
                    temp += a[lp];
                    used[lp] = 1;
                    break;
                }
            }
            lp = (s + n - 1) % n, rp = (t + 1) % n;
            while(!used[lp]){
                if(lp == rp){
                    temp -= a[rp];
                    used[lp] = 1;
                    break;
                }
                used[lp] = used[rp] = 1;
                temp += a[lp] - a[rp];
                lp = (lp - 1 + n) % n;
                rp = (rp + 1) % n;
            }
            ans = temp;
            debug(ans);
            temp = 0;
            fill(all(used), 0);
            lp = s, rp = t;
            while(!used[lp]){
                used[lp] = used[rp] = 1;
                temp += a[lp] - a[rp];
                lp = (lp + 1) % n;
                rp = (rp - 1 + n) % n;
                if(lp == rp){
                    temp -= a[rp];
                    used[rp] = 1;
                    break;
                }
            }
            lp = (s + n - 1) % n, rp = (t + 1) % n;
            while(!used[lp]){
                if(lp == rp){
                    temp += a[lp];
                    used[lp] = 1;
                    break;
                }
                used[lp] = used[rp] = 1;
                temp += a[lp] - a[rp];
                lp = (lp - 1 + n) % n;
                rp = (rp + 1) % n;
            }
            debug(temp);

            chmax(ans, temp);
        }
    }

    cout << ans << "\n";
}