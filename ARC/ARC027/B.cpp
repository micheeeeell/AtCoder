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
    ll n; cin >> n;
    string s;cin >> s;
    string t;cin >> t;
    ll cnt = 0;
    bitset<26> bs(0);
    rep(i,n){
        ll temp = s[i] - '0';
        if(temp < 10 && 0 <= temp)continue;
        temp = s[i] - 'A';
        if(!bs[temp])cnt++;
        bs[temp] = 1;
    }
    rep(i,n){
        ll temp = t[i] - '0';
        ll temp_s = s[i] - 'A';
        if(temp < 10 && 0 <= temp){
            if(temp_s < 26 && 0 <= temp_s && bs[temp_s]){
                cnt--;
                bs[temp_s] = 0;
            }
        }
    }
    auto is_num = [](const char c){
        ll t = c - '0';
        return t < 10 && 0 <= t;
    };
    auto is_alp = [](const char c){
        ll t = c - 'A';
        return t < 26 && 0 <= t;
    };
    rep(i,n)rep(j,n){
        if(i <= j)continue;
        if(s[i] == s[j])continue;
        if(t[i] != t[j])continue;
        if(is_num(s[i]) && is_num(s[j]))continue;
        if(is_alp(s[i])){
            if(bs[s[i] - 'A'])cnt--, bs[s[i] - 'A'] = 0;
        }
        else{
            if(bs[s[j] - 'A'])cnt--, bs[s[j] - 'A'] = 0;
        }
    }

    ll ans = 1;
    ll temp = s[0] - 'A';
    if(temp < 26 && 0 <= temp && bs[temp])ans *= 9, cnt--;
    ans *= pow(10, cnt);

    cout << ans << endl;
}