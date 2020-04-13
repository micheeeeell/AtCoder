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

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll n,m; cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    string s;cin >> s;
    deque<ll> deq;
    rep(i,n)deq.emplace_back(a[i]);
    rep(i,m){
        if(s[i] == 'L'){
            ll t1 = deq.front();deq.pop_front();
            ll t2 = deq.front();deq.pop_front();
            deq.emplace_front(t1 + t2);
            deq.emplace_back(0);
        }
        else{
            ll t1 = deq.back();deq.pop_back();
            ll t2 = deq.back();deq.pop_back();
            deq.emplace_back(t1 + t2);
            deq.emplace_front(0);
        }
    }

    for(auto &i : deq)cout << i << " ";
    cout << endl;
}