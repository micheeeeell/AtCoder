// #define _GLIBCXX_DEBUG
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
const int n_max = 2e5+10;
#define int ll
template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

vector<ll> par(n_max), cnt(n_max);
// bitset<n_max> used(0);
// vector<ll> used(n_max);
// vector<vector<ll>> color(n_max);
vector<ll> latest(n_max, -1);
vector<ll> same_par(n_max, -1);
vector<ll> c(n_max);
vector<ll> depth(n_max);
vvl graph(n_max);

void dfs(ll pos, ll parent){

    cnt[pos] = 1;
    for(auto to : graph[pos]){
        if(to == parent)continue;
        par[to] = pos;
        dfs(to, pos);
        cnt[pos] += cnt[to];
    }

}

void dfs2(ll pos, ll parent){
    ll pre = latest[c[pos]];
    if(latest[c[pos]] != -1)same_par[pos] = latest[c[pos]];
    latest[c[pos]]= pos;

    for(auto to : graph[pos]){
        if(to == parent)continue;
        // par[to] = pos;
        dfs2(to, pos);
        // cnt[pos] += cnt[to];
    }

    latest[c[pos]] = pre;
}

void depth_dfs(ll pos, ll parent, ll d){
    depth[pos] = d;
    for(auto to : graph[pos]){
        if(to == parent)continue;
        depth_dfs(to, pos, d+1);
    }
}

template<class T>
void print(vector<T> &vec, ll k){
    chmin(k, (ll)vec.size());
    // debug("print");
    rep(i,k)cout << vec[i] << " ";
    cout << endl;
}

vector<ll> tree_topo(vvl &graph, ll root){
    const ll n_max = 2e5+10;
    bitset<n_max> bs(0);
    vector<ll> ans;
    queue<ll> que;
    que.emplace(root);
    bs[root] = 1;
    while(!que.empty()) {
        auto f = que.front();que.pop();
        ans.emplace_back(f);
        for(auto &to : graph[f]){
            if(bs[to])continue;
            bs[to] = 1;
            que.emplace(to);
        }
    }
    return ans;
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // ifstream in("input.in");
    // cin.rdbuf(in.rdbuf());
    // ofstream ofstr("out.txt");
    // streambuf* strbuf;
    // strbuf = std::cout.rdbuf( ofstr.rdbuf() );
    ll n; cin >> n;

    rep(i,n) {
        cin >> c[i];
        c[i]--;
    }
    // vector<vector<ll>> graph(n);
    rep(i,n-1) {
        ll a,b;cin >> a >> b;
        a--;b--;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    vector<ll> ans(n);
    par[0] = -1;
    // print(c, 10);
    dfs(0, -1);
    depth_dfs(0,-1,0);
    dfs2(0,-1);
    // print(same_par, 10);
    // return 0;

    vector<ll> cnt2(n);
    vector<ll> topo = tree_topo(graph, 0);
    // return 0;
    rep(j,n){
        ll i = topo[j];
        ll temp = 0;
        ll sum = 0, jijou = 0;
        for(auto &to : graph[i]){
            if(to != par[i]){
                sum += cnt[to];
                jijou += (cnt[to]) * (cnt[to]);
            }
        }
        ll num;
        if(par[i] != -1){
            if(same_par[i] != -1)num = depth[i] - depth[same_par[i]] - 1;
            else num = n - cnt[i];
            temp = cnt[i] + num;
            sum += num;
            jijou += num * num;
        }
        else{
            temp = n;
        }
        ans[c[i]] += (sum * sum - jijou) / 2 + temp;
        // ans[c[i]] -= cnt2[c[i]];
        // cnt2[c[i]]++;
        // debug(num);debug(sum);debug(jijou);
    }

    print(ans, n);
}