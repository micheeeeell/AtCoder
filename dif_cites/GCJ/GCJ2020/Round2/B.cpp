#define LOCAL
#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include<bits/stdc++.h>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define rrep(i,x) for(ll i = (ll)(x)-1;0 <= i; i--)
#define reps(i,x) for(ll i = 1; i < (ll)(x)+1; i++)
#define rreps(i,x) for(ll i = (ll)(x); 1 <= i; i--)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> Pll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
constexpr ll INF = numeric_limits<ll>::max()/4;
constexpr ll n_max = 1e2+10;
#define int ll

template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string &s) {return '"' + s + '"';}
string to_string(const char c) {return to_string((string) &c);}
string to_string(bool b) {return (b ? "true" : "false");}
template <size_t N>
string to_string(bitset<N> v){
    string res = "";
    for(size_t i = 0; i < N; i++) res += static_cast<char>('0' + v[i]);
    return res;
}
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for(const auto &x : v) {
        if(!first) res += ", ";
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p){return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}

void debug_out() {cerr << endl;}
template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

void print() {
    cout << endl;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
    cout << head;
    if (sizeof...(tail) != 0) cout << " ";
    print(forward<Tail>(tail)...);
}

template <class T>
void print(vector<T> &vec) {
    for (auto& a : vec) {
        cout << a;
        if (&a != &vec.back()) cout << " ";
    }
    cout << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
    for (auto& vec : df) {
        print(vec);
    }
}


void Case(int x){
    cout << "Case #" << x + 1 << ": ";
}
vector<ll> path, c_path;
vector<ll> used(n_max), t_used(n_max), clear(n_max);

bool dfs(vvl &graph, ll pos, ll e){
    t_used[pos] = 1;
    if(e == pos){
        path.emplace_back(pos);
        return true;
    }
    for(auto &to : graph[pos]){
        if(t_used[to])continue;
        if(to != e && used[to] == 0)continue;
        if(dfs(graph, to, e)){
            path.emplace_back(pos);
            return true;
        }
    }
    return false;
}

vector<ll> bfs(vvl &grpah, ll root, ll e){
    t_used[root] = 1;
    vector<ll> ret;
    queue<ll> que;
    ret.emplace_back(root);
    while(!que.empty()){

    }
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll t; cin >> t;
    rep(q,t){
        ll n,m; cin >> n >> m;
        vector<Pll> num, que;
        used = clear;
        reps(i,n-1){
            ll t; cin >> t;
            if(t >= 0){
                num.emplace_back(t,i);
            }
            else{
                que.emplace_back(-t, i);
            }
        }
        sort(all(que), greater<>());
        sort(all(num), greater<>());

        vector<vector<ll>> graph(n);
        map<Pll, ll> mp;
        rep(i,m) {
            ll a,b;cin >> a >> b;
            a--;b--;
            graph[a].emplace_back(b);
            graph[b].emplace_back(a);
            mp[Pll(a,b)] = i;
            mp[Pll(b,a)] = i;
        }
        vector<Pll> temp;
        ll id = 1;
        ll last = 0;
        vector<ll> ans(m);
        while(!que.empty() || !num.empty()){
            temp.clear();
            bool is_que = false;
            while(!que.empty() && que.back().first <= id){
                temp.emplace_back(que.back());
                que.pop_back();
                is_que = true;
            }
            if(temp.empty()){
                temp.emplace_back(num.back());
                num.pop_back();
                ll t = temp[0].first;
                while(!num.empty() && num.back().first <= t){
                    temp.emplace_back(num.back());
                    num.pop_back();
                }
            }
            debug(temp);
            id += temp.size();
            ll time;
            if(is_que){
                time = last + 1;
                last++;
            }
            else{
                time = temp[0].first;
                last = time;
            }
            debug(time);
            for(auto &p : temp){
                path = c_path;
                t_used = clear;
                dfs(graph, 0, p.second);
                ll t = 0;
                for(int i = path.size()-1; 1 < i; i--){
                    t += ans[mp[Pll(path[i], path[i-1])]];
                }
                debug(path);
                ans[mp[Pll(path[1], path[0])]] = time - t;
                
            }
            for(auto &p : temp){
                used[p.second] = 1;
            }

        }

        for(auto &t : ans){
            if(t == 0)t = 1e6;
            assert(t > 0);
        }

        Case(q);
        print(ans);
    }
}