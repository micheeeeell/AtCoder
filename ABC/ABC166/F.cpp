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

void YES(bool ok){
    cout << (ok ? "Yes" : "No") << endl;
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    ll a,b,c; cin >> a >> b >> c;
    string ans;
    vector<ll> cnt(3), use(3);
    vector<ll> AB, BC, AC;
    vector<string> in(n);
    bool ok = true;
    rep(i,n){
        string s;cin >> s;
        in[i] = s;
        if(s == "AB"){
            cnt[0]++;
            a--;b--;
            AB.emplace_back(i);
        }
        if(s == "BC"){
            cnt[1]++;
            b--;c--;
            BC.emplace_back(i);
        }
        if(s == "AC"){
            cnt[2]++;
            a--;c--;
            AC.emplace_back(i);
        }
        if(a < 0){
            use[0]++;
            a += 2;
            ans += 'A';
        }
        if(b < 0){
            use[1]++;
            b += 2;
            ans += 'B';
        }
        if(c < 0){
            use[2]++;
            c += 2;
            ans += 'C';
        }
        ll sum = cnt[0] + cnt[1] + cnt[2];
        if(use[0] + use[1] + use[2] > sum){
            ok = false;
        }
        if(use[0] + use[1] > sum || use[1] + use[2] > sum || use[0] + use[2] > sum){
            ok = false;
        }
        if(use[0] > cnt[0] + cnt[2] || use[1] > cnt[0] + cnt[1] || use[2] > cnt[1] + cnt[2]){
            ok = false;
        }
    }

    sort(all(AB), greater<ll>());
    sort(all(BC), greater<ll>());
    sort(all(AC), greater<ll>());
    vector<string> res(n, ".");
    
    
    YES(ok);
    if(ok){
        for(auto c : ans){
            ll u = INF,v = INF;
            if(c == 'A'){
                if(!AB.empty())u = AB.back();
                if(!AC.empty())v = AC.back();
                if(u < v){
                    res[u] = "A";
                    AB.pop_back();
                }
                else{
                    res[v] = "A";
                    AC.pop_back();
                }
            }
            if(c == 'B'){
                if(!AB.empty())u = AB.back();
                if(!BC.empty())v = BC.back();
                if(u < v){
                    res[u] = "B";
                    AB.pop_back();
                }
                else{
                    res[v] = "B";
                    BC.pop_back();
                }
            }
            if(c == 'C'){
                if(!BC.empty())u = BC.back();
                if(!AC.empty())v = AC.back();
                if(u < v){
                    res[u] = "C";
                    BC.pop_back();
                }
                else{
                    res[v] = "C";
                    AC.pop_back();
                }
            }
        }

        rep(i,n)if(res[i] == "."){
            if(in[i] == "AB")res[i] = "A";
            if(in[i] == "BC")res[i] = "B";
            if(in[i] == "AC")res[i] = "C";
        }
        for(auto &str : res)cout << str << "\n";
    }
}