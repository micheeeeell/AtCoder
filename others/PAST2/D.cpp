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

// template <class Head, class... Tail>
// void print(Head&& head, Tail&&... tail) {
//     cout << head;
//     if (sizeof...(tail) != 0) cout << " ";
//     print(forward<Tail>(tail)...);
// }

template <class T>
void print(vector<T> &vec) {
    for (auto& a : vec) {
        cout << a;
        if (&a != &vec.back()) cout << " ";
    }
    cout << endl;
}

template <class T>
void print(vector<T> &vec, ll k){
   ll n = vec.size();
   k = min(k, n);
   rep(i,k-1)cout << vec[i] << " ";
   cout << vec[k-1] << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
    for (auto& vec : df) {
        print(vec);
    }
}

template<class T, class U>
void print(pair<T,U> &p){
    cout << p.first << " " << p.second << "\n";
}
ll n;
bool c(vector<ll> &v, vector<ll> &t){
    bool ok = false;
    ll k = t.size();
    if(k == 0)return false;
    if(k > n)return false;
    rep(i,n-k+1){
        bool temp = true;
        rep(j,k){
            if(t[j] == 26)continue;
            if(v[i+j] == t[j])continue;
            else temp = false;
        }
        ok |= temp;
    }
    return ok;
}

vector<ll> v(n_max), t;
ll ans = 0;
void dfs(ll cnt){
    if(c(v,t)){
        ans++;
        // print(t);
    }
    if(cnt == 3)return ;
    rep(i,27){
        t.emplace_back(i);
        dfs(cnt + 1);
        t.pop_back();
    }
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;cin >> s;
    n = s.size();
    rep(i,n)v[i] = s[i] - 'a';
    
    dfs(0);

    cout << ans << endl;
}