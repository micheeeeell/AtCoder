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

class item{
    public:
    int w,v,c;
    item(){};
    item(int w, int v, int c):w(w), v(v), c(c){};
};

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}
int main(){
    // ll dp[105][10000][55][55];
    ll n,w,c; cin >> n >> w >> c;
    vector<item> vec(n);
    vvvl dp(w+1, vvl(c+1, vl(55,-1)));
    rep(i,n){
        ll w,v,c; cin >> w >> v >> c;
        vec[i] = item(w,v,c);
    }
    sort(all(vec), [&](const auto &a, const auto &b){
        return a.c < b.c;
    });
    // Fill(dp, -1);
    // memset(dp, -, sizeof(dp));
    debug("test");
    dp[0][0][0] = 0;
    rep(i,n){
        for(int j = w;0 <= j; j--){
            for(int k = c; 0 <= k; k--){
                rep(l,vec[i].c+1){
                    if(dp[j][k][l] != -1){
                        if(l == vec[i].c){
                            if(j + vec[i].w <= w)chmax(dp[j + vec[i].w][k][l], dp[j][k][l] + vec[i].v);
                        }
                        else{
                            if(j + vec[i].w <= w && k+1 <= c)chmax(dp[j + vec[i].w][k+1][vec[i].c], dp[j][k][l] + vec[i].v);
                        }
                    }
                }
            }
        }
    }
    ll ans = 0;
    rep(i,w+1){
        rep(j,c+1){
            rep(k, 55){
                chmax(ans, dp[i][j][k]);
            }
        }
    }
    cout << ans << endl;
}