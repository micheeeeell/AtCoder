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

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll q; cin >> q;
    using Pcl = pair<char, ll>;
    deque<Pcl> v;
    rep(i,q){
        ll t; cin >> t;
        if(t == 1){
            char c; cin >> c;
            ll x; cin >> x;
            if(!v.empty()){
                auto p = v.back();v.pop_back();
                if(p.first == c){
                    p.second += x;
                    v.emplace_back(p);
                    continue;
                }
                else {
                    v.emplace_back(p);
                    v.emplace_back(c,x);
                }
            }
            else v.emplace_back(c,x);
            
        }
        else{
            ll d; cin >> d;
            ll ans = 0;
            vector<ll> cnt(26);
            while(!v.empty() && d){
                auto p = v.front();v.pop_front();
                if(d >= p.second){
                    cnt[p.first - 'a'] += p.second;
                    d -= p.second;
                }
                else {
                    cnt[p.first - 'a'] += d;
                    p.second -= d;
                    v.emplace_front(p);
                    d = 0;
                }
            }
            rep(j,26)ans += cnt[j] * cnt[j];
            cout << ans << "\n";
        }
    }
}