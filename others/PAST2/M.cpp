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

ll LOG = 32;
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll d,l,n; cin >> d >> l >> n;
    vector<ll> c(d);
    rep(i,d) cin >> c[i];
    vector<ll> c2 = c;
    copy(all(c), back_inserter(c2));
    // print(c2);
    vector<ll> cnt(n_max, -1);
    vector<ll> nxt(d * 2);
    rrep(i,d*2){
        if(cnt[c2[i]] != -1)nxt[i] = cnt[c2[i]];
        else nxt[i] = i + n;
        cnt[c2[i]] = i;
    }

    // print(nxt);
    vvl table(LOG, vl(d)), data(LOG, vl(d));
    rep(i,d){
        table[0][i] = nxt[i] % d;
        data[0][i] = (nxt[i] - i - 1) / l + 1;
    }
    rep(k,LOG-1){
        rep(i,d){
            table[k+1][i] = table[k][table[k][i]];
            data[k+1][i] = data[k][i] + data[k][table[k][i]];
        }
    }
    // print(data);

    vvl graph(n_max);
    rep(i,d *2){
        graph[c2[i]].emplace_back(i);
    }

    rep(_,n){
        ll k,f,t; cin >> k >> f >> t;
        f--;
        ll id;
        if(!graph[k].empty())id = *lower_bound(all(graph[k]), f);
        else id = INF;
        ll temp;
        if(id > f)temp = (id - f - 1) / l + 1;
        else temp = 0;
        if(temp >= t || id == INF){
            cout << 0 << "\n";
            continue;
        }
        id %= d;
        // debug(temp);
        t -= temp;
        ll ans = 0;
        // debug(t);
        while(t > 0){
            ll ok = 0;
            ll ng = LOG;
            while(abs(ok - ng) > 1){
                ll x = (ok + ng) / 2;
                // debug(id);debug(x);debug(data[x][id]);
                if(data[x][id] <= t)ok = x;
                else ng = x;
            }
            t -= data[ok][id];
            ans += pow(2, ok);
            id = table[ok][id];
            // debug(ok);debug(ans);debug(id);debug(t);
        }

        cout << ans << "\n";
    }
}