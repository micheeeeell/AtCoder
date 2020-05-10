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
    if (sizeof...(tail) != 0) cout << " ";
    print(forward<Tail>(tail)...);
}

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
    ll l, r, id;
    string s;
    state(){}
    state(ll l, ll r, string s, ll id):l(l), r(r), s(s), id(id) {};
};
void YES(bool ok){
    cout << (ok ? "Yes" : "No") << endl;
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    vector<state> v(n);
    ll lcnt = 0, rcnt = 0;
    string left, right;
    ll lid, rid;
    rep(i,n){
        string s;cin >> s;
        ll temp = 0;
        state t(0, 0, s, i);
        for(auto &c : s){
            if(c == ')')temp--;
            else temp++;
            chmin(t.l, temp);
        }
        reverse(all(s));
        temp = 0;
        for(auto &c : s){
            if(c == '(')temp--;
            else temp++;
            chmin(t.r, temp);
        }
        t.r = abs(t.r);
        t.l = abs(t.l);
        reverse(all(s));
        if(t.l == 0){
            if(chmax(rcnt, t.r)){
                left = s;
                lid = i;
            }
        }
        if(t.r == 0){
            if(chmax(lcnt, t.l)){
                right = s;
                rid = i;
            } 
        }
        v[i] = t;
        // debug(t.l);debug(t.r);
    }

    sort(all(v), [&](const auto &a, const auto &b){
        return (a.r - a.l) > (b.r - b.l);
    });
    string mid;
    rep(i,n){
        if( v[i].id != lid && v[i].id != rid)mid += v[i].s;
    }
    string ans = left + mid + right;
    ll temp = 0;
    // print(ans);print(left);print(right);
    bool ok = true;
    for(auto &c : ans){
        if(c == '(')temp++;
        else temp--;
        if(temp < 0)ok = false;
    }
    YES(ok && temp == 0);
}