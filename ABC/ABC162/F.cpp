#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define rrep(i,x) for(ll i = (ll)(x)-1;0 <= i; i--)
#define reps(i,x) for(ll i = 1; i < (ll)(x)+1; i++)
#define rreps(i,x) for(ll i = (ll)(x); 1 <= i; i--)
#define debug(x) cerr << #x << ": " << (x) << "\n";
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
const ll INF = numeric_limits<ll>::max()/4;
const int n_max = 1e5+10;
#define int ll

void print() {
    cout << endl;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
    cout << head;
    if (sizeof...(tail) != 0) cout << ' ';
    print(forward<Tail>(tail)...);
}

template <class T>
void print(vector<T> &vec) {
    for (auto& a : vec) {
        cout << a;
        if (&a != &vec.back()) cout << ' ';
    }
    cout << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
    for (auto& vec : df) {
        print(vec);
    }
}

template<class T, class U>
void print(pair<T,U> &p){
    print(p.first, p.second);
}

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

vector<ll> memo(n_max, 0);
ll dfs(vector<ll> &a,vector<ll> &odd ,ll s, ll k){
    ll n = a.size();
    ll t1, t2, t3;
    // if(memo[s]) return memo[s];
    if(k == 0)return 0;
    if(s == n)return 0;
    if(k * 2 > n - s){
        if(k*2-1 != n-s)return 0;
        // debug(s);
        // debug(odd[n] - odd[s]);
        return odd[n] - odd[s];
    }
    t1 = a[s] + dfs(a, odd, s+2, k-1);
    t2 = a[s+1] + dfs(a, odd, s+3, k-1);
    t3 = dfs(a, odd, s+2, k);
    // debug(s);debug(k);debug(t1);debug(t2);debug(t3);
    return max({t1, t2, t3});
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> even(n+1, 0), odd(n+1, 0);
    rep(i,n){
        if(n % 2 == 0){
            if(i & 1){
                odd[i+1] = odd[i] + a[i];
                even[i+1] = even[i];
            }
            else{
                even[i+1] = even[i] + a[i];
                odd[i+1] = odd[i];
            }
        }
        else {
            if(i % 2 == 0){
                odd[i+1] = odd[i] + a[i];
                even[i+1] = even[i];
            }
            else{
                even[i+1] = even[i] + a[i];
                odd[i+1] = odd[i];
            }

        }
    }
    // print(even);print(odd);
    ll ans = dfs(a, odd, 0, n/2);
    cout << ans << endl;
}