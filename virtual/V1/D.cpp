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
    print(p.first, p.second);
}

vector<ll> sum(n_max), pat(n_max);
ll dfs(ll i,ll  x){
    if(x <= 0)return 0;
    if(sum[i] == x)return pat[i];
    if(i == 0)return 1;
    if(x == sum[i-1] + 2)return pat[i-1]+1;
    if(x > sum[i-1] + 2){
        return pat[i-1] + dfs(i-1, x - sum[i-1] - 2) + 1;
    }
    return dfs(i-1, x-1);
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll n,x; cin >> n >> x;
    // n--;

    sum[0] = 1;
    pat[0] = 1;
    reps(i,n){
        sum[i] = sum[i-1] * 2 + 3;
        pat[i] = pat[i-1] * 2 + 1;
    }
    // print(sum, 4);print(pat, 4);

    cout << dfs(n,x) << endl;
}