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
template<class T, class U>
void print(pair<T,U> &p){
    print(p.first, p.second);
}

template <class T>
void print(vector<T> &vec) {
    for (auto& a : vec) {
        print(a);
    }
    cout << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
    for (auto& vec : df) {
        print(vec);
    }
}

struct star{
    ld x, y;
    ll idx;
    star(){}
};


signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    using Pld = pair<ld, ld>;
    vector<star> xy(n), xy2(n);
    rep(i,n){
        cin >> xy[i].x >> xy[i].y;
        xy[i].idx = i;
    }
    rep(i,n){
        cin >> xy2[i].x >> xy2[i].y;
        xy2[i].idx = i;
    }


    auto f = [&](vector<star> &xy){
        vector<star> temp = xy;
        long double ans = 0;
        long double x_ave = 0, y_ave = 0;
        rep(i,n)x_ave += temp[i].x, y_ave += temp[i].y;
        x_ave /= ld(n); y_ave /= ld(n);
        rep(i,n)temp[i].x -= x_ave, temp[i].y -= y_ave;
        debug(x_ave);debug(y_ave);

        sort(all(temp), [&](const auto &a, const auto &b){
            ld ath = atan2(a.y, a.x);
            ld bth = atan2(b.y, b.x);
            return ath < bth || (ath == bth && hypot(a.x, a.y) < hypot(b.x, b.y));
        });
        rep(i,n)cout << temp[i].idx << " ";print();

        temp.emplace_back(temp[0]);
        rep(i,n) ans += hypot(xy[temp[i].idx].x - xy[temp[i+1].idx].x, xy[temp[i].idx].y - xy[temp[i+1].idx].y);
        debug(ans);
        return ans;
    };

    auto g = [&](vector<star> &xy){
        vector<star> temp = xy;
        long double ans = 0;
        long double x_ave = 0, y_ave = 0;
        rep(i,n)x_ave += temp[i].x, y_ave += temp[i].y;
        x_ave /= ld(n); y_ave /= ld(n);

        rep(i,n)ans += hypot(x_ave - xy[i].x, y_ave - xy[i].y);
        return ans;
    };

    cout << fixed << setprecision(15);
    cout << g(xy2) / g(xy) << endl;
}