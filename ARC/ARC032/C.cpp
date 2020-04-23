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
const int n_max = 1e6+10;
#define int ll

struct work{
    ll s, e, id;
    work(){s = -1;};
    // bool operator>(work *rhs){
    //     return (*this).s > (*rhs).s;
    // }
};

void print() {
    cout << endl;
}

// template <class Head, class... Tail>
// void print(Head&& head, Tail&&... tail) {
//     cout << head;
//     if (sizeof...(tail) != 0) cout << ' ';
//     print(forward<Tail>(tail)...);
// }

template <class T>
void print(vector<T> &vec) {
    for (auto& a : vec) {
        cout << a;
        if (&a != &vec.back()) cout << ' ';
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

void print(vector<work> &vec, ll k){
    ll n = vec.size();
    k = min(k, n);
    rep(i,k-1)cout << vec[i].id << " ";
    cout << vec[k-1].id << endl;
}
template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<work> w(n);
    rep(i,n){
        cin >> w[i].s >> w[i].e;
        w[i].id = i;
    }

    sort(all(w), [](const auto &a, const auto &b){
        return a.s > b.s;
    });
    vector<ll> dp(n_max);
    ll id = n_max-1;
    rep(i,n){
        work t =  w[i];
        for(; id > t.s; id--)chmax(dp[id-1], dp[id]);
        chmax(dp[t.s], dp[t.e] + 1);
        // print(dp, 12);
    }
    for(; id > 0; id--)chmax(dp[id-1], dp[id]);
    sort(all(w),[](const auto &a, const auto &b){
        return a.s < b.s;
    });
    ll num = dp[0], time = 0;
    vector<work> vec, clear;
    vector<ll> ans;
    for(ll id = 0; id < n; id++){
        work now = w[id];
        work nxt;
        if(id < n-1)nxt = w[id+1];
        if(dp[now.s] == dp[now.e] + 1 && dp[now.s] == num && now.s >= time){
            vec.emplace_back(now);
        }
        if(nxt.s == -1 || dp[now.s] != dp[nxt.s]){
            // debug(num);print(vec, n_max);
            num--;
            work min_ = *min_element(all(vec),[](const auto &a, const auto &b){
                return a.id < b.id;
            });
            ans.emplace_back(min_.id + 1);
            time = min_.e;
            vec = clear;
        }
    }

    // print(dp, 12);
    cout << ans.size() << endl;
    print(ans, n_max);
}