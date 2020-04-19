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


const int N = 211111;
//const int N = 3;
vvl G(N);
vl c(N);
vl ans(N);
vl root_num(N);
vl num(N);
vl sub(N);
vl parent(N);
int n;

void pre_dfs(int now, int par) {
    sub[now] = 1;
    parent[now] = par;
    for (int ch: G[now]) {
        if (ch == par) continue;
        pre_dfs(ch, now);
        sub[now] += sub[ch];
    }
}

void dfs(int now, int par, vl& latest) {
    ll ori;
    if (now == 0) {
        rep (i, n) latest[i] = 0;
        ori = 0;
    }
    else {
        ori = latest[c[par]];
        latest[c[par]] = now;
    }
    int last_same = latest[c[now]];
    if (last_same != 0) {
        num[last_same] -= sub[now];
    }
    else {
        root_num[c[now]] -= sub[now];
    }

    for (int ch: G[now]) {
        if (ch == par) continue;
        dfs(ch, now, latest);
    }
    
    if (now == 0) {
    }
    else {
        latest[c[par]] = ori;
    }
}

signed main() {
    // fio();
    // ifstream in("input.in");
    // cin.rdbuf(in.rdbuf());
    // ofstream ofstr("out.txt");
    // streambuf* strbuf;
    // strbuf = std::cout.rdbuf( ofstr.rdbuf() );
    cin >> n;
    rep (i, n) {
        cin >> c[i];
        c[i]--;
    }
    rep (i, n - 1) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    pre_dfs(0, -1);
    // return 0;
    rep (i, n) {
        num[i] = sub[i];
    }
    rep (i, n) {
        root_num[i] = num[0];
    }

    vl latest(n);
    dfs(0, -1, latest);
    // DEBUG_VEC(num);
    // DEBUG_VEC(root_num);

    debug("test");

    vl ans(n);
    rep (i, n) {
        ans[i] = n * (n - 1) / 2 + n;
    }
    for (int i = 1; i < n; i++) {
        int pc = c[parent[i]];
        ans[pc] -= num[i] * (num[i] - 1) / 2 + num[i];
    }
    rep (i, n) {
        ans[i] -= root_num[i] * (root_num[i] - 1) / 2 + root_num[i];
    }

    rep (i, n) {
        cout << ans[i] << endl;
    }
}
