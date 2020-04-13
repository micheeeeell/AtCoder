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


signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    string s;cin >> s;
    vector<ll> sv(n);
    rep(i,n){
        if(s[i] == 'R')sv[i] = 1;
        if(s[i] == 'G')sv[i] = 2;
        if(s[i] == 'B')sv[i] = 3;
    }
    vector vec(3, vector<ll>(n+1, 0LL));
    rrep(i,n){
        rep(j,3)vec[j][i] = vec[j][i+1];
        if(s[i] == 'R')vec[0][i]++;
        if(s[i] == 'G')vec[1][i]++;
        if(s[i] == 'B')vec[2][i]++;
    } 

    // print(vec);
    ll ans = 0;
    rep(i,n)rep(j,n){
        if(i >= j)continue;
        if(j == n-1)continue;
        if(s[i] == s[j])continue;
        ll next = sv[i] ^ sv[j];
        next--;
        // debug(next);
        ans += vec[next][j+1];
        if(j*2-i < n && sv[j*2-i] == next+1)ans--;
        // debug(i);debug(j);debug(ans);
    }

    cout << ans << endl;
}