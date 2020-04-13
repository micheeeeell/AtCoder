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

    // ifstream in("out.txt");
    // cin.rdbuf(in.rdbuf());
    // ofstream ofstr("out.txt");
    // streambuf* strbuf;
    // strbuf = std::cout.rdbuf( ofstr.rdbuf() );
    
    ll n,x; cin >> n >> x;
    vector<Pll> vec(n);
    rep(i,n)cin >> vec[i].first;
    rep(i,n)cin >> vec[i].second;
    sort(all(vec), greater<Pll>());
    auto check = [&](int time){
        ll idx = 0;
        priority_queue<ll> pq;
        // while(idx < n && vec[idx].first > time){
        //     pq.emplace(vec[idx++].second);
        // }

        ll sum = 0;
        while(time > 0) {
            while(idx < n && vec[idx].first >= time) {
                pq.emplace(vec[idx].second);
                idx++;
                // if(idx % 1000 == 0)debug(idx);
            }
            if(!pq.empty()){
                ll p = pq.top();pq.pop();
                sum += p;
            }
            // debug(time);
            time--;
        }
        return sum >= x;
    };

    ll ok = n_max;
    ll ng = 0;
    while(abs(ok - ng) > 1){
        ll time = (ok + ng) / 2;
        // debug(time);
        if(check(time))ok = time;
        else ng = time;
    }

    cout << (check(ok) ? ok : -1) << endl;
}