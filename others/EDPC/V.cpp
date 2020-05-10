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
   rep(i,k-1)cout << vec[i] << "\n";
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

ll modinv(ll a, ll m){
    ll b = m, u = 1, v = 0;
    while(b){
        ll t = a/b;
        a -= t * b; swap(a,b);
        u -= t * v; swap(u,v);
    }
    u %= m;
    if(u < 0) u += m;
    return u;

}

ll n, m;
vector<ll> sub(n_max);
vector<ll> dp(n_max);
void dfs(vvl &graph, ll pos, ll par = -1){
    ll ans = 1;
    for(auto &to : graph[pos]){
        if(to == par)continue;
        dfs(graph, to, pos);
        ans = ans * (sub[to] + 1) % m;
    }
    sub[pos] = ans;
}

void dfs2(vvl &graph, ll pos, ll par = -1){
    ll n = graph[pos].size();
    if(n == 0){
        dp[pos] = sub[pos];
        return ;
    }
    vector<ll> cum(n+1), cum2(n+1), num(n);
    cum[0] = 1;
    cum2[n] = 1;
    num[n-1] = 1;
    ll ans = 1;

    rep(i, n){
        ll to = graph[pos][i];
        if(to == par){
            num[i] = dp[pos];
            continue;
        }
        num[i] = sub[to] + 1;
        ans = (ans * (sub[to] + 1)) % m;
    }
    rep(i,n)cum[i+1] = (cum[i] * num[i]) % m;
    rreps(i,n)cum2[i-1] = (cum2[i] * num[i-1]) % m;
    // debug(pos);print(num);print(cum);print(cum2);
    sub[pos] = ans;
    rep(i,n){
        ll to = graph[pos][i];
        if(to == par)continue;
        dp[to] = (cum[i] * cum2[i+1] + 1) % m;
    }
    if(par == -1)dp[pos] = ans;
    else{
        for(auto &to : graph[pos]){
            if(to == par)continue;
            dp[pos] = dp[pos] * (sub[to] + 1) % m;
        }
    }
    for(auto &to : graph[pos]){
        if(to != par)dfs2(graph, to, pos);
    }
}


signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    vector<vector<ll>> graph(n);
    rep(i,n-1) {
        ll a,b;cin >> a >> b;
        a--;b--;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }

    dfs(graph, 0);
    dfs2(graph, 0);
    // print(sub, 5);
    print(dp,n);
}