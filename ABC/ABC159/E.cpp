#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
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

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

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

template<class T, class U>
void print(pair<T,U> &p){
    print(p.first, p.second);
}


int main(){
    ll h,w,k; cin >> h >> w >> k;
    string s[h];
    rep(i,h)cin >> s[i];
    vector<vector<ll>> sum(h+1, vector<ll>(w+1));
    rep(i,h)rep(j,w){
        sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j] + (s[i][j] - '0');
    }
    auto f = [&](int sx, int sy, int gx, int gy){
        return sum[gx][gy] - sum[gx][sy] - sum[sx][gy] + sum[sx][sy];
    };

    // print(sum);

    ll ans = INF;
    rep(i,(1LL << (h-1))){
        ll sy = 0;
        ll sx = 0, gx = 1;
        ll temp = 0;
        bool ok = true;
        reps(gy, w){
            rep(j,h-1){
                if((i >> j) & 1){
                    gx = j+1;
                    if(f(sx,sy,gx,gy) > k){
                        if(sy == gy-1)ok = false;
                        temp++;
                        sy = gy-1;
                        // debug(i);debug(gy);
                    }
                    sx = gx;
                }
            }
            if(f(sx,sy,h,gy) > k){
                if(sy == gy-1)ok = false;
                sy = gy-1;
                temp++;
                // debug(i);debug(gy);
            }
            sx = 0;
        }
        
        if(ok){
            // debug(i);debug(temp);
            chmin(ans, __builtin_popcountll(i) + temp);
        }
    }

    cout << ans << endl;
}