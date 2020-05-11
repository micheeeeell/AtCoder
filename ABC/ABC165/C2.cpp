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
const int q_max = 100;
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


template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}
struct state{
    state(){}
    ll a,b,c,d;
    bool operator>(state rhs){
        return d > rhs.d;
    };
    bool operator<(state rhs){
        return d < rhs.d;
    };
};
vector<state> v(q_max);
ll ans = 0;
ll n,m,q;
map<vector<ll>, ll> mp;
void dfs(vector<ll> &a){
    if(mp.find(a) != mp.end())return;
    // print(a);
    
    ll t = a.size();
    ll temp = 0;
    rep(i,q){
        if(a[v[i].b] - a[v[i].a] == v[i].c)temp += v[i].d;
    }
    chmax(ans, temp);
    mp[a] = temp;
    reps(i,t-2){
        if(a[i] + 1 <= m && a[i-1] <= a[i]+1 && a[i]+1 <= a[i+1]){
            a[i]++;
            dfs(a);
            a[i]--;
        }
    }
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    cin >> n >> m >> q;

    rep(i,q){
        cin >> v[i].a >> v[i].b >> v[i].c >> v[i].d;
        // v[i].a--;v[i].b--;
    }

    vector<ll> a(n+2);
    a[0] = 0;
    reps(i,n)a[i] = 1;
    a[n+1] = m+1;
    dfs(a);
    cout << ans << endl;
}