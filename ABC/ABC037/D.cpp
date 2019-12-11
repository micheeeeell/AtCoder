#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define debug(x) cerr << #x << ": " << (x) << "\n";
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
const ll INF = LLONG_MAX/4;
const ll MOD = 1e9+7;
const int n_max = 1e5+10;

void print() {
    cout << endl;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
    cout << head;
    if (sizeof...(tail) != 0) cout << ' ';
    print(forward<Tail>(tail)...);
}

template <class T>
void print(vector<T> &vec) {
    for (auto& a : vec) {
        cout << a;
        if (&a != &vec.back()) cout << ' ';
    }
    cout << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
    for (auto& vec : df) {
        print(vec);
    }
}

template<typename T>
void print(T &arr){
    ll sz = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0;i < sz-1;i++){cout << arr[i] << ' ';}
    cout << arr[sz-1] << endl;
}

ll h,w;
ll h_max = 1010, w_max = 1010;
vector<vector<ll>> a(h_max,vector<ll>(w_max,0));
vector<vector<ll>> memo(h_max,vector<ll>(w_max,0));
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool is_max(ll x, ll y){
    bool ret = true;
    rep(i,4){
        ll nx = x + dx[i];
        ll ny = y + dy[i];
        if(nx < 0 || ny < 0 || h <= nx || w <= ny)continue;
        ret &= (a[nx][ny] <= a[x][y]);
    }
    return ret;
}

ll dfs(ll x, ll y){
    if(is_max(x,y))return 0;
    if(memo[x][y])return memo[x][y];
    ll ret = 0;
    rep(i,4){
        ll nx = x + dx[i];
        ll ny = y + dy[i];
        if(nx < 0 || ny < 0 || h <= nx || w <= ny)continue;
        if(a[x][y] < a[nx][ny])ret = (ret + dfs(nx,ny) + 1) % MOD;
    }
    memo[x][y] = ret;
    return ret;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> h >> w;
    rep(i,h)rep(j,w){
        cin >> a[i][j];
    }
    auto check = [&](ll x, ll y){
        bool ret = true;
        rep(i,4){
            ll nx = x + dx[i];
            ll ny = y + dy[i];
            if(nx < 0 || ny < 0 || h <= nx || w <= ny)continue;
            ret &= (a[nx][ny] <= a[x][y]);
        }
        return ret;
    };
    vector<vector<ll>> dp(h,vector<ll>(w));
    rep(i,h)rep(j,w)dp[i][j] = dfs(i,j);
    // print(dp);
    ll ret = 0;
    
    rep(i,h)rep(j,w)ret = (ret + dp[i][j] + 1) % MOD;

    cout << ret << endl; 
}