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


template<class T, class U>
void print(const pair<T,U> &p){
    cout << p.first << " " << p.second << "\n";
}


struct nxt{
    ll u,d,r,l;
    nxt(){}
    nxt(ll u, ll d, ll r, ll l):u(u), d(d), r(r), l(l){};
    void prt(){
        cout << u << " " << d << " " << r << " " << l << "\n"; 
    }
};
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll k; cin >> k;
    string s;cin >> s;
    map<Pll, nxt> mp;
    mp[Pll(0,0)] = nxt(1, -1, 1, -1);
    auto update = [&](ll x, ll y){
        nxt t = mp[Pll(x, y)];
        if(mp.find(Pll(t.r, y)) == mp.end())mp[Pll(t.r, y)] = nxt(y+1, y-1, t.r+1, t.l);
        else mp[Pll(t.r, y)].l = t.l;

        if(mp.find(Pll(x, t.u)) == mp.end())mp[Pll(x, t.u)] = nxt(t.u+1, t.d, x+1, x-1);
        else mp[Pll(x, t.u)].d = t.d;

        if(mp.find(Pll(t.l, y)) == mp.end())mp[Pll(t.l, y)] = nxt(y+1, y-1, t.r, t.l-1);
        else mp[Pll(t.l, y)].r = t.r;

        if(mp.find(Pll(x, t.d)) == mp.end())mp[Pll(x, t.d)] = nxt(t.u, t.d-1, x+1, x-1);
        else mp[Pll(x, t.d)].u = t.u;

    };
    update(0,0);
    auto p = [&](){
        for(auto itr = mp.begin();itr != mp.end(); itr++){
            print(itr->first);
            itr->second.prt();
        }
        print();
    };
    // p();
    ll x = 0, y = 0;
    rep(i,k){
        nxt t = mp[Pll(x, y)];
        if(s[i] == 'U'){
            y = mp[Pll(x,y)].u;
            mp[Pll(x, y)].d = t.d;
        }
        if(s[i] == 'D'){
            y = mp[Pll(x,y)].d;
            mp[Pll(x, y)].u = t.u;
        }
        if(s[i] == 'R'){
            x = mp[Pll(x,y)].r;
            mp[Pll(x, y)].l = t.l;
        }
        if(s[i] == 'L'){
            x = mp[Pll(x,y)].l;
            mp[Pll(x, y)].r = t.r;
        }
        update(x,y);
        // debug(x);debug(y);
        // p();
    }
    cout << x << " " << y << "\n";
}