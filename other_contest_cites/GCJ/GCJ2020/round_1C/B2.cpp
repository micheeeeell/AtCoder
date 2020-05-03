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

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    // ifstream in("input.in");
    // cin.rdbuf(in.rdbuf());
    // ofstream ofstr("out.txt");
    // streambuf* strbuf;
    // strbuf = std::cout.rdbuf( ofstr.rdbuf() );

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
            for(auto c : r[i]){
                st.insert(c);
            }
            cnt[r[i][0]]++;
            if(r[i].size() > 1)is_zero[r[i][0]] = true;
        }
        vector<pair<ll, char>> temp;
        vector<char> ans(10);
        for(auto c : st){
            if(is_zero[c] == 0){
                ans[0] = c;
                cnt[c] = 0;
            }
        }
        for(auto itr : cnt){
            if(itr.second != 0)temp.emplace_back(itr.second, itr.first);
        }
        sort(all(temp), greater<pair<ll, char>>());
        reps(i,9)ans[i] = temp[i-1].second;
        Case(q);
        for(auto i : ans)cout << i;
        cout << endl;
    }
}