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
    string s;cin >> s;
    string t;cin >> t;
    string at = "atcoder";
    auto c = [&](const char c){
        bool ok = false;
        for(auto ch : at){
            ok |= c == ch;
        }
        return ok;
    };

    bool ok = true;
    rep(i,s.size()){
        if(s[i] != '@' && t[i] != '@')ok &= s[i] == t[i];
        if(s[i] == '@'){
            if(t[i] == '@')continue;
            ok &= c(t[i]);
        }
        if(t[i] == '@'){
            if(s[i] == '@')continue;
            ok &= c(s[i]);
        }
    }

    cout << (ok ? "You can win" : "You will lose") << endl;
}