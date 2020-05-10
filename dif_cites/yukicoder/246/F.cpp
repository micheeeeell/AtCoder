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

void print() {
    cout << endl;
}

// template <class Head, class... Tail>
// void print(Head&& head, Tail&&... tail) {
//     cout << head;
//     if (sizeof...(tail) != 0) cout << " ";
//     print(forward<Tail>(tail)...);
// }

template <class T>
void print(vector<T> &vec) {
    for (auto& a : vec) {
        cout << a;
        if (&a != &vec.back()) cout << " ";
    }
    cout << endl;
}

template <class T>
void print(vector<T> &vec, ll k){
   ll n = vec.size();
   k = min(k, n);
   rep(i,k-1)cout << vec[i] << " ";
   cout << vec[k-1] << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
    for (auto& vec : df) {
        print(vec);
    }
}

template<class T, class U>
void print(pair<T,U> &p){
    cout << p.first << " " << p.second << "\n";
}


template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

struct state{
    ll x,y,z;
    state(){}
};

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<state> v(n);
    rep(i,n)cin >> v[i].x >> v[i].y >> v[i].z;

    auto c = [&](ll j, ll k, ll l, ll m){
        ll one[2], two[2];
        if(k == 0){
            one[0] = v[j].x, one[1] = v[j].y;
        }
        if(k == 1){
            one[0] = v[j].z, one[1] = v[j].y;
        }
        if(k == 2){
            one[0] = v[j].x, one[1] = v[j].z;
        }
        if(m == 0){
            two[0] = v[l].x, two[1] = v[l].y;
        }
        if(m == 1){
            two[0] = v[l].z, two[1] = v[l].y;
        }
        if(m == 2){
            two[0] = v[l].x, two[1] = v[l].z;
        }
        if(one[0] >= two[0] && one[1] >= two[1])return true;
        if(one[0] >= two[1] && one[1] >= two[0])return true;
        return false;
    };
    auto f = [&](ll l, ll m){
        if(m == 0)return v[l].z;
        if(m == 1)return v[l].x;
        if(m == 2)return v[l].y;
    };
    vvvl dp(1 << n, vvl(n, vl(3)));
    rep(i,n){
        rep(j, 3)dp[1LL << i][i][j] = f(i, j);
    }
    rep(i, 1LL << n){
        rep(j,n){
            if((i >> j) & 1){

                rep(k, 3){
                    rep(l,n){
                        if((i >> l) & 1)continue;
                        rep(m,3){
                            if(c(j,k,l,m)){
                                chmax(dp[i | (1LL << l)][l][m], dp[i][j][k] + f(l,m));
                            }
                        }
                    }
                }
            }
        }
        // print(dp[i]);print();
    }

    ll ans = 0;
    rep(i, 1LL << n){
        rep(j,n)rep(k,3)chmax(ans, dp[i][j][k]);
    }

    cout << ans << endl;
}