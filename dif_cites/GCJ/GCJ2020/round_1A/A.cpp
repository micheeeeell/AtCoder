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

void Case(int x){
    cout << "Case #" << x + 1 << ": ";
}

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
    cout << p.first << " " << p.second << endl;
}


signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll t; cin >> t;
    auto pre_up = [&](string pre, string temp_pre) -> pair<bool, string>{
        string ans;
        bool ok = true;
        rep(i, min(pre.size(), temp_pre.size())){
            ok &= pre[i] == temp_pre[i];
            ans += pre[i];
        }
        // debug(ans);
        if(ans.size() < pre.size()){
            ans += pre.substr(ans.size());
        }
        // debug(ans);
        if(ans.size() < temp_pre.size()){
            ans += temp_pre.substr(ans.size());
        }
        // debug(ans);
        return {ok, ans};
    };
    auto suf_up = [&](string suf, string temp_suf) -> pair<bool, string>{
        reverse(all(suf));
        reverse(all(temp_suf));
        string ans;
        // debug(suf);debug(temp_suf);
        bool ok = true;
        rep(i, min(suf.size(), temp_suf.size())){
            ok &= suf[i] == temp_suf[i];
            ans += suf[i];
        }
        // debug(ans);
        if(ans.size() < suf.size()){
            ans += suf.substr(ans.size());
        }
        // debug(ans);
        if(ans.size() < temp_suf.size()){
            ans += temp_suf.substr(ans.size());
        }
        // debug(ans);
        reverse(all(ans));
        return {ok, ans};
    };
    // debug(pre_up("HELLo", "HEL").first);
    // debug(pre_up("HELLo", "HEL").second);
    // debug(pre_up("HE", "EH").first);
    // debug(pre_up("HE", "EH").second);
    // debug(suf_up("CONUTS", "COCONUTS").second);
    rep(q, t){
        ll n; cin >> n;
        string pref, suff, middle;
        string temp_pre, temp_suf, temp_middle;
        bool ok = true;
        rep(i,n){
            string s;cin >> s;
            ll sz = s.size();
            int pre_id = 0;
            while(pre_id < sz && s[pre_id] != '*')temp_pre += s[pre_id++];
            
            int suf_id = sz-1;
            while(suf_id >= 0 && s[suf_id] != '*')temp_suf += s[suf_id--];
            reverse(all(temp_suf));
            auto p = pre_up(pref, temp_pre);
            ok &= p.first;
            pref = p.second;
            p = suf_up(suff, temp_suf);
            ok &= p.first; suff = p.second;
            // if(!ok)break;
            for(int j = pre_id; j <= suf_id; j++){
                temp_middle += s[j];
            }
            middle += temp_middle;
            // debug(temp_pre);debug(temp_suf);
            // debug(pref);debug(suff);debug(middle);debug(ok);
            temp_suf = "";temp_pre = "";temp_middle = "";
        }
        rep(i,middle.size()){
            if(middle[i] == '*')middle[i] = 'A';
        }
        Case(q);
        cout << (ok ? pref + middle + suff : "*") << "\n";
    }
    return 0;
}