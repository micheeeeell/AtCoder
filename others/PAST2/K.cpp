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
const int n_max = 3030;
#define int ll


template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

vector<ll> c(n_max);
vector<ll> d(n_max);
string s;
vvl memo(n_max, vl(n_max));
vvl flag(n_max, vl(n_max));

ll dfs(ll left, ll right){
    if(left == right)return 0;
    if(flag[left][right])return memo[left][right];
    if(right == left + 1){
        flag[left][right] = 1;
        return memo[left][right] = d[left];
    }

    ll ans = INF;
    if(left + 1 <= right - 1){
        ll temp = 0;
        if(s[left] != '(')temp += c[left];
        if(s[right-1] != ')')temp += c[right-1];
        chmin(ans, temp + dfs(left+1, right-1));
    }

    for(ll r = left + 1; r < right; r++){
        chmin(ans, dfs(left, r) + dfs(r, right));
    }

    // debug(left);debug(right);debug(ans);
    flag[left][right] = 1;
    return memo[left][right] = ans;
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ifstream in("input.in");
    cin.rdbuf(in.rdbuf());
    ofstream ofstr("out.txt");
    streambuf* strbuf;
    strbuf = std::cout.rdbuf( ofstr.rdbuf() );
    
    ll n; cin >> n;
    cin >> s;
    rep(i,n) cin >> c[i];
    rep(i,n) cin >> d[i];

    cout << dfs(0, n) << endl;
}