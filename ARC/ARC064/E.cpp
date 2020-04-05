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

class node{
    public:
    double x, y, r;
    node(){};
    node(double x, double y, double r):x(x), y(y), r(r){};
};

int main(){
    double xs,ys; cin >> xs >> ys;
    double xt,yt; cin >> xt >> yt;
    ll n; cin >> n;

    vector<node> vec(n+2);
    vec[0] = node(xs, ys, 0);
    vec[n+1] = node(xt, yt, 0);
    reps(i,n){
        double x,y; cin >> x >> y;
        double r; cin >> r;
        vec[i] = node(x, y, r);
    } 
    vector<vector<double>> graph(n+2, vector<double>(n+2, 0));
    auto dist = [&](int i, int j){
        double x1 = vec[i].x, y1 = vec[i].y, x2 = vec[j].x, y2 = vec[j].y;
        return sqrt((x1-x2) * (x1-x2) + (y1-y2) * (y1-y2));
    };
    rep(i,n+2)rep(j,n+2){
        if(i <= j)continue;
        graph[i][j] = graph[j][i] = max(dist(i, j) - vec[i].r - vec[j].r, 0.0);
    }

    auto dijkstra = [&](int x){
        using state = pair<double, int>;
        priority_queue<state, vector<state>, greater<state>> pq;
        pq.emplace(double(0), x);
        vector<double> data(n+2, numeric_limits<double>::max());
        data[x] = (double)0;

        while(!pq.empty()) {
            state cur = pq.top();pq.pop();
            double c = cur.first; int pos = cur.second;
            if(data[pos] < c)continue;
            rep(i,n+2){
                if(i == pos)continue;
                if(c + graph[pos][i] < data[i]){
                    data[i] = c + graph[pos][i];
                    pq.emplace(data[i], i);
                }
            }
        }
        return data;
    };

    auto ans = dijkstra(0);
    cout << fixed << setprecision(10);
    cout << ans[n+1] << endl;
}