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

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<Pll> a(n);
    rep(i,n){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(all(a), greater<Pll>());
    // vector dp(n+1, vector<ll>(n+10));
    // rep(i,n){
    //     ll num = a[i].first, id = a[i].second;
    //     rep(j,i+1){
    //         chmax(dp[i+1][j+1], dp[i][j] + num * abs(id - j));
    //         chmax(dp[i+1][j], dp[i][j] + num * abs(n - i + j - 1 - id));
    //     }
    // }
    // print(dp);

    // インライン化
    vector<ll> dp2(n+1);
    rep(i,n){
        ll num = a[i].first, id = a[i].second;
        rrep(j,i+1){
            chmax(dp2[j+1], dp2[j] + num * abs(id - j));
            chmax(dp2[j], dp2[j] + num * abs(n - i + j - 1 - id));
        }
        // print(dp2);
    }
    ll ans = 0;
    rep(i,n+1)chmax(ans, dp2[i]);
    cout << ans << endl;
}