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


signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    vector<ll> h(n);
    rep(i,n) cin >> h[i];
    vector<ll> front(n), back(n);
    vector<Pll> stack;
    stack.emplace_back(Pll(INF, -1));
    rep(i,n){
        while(!stack.empty() && stack.back().first <= h[i]){
            stack.pop_back();
        }
        front[i] = stack.back().second;
        stack.emplace_back(Pll(h[i], i));
    }
    stack.clear();
    stack.emplace_back(Pll(INF, n));
    rrep(i,n){
        while(!stack.empty() && stack.back().first <= h[i]){
            stack.pop_back();
        }
        back[i] = stack.back().second;
        stack.emplace_back(Pll(h[i], i));
    }

    // print(front);print(back);
    vector<ll> ans(n);
    rep(i,n){
        ans[i] = i - front[i] - 1;
        ans[i] += back[i] - i - 1;
    }
    print(ans);
}