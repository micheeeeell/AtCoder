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

double pi = 3.14159265358979323846;
struct ensui{
    double r, h, bot, top;
    double m;
    ensui(){}
    ensui(double r_, double h_, double x_):r(r_), h(h_), bot(x_){
        m = r * r * pi * h / 3.0;
        top = x_ + h_;
    }
};

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll n,q; cin >> n >> q;
    vector<ensui> vec(n);
    rep(i,n){
        double x,r,h;cin >> x >> r >> h;
        vec[i] = ensui(r,h,x);
    }

    auto f = [&](int idx, double a, double b){
        ensui t = vec[idx];
        double rate, rate2;
        if(t.top <= a || t.bot >= b)return 0.0;
        if(t.top <= b){
            if(a <= t.bot)rate = 1.0;
            else {
                rate = (t.top - a) / t.h;
            }
            return t.m * rate * rate * rate;
        }
        else {
            if(t.bot >= a){
                rate = (t.top - b) / t.h;
                return t.m * (1.0 - rate * rate * rate);
            }
            else {
                rate = (t.top - b) / t.h;
                rate2 = (t.top - a) / t.h;
                return t.m * (rate2*rate2*rate2 - rate*rate*rate);
            }
        }
        assert(1);
        return 0.0;
    };
    rep(_, q){
        double a, b; cin >> a >> b;
        double sum = 0;
        rep(i,n)sum += f(i, a, b);
        cout << fixed << setprecision(10);
        cout << sum << "\n";
    }
    return 0;
}