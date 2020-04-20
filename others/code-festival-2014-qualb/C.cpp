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

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}
void YES(bool ok){
    cout << (ok ? "YES" : "NO") << endl;
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    string s[3];
    rep(i,3)cin >> s[i];
    ll n = s[0].size();
    vector<vector<ll>> cnt(3, vector<ll>(26));
    rep(i,3){
        for(auto c : s[i]){
            cnt[i][c - 'A']++;
        }
    }

    ll min_1 = 0, min_2 = 0;
    bool ok = true;
    rep(i,26){
        ll num = cnt[0][i] + cnt[1][i] - cnt[2][i];
        min_1 += cnt[0][i] - min(cnt[0][i], num);
        min_2 += cnt[1][i] - min(cnt[1][i], num);
        chmin(cnt[0][i], num);
        chmin(cnt[1][i], num);
        ok &= num >= 0;
        cnt[2][i] = min(cnt[0][i], cnt[1][i]);
    }

    YES(min_1 <= (n / 2) && min_2 <= (n / 2) && ok);
}