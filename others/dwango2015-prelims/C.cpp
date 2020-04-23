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

const int MAX = 102;
vector<vector<ld>> com(MAX+1,vector<ld>(MAX+1,0));
void COMinit(){
    com[0][0] = 1;
    rep(i,MAX){
        rep(j,MAX){
            if(i == 0 || j == 0)com[i][j] = 1;
            else com[i][j] = com[i][j-1] + com[i-1][j];
        }
    }
}
ll COM(ll n, ll k){
    return com[n-k][k];
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    auto f = [&](ll r, ll s, ll p){
        ll min_ = min({r, s, p});
        vector<ll> v(3);
        v[0] = r;v[1] = s;v[2] = p;
        ll cnt = 0;
        rep(i,3)if(v[i] == min_)cnt++;
        sort(all(v));
        if(cnt == 3)return r + s + p;
        if(cnt == 2){
            return (v[0] == 0 ? v[2] : v[0]);
        }
        if(cnt == 1){
            return (v[0] == 0 ? v[1] : v[0]);
        }
        assert(false);
        return 0LL;
    };
    COMinit();
    auto P = [&](ll n, ll r, ll s, ll p){
        ld ans = 0;
        ans = (COM(n, r) / pow(3, n)) * COM(n-r, s);
        return ans;
    };
    vector<ld> e(n+1);
    ll p;
    for(int i = 2; i <= n; i++){
        ld rev = 0;
        ld temp = 0;
        rep(r, i+1)rep(s, i+1){
            if(r + s > i)continue;
            p = i - r - s;
            if(f(r,s,p) == i){
                rev += P(i,r,s,p);
                temp += P(i,r,s,p);
                continue;
            }
            temp += P(i,r,s,p) * (1.0 + e[f(r,s,p)]);
        }
        e[i] = temp / (1.0 - rev);
    }

    cout << fixed << setprecision(15) << e[n] << endl;
}