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

const int MOD = 1e9+7;
const int MAX = 1e5 + 10;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

void Case(int x){
    cout << "Case #" << x + 1 << ":\n";
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    COMinit();
    // print(com);   

    ll t; cin >> t;
    rep(q,t){
        bitset<n_max> bs(0);
        ll n; cin >> n;
        vector<Pll> ans;
        if(n < 201){
            reps(i,n)ans.emplace_back(Pll(i, i));
        }
        else {
            n -= 200;
            rreps(i, 199)if(n >= i){
                bs[i] = 1;
                n -= i;
            }
            reps(i,200){
                if(bs[i-1]){
                    ans.emplace_back(Pll(i, i-1));
                    // debug(i);
                }
                ans.emplace_back(Pll(i,i));
            }
        }

        // ll sum = 0;
        // for(auto &p : ans)sum += COM(p.first-1, p.second-1);

        Case(q);
        for(auto &p : ans)cout << p.first << " " << p.second << "\n";
        // cout << sum << endl;
    }
    return 0;
}