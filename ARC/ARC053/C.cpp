#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define rrep(i,x) for(ll i = (ll)(x)-1;0 <= i; i--)
#define reps(i,x) for(ll i = 1; i < (ll)(x)+1; i++)
#define rreps(i,x) for(ll i = (ll)(x); 1 <= i; i--)
#define debug(x) cerr << #x << ": " << (x) << "\n";
#define all(x) (x).begin(), (x).end()
// typedef long long ll;
#define ll long long
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
const ll INF = numeric_limits<ll>::max()/4;
const int n_max = 1e5+10;
#define int ll

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

struct magic{
    ll a, b, c;
    magic(){}
    magic(ll a, ll b): a(a), b(b), c(a - b){}
};
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    vector<magic> vec(n);
    ll a, b;
    rep(i,n){
        cin >> a >> b;
        vec[i] = magic(a, b);
    }
    sort(all(vec), [&](auto &A, auto &B){
        if(A.c < 0 && B.c < 0)return A.a < B.a;
        else if(A.c <= 0 || B.c <= 0)return A.c < B.c;
        else return A.b > B.b;
    });
    ll ans = 0;
    ll temp = 0;
    rep(i,n){
        chmax(ans, temp + vec[i].a);
        temp += vec[i].c;
    }

    cout << ans << endl;
}