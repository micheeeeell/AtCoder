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

void YES(bool ok){
    cout << (ok ? "YES" : "NO") << endl;
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    string a;cin >> a;
    string b;cin >> b;
    ll n = a.size();
    vector<ll> cnt_a(26), cnt_b(26);
    bool ok = true;
    rep(i,n)cnt_a[a[i] - 'a']++;
    rep(i,n)cnt_b[b[i] - 'a']++;
    vector<ll> dif;
    rep(i,n){
        if(a[i] != b[i])dif.emplace_back(i);
    }
    rep(i,26)ok &= cnt_a[i] == cnt_b[i];
    bool doub = false;
    rep(i,26)doub |= cnt_a[i] > 1;
    ll k = dif.size();
    ll pr = 0;
    for(auto &i : dif)for(auto &j : dif){
        if(i <= j)continue;
        if(a[i] == b[j] && a[j] == b[i])pr++;
    }
    if(k == 1 || k > 6)ok = false;
    if(k == 2)ok &= true;
    if(k == 3){
        ok &= doub;
    }
    if(k == 4){
        // debug(pr);
        if(pr == 2)ok &= doub;
    }
    if(k == 5){
        ok &= (pr == 1);
    }
    if(k == 6){
        ok &= (pr == 3);
    }
    if(k == 0){
        ok &= doub;
    }
    YES(ok);
}