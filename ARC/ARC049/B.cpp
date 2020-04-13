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

struct norumu {
    double x, y, c;
    norumu(){};
};

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    double x_sum = 0, y_sum = 0;
    double csum = 0;
    vector<norumu> vec(n);
    rep(i,n){
        cin >> vec[i].x >> vec[i].y >> vec[i].c;
        x_sum += vec[i].x * vec[i].c;
        y_sum += vec[i].y * vec[i].c;
        csum += vec[i].c;
    }
    auto check = [&](double cost){
        double x_min = -1e5, x_max = 1e5, y_min = -1e5, y_max = 1e5;
        rep(i,n){
            chmax(x_min, vec[i].x - (cost / vec[i].c));
            chmin(x_max, vec[i].x + (cost / vec[i].c));
            chmax(y_min, vec[i].y - (cost / vec[i].c));
            chmin(y_max, vec[i].y + (cost / vec[i].c));
            if(x_min > x_max || y_min > y_max)return false;
        }
        return true;
    };
    double ok = 1e8;
    double ng = 0.0;
    rep(i,100){
        double cost = (ok + ng) / 2.0;
        if(check(cost))ok = cost;
        else ng = cost;
    }

    cout << fixed << setprecision(15);
    cout << ok << endl;
}