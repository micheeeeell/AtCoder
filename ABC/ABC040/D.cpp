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

struct UnionFind{
private:
    vector<int> par;
    vector<int> rank;
    vector<int> sz;

public:
    //n要素で親を初期化、par[x]はxの親を表す
    UnionFind(int n){
        par.resize(n,0);
        rank.resize(n,0);
        sz.resize(n,1);
        rep(i,n){
            par[i] = i;
        }
    }

    //木の根を求める
    int root(int x){
        if(par[x] == x) return x;
        else return par[x] = root(par[x]);
    }

    //xとyの属する集合を併合
    void unite(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y) return;
        else{
            par[y] = x;
            sz[x] += sz[y];
            if(rank[x] == rank[y]) rank[x]++;
        }
    }

    //xとyが同じ集合に属するか否か
    bool same(int x, int y){
        return root(x) == root(y);
    }

    //xが属する集合のサイズを返す
    int size(int x){
        return sz[root(x)];
    }
};

class bridge{
    public:
    bridge(){};
    bridge(ll a, ll b, ll y): a(a), b(b), y(y)
    {};
    ll a,b,y;
};

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


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll n,m; cin >> n >> m;
    vector<bridge> bri(m);
    rep(i,m){
        ll a,b,y; cin >> a >> b >> y;
        a--;b--;
        bri[i] = bridge(a,b,y);
    }
    ll q; cin >> q;
    // vector<Pll> query(q);
    using Plll = pair<ll,Pll>;
    priority_queue<Plll> pq;
    rep(i,q){
        ll v,w; cin >> v >> w;
        v--;
        // query[i] = Pll(v,w);
        pq.push(Plll(w,Pll(v,i)));
    }
    sort(all(bri),
    [&](const auto &a, const auto &b){
        return a.y > b.y;
    });
    UnionFind uf(n);
    vector<ll> ret(q,0);
    ll cnt = 0;
    ll year = 2*1e5+10;
    while(0 < year && pq.size()){
        while(bri[cnt].y == year && cnt < m){
            uf.unite(bri[cnt].a, bri[cnt].b);
            cnt++;
        }
        // print(year, cnt);
        Plll t;
        if(pq.size())t = pq.top();
        while(pq.size() && t.first == year-1 ){
            pq.pop();
            ret[t.second.second] = uf.size(t.second.first);
            t = pq.top();
        }
        // if(year > 1994 && year < 2005)print(year,pq.size(), t.first);
        // year = bri[cnt].y;
        year--;
    }

    rep(i,q){
        cout << ret[i] << "\n";
    }
}