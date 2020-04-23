// #define _GLIBCXX_DEBUG
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
void print(const pair<T,U> &p){
    print(p.first, p.second);
}


signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll n,m; cin >> n >> m;
    vector<Pll> vec(n);
    rep(i,n)cin >> vec[i].second >> vec[i].first;

    vector<ll> a(m);
    rep(i,m) cin >> a[i];
    sort(all(vec),greater<Pll>());
    sort(all(a), greater<ll>());
    ll ans = 0;
    ll id = 0;
    priority_queue<Pll> pq;
    rep(i,m){
        while(id < n && vec[id].first >= a[i]){
            pq.emplace(Pll(vec[id].second, vec[id].first));
            id++;
        }
        while(!pq.empty() && pq.top().first > a[i]){
            pq.pop();
        }
        if(!pq.empty() && pq.top().first <= a[i]){
            // print(pq.top());
            pq.pop();
            ans++;
        }
        // debug(ans);
    }
    cout << ans << endl;
}