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
string s;
ll n;
pair<string, ll> dfs(int pos){
    string ans, ret;
    while(pos < n && s[pos] != ')'){
        if(s[pos] != '(')ans += s[pos++];
        else{
            auto p = dfs(pos+1);
            ans += p.first;
            pos = p.second;
        }
    }
    if(pos == n){
        return {ans, pos};
    }
    if(s[pos] == ')'){
        ret = ans;
        reverse(all(ans));
        ret += ans;
        return {ret, pos+1};
    }

}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> s;
    n = s.size();
    string ans;
    ll pos = 0;
    while(pos < n){
        auto p = dfs(pos);
        ans += p.first;
        pos = p.second;
    }

    cout << ans << endl;
}