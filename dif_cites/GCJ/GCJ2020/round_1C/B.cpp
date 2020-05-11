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

// xの桁数を返す関数
int digit_max(ll x){
    int dig = 0;
    while(x > 0){
        dig++;
        x /= 10;
    }
    return dig;
}
int digit_num(ll x, int digit){
    assert(digit_max(x) >= digit);
    rep(i,digit-1)x /= 10;
    return x % 10;
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ifstream in("input.in");
    cin.rdbuf(in.rdbuf());
    ofstream ofstr("out.txt");
    streambuf* strbuf;
    strbuf = std::cout.rdbuf( ofstr.rdbuf() );
    
    ll t; cin >> t;
    rep(q,t){
        vector<ll> m(1e4);
        vector<string> r(1e4);
        ll k; cin >> k;
        rep(i,1e4)cin >> m[i] >> r[i];
        map<char, ll> is_zero;
        map<char, ll> upper, use, cnt;
        set<char> st;
        rep(i,1e4){
            ll dig = digit_max(m[i]);
            for(auto c : r[i]){
                st.insert(c);
                cnt[c]++;
            }
            if(dig > 1)is_zero[r[i][0]] = false;
            if(dig == r[i].size()){
                // debug(r[i][0]);
                if(upper.find(r[i][0]) == upper.end())upper[r[i][0]] = digit_num(m[i], dig);
                else upper[r[i][0]] = min(upper[r[i][0]], digit_num(m[i], dig));
            }
        }
        vector<char> ans(10);
        for(auto itr = upper.begin(); itr != upper.end(); itr++){
            // debug(itr->first);debug(itr->second);
            if(itr->second < 10){
                ans[itr->second] = itr->first;
                use[itr->first] = 1;
            }
        }
        for(auto c : st){
            if(use[c] == 0)ans[0] = c;
        }

        Case(q);
        for(auto i : ans)cout << i;
        cout << endl;
    }
}