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
    ll n,k; cin >> n >> k;
    string s;cin >> s;
    if(n / 2 < k){
        YES(false);
        return 0;
    }

    vector<ll> cnt(26);
    vector<vector<ll>> table(n-k+1);

    rep(right,n){
        ll t = s[right] - 'a';
        cnt[t]++;
        if(right - k + 1 >= 0){
            table[right-k+1] = cnt;
            cnt[s[right-k+1] - 'a']--;
        }
    }
    map<vector<ll>, ll> mp;
    bool ok = false;
    for(int i = k; i < n - k + 1; i++)mp[table[i]]++;
    rep(i,n-k+1){
        if(mp[table[i]] > 0)ok = true;
        if(i + k <= n - k)mp[table[i + k]]--;
        if(i - k > 0){
            mp[table[i - k]]++;
        }
    }

    YES(ok);
}