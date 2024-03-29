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


signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,m; cin >> n >> m;
    vector<Pll> ans;
    if((n % 2) == 1){
        ll left = 1, right = n-1;

        while(m){
            ans.emplace_back(left, right);
            left++, right--;
            m--;
        }
    }
    else{
        vector<ll> use(n);
        ll left = 1;
        ll even_left = left + m + 1;
        while(m){
            if(m & 1){
                ll right = left + m;
                ans.emplace_back(left, right);
                left++;
            }
            else{
                ll right = even_left + m;
                ans.emplace_back(even_left, right);
                even_left++;
            }
            m--;
        }
    }

    for(auto p : ans){
        print(p);
    }
}