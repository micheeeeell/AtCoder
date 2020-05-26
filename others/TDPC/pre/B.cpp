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

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

ll A_max = 1100,B_max = 1100;
vector< vector <ll> > memo(A_max, vector<ll>(B_max,INF));
vector<ll> a(A_max);
vector<ll> b(B_max);
ll A,B;

ll solve(int l, int r, int turn = 0){
    if(l == A && r == B)return memo[l][r] = 0;
    if(memo[l][r] != INF)return memo[l][r];
    ll res = (turn ? INF : -INF);
    if(l < A){
        if(turn == 0)res = solve(l+1, r, turn^1) + a[l];
        else res = solve(l+1, r, turn^1) - a[l];
    }
    if(r < B){
        if(turn == 0)chmax(res, solve(l,r+1, turn^1) + b[r]);
        else chmin(res, solve(l, r+1, turn^1) - b[r]);
    }

    return memo[l][r] = res;
};

int main(){
    cin >> A >> B;
    rep(i,A) cin >> a[i];
    rep(i,B) cin >> b[i];
    ll sum = 0;
    rep(i,A)sum += a[i];
    rep(i,B)sum += b[i];
    ll ans = solve(0,0);
    ans += (sum-ans)/2;
    cout << ans << endl;
}