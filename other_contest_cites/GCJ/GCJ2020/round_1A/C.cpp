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



void Case(int x){
    cout << "Case #" << x + 1 << ": ";
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll t; cin >> t;
    ll h,w;
    auto ave = [&](vvl &graph, bitset<n_max> bs[], int x, int y){
        if(!bs[x][y])return numeric_limits<double>::max();
        double ave = 0, cnt = 0;
        rep(i,w){
            ave += graph[x][i];
            cnt += bs[x][i];
        }
        rep(i,h){
            ave += graph[i][y];
            cnt += bs[i][y];
        }
        ave -= graph[x][y] * 2;
        cnt-= 2;
        if(cnt == 0)return numeric_limits<double>::min();
        return ave / cnt;
    };
    rep(q, t){
        cin >> h >> w;
        vector<vector<ll>> graph(h, vector<ll>(w)), next(h, vl(w)), clear(h, vl(w));
        ll sum = 0;

        rep(i,h)rep(j,w)cin >> graph[i][j];
        bitset<n_max> bs[h], bs_next[h];
        rep(i,h)rep(j,w)bs[i][j] = 1;

        // next = graph;
        while(1){
            // print(graph);
            rep(i,h)rep(j,w){
                if(ave(graph, bs, i,j) <= graph[i][j]){
                    // debug(i);debug(j);
                    // debug(ave(graph, bs, i, j));
                    next[i][j] = graph[i][j];
                    bs_next[i][j] = 1;
                }
            }

            rep(i,h)rep(j,w)sum += graph[i][j];
            // print(graph);
            if(graph == next)break;
            graph = next;
            rep(i,h)bs[i] = bs_next[i];
            next = clear;
            rep(i,h)bs_next[i] &= 0;
            
        }

        Case(q);
        cout << sum << "\n";
    }
}