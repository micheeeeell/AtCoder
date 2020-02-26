#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
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

//狭義のLIS
ll N_LIS(vector<ll> a){
    vector<ll> dp(a.size(),INF);
    int n = a.size();
    rep(i,n){
        *lower_bound(all(dp), a[i]) = a[i];
    }
    // cout << lower_bound(all(dp), INF) - dp.begin() << endl;
    return lower_bound(all(dp), INF) - dp.begin();
}

//狭義のLDS
ll N_LDS(vector<ll> a){
    // fill(dp, dp + n_max, INF);
    int n = a.size();
    vector<int> b;
    reverse(all(a));
    return N_LIS(a);
}
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


int main(){
    ll n,a,b; cin >> n >> a >> b;
    vector<ll> ans;

    // for(int i = n - a + 1; i <= n; i++)ans.emplace_back(i);
    // reps(i,n-a-b+1)ans.emplace_back(i);
    // for(int i = n-a; ans.size() < n;i--)ans.emplace_back(i);


    for(int i = n - a + 1; i <= n; i++)ans.emplace_back(i);
    rreps(i,b-1)ans.emplace_back(i);
    ll max_ = n-a;
    while(ans.size() < n){
        for(int i = max(max_ - a + 1, b); i <= max_; i++)ans.emplace_back(i);
        max_ = min(max_ - a + 1, b-1) - 1;
    }

    print(ans);

    if(N_LIS(ans) != a || N_LDS(ans) != b)cout << -1 << endl;
    else print(ans);
}