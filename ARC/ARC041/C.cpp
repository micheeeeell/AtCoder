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


signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll n,l; cin >> n >> l;
    using Pls = pair<ll, char>;
    vector<Pls> a(n);
    rep(i,n)cin >> a[i].first >> a[i].second;
    
    auto f = [&](vector<Pls> &v){
        ll ret = 0;
        ll lcnt = 0, rcnt = 0;
        for(auto &p : v){
            if(p.second == 'R')lcnt++;
            else rcnt++;
        }
        if(lcnt == 0){
            ll i = 1;
            for(auto &p : v)ret += p.first - i++;
            return ret;
        }
        if(rcnt == 0){
            ll i = l;
            reverse(all(v));
            for(auto &p : v)ret += i-- - p.first;
            return ret;
        }
        ll lpos, rpos;
        rep(i,v.size()-1){
            if(v[i].second == 'R' && v[i+1].second == 'L')lpos = v[i].first, rpos = v[i+1].first;
        }

        if(lcnt >= rcnt)lpos = rpos - 1;
        else rpos = lpos + 1;

        for(auto &p : v){
            if(p.second == 'R')continue;
            ret += p.first - rpos++;
        }
        reverse(all(v));
        for(auto &p : v){
            if(p.second == 'L')continue;
            ret += lpos-- - p.first;
        }
        return ret;
    };

    vector<Pls> temp, clear;
    ll ans = 0;
    rep(i,n-1){
        temp.emplace_back(a[i]);
        if(a[i].second == 'L' && a[i+1].second == 'R'){
            ans += f(temp);
            temp = clear;
        }
    }
    temp.emplace_back(a[n-1]);
    ans += f(temp);

    cout << ans << endl;
}