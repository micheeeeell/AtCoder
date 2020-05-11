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
template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

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
        if (&a != &vec.back()) cout << "\n";
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

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    set<Pll> st;
    vector<ll> ans;
    rep(i,n){
        ll s,c; cin >> s >> c;
        if(st.empty()){
            st.insert(Pll(s, s + c));
            ans.emplace_back(s + c - 1);
            continue;
        }
        auto itr = st.lower_bound(Pll(s, -1));
        ll cnt = c, r = s;
        if(itr != st.begin()){
            itr--;
            if(itr->second >= s){
                s = itr->first;
                r = itr->second;
                auto itr2 = itr;
                itr++;
                st.erase(itr2);
            }
            else itr++;
        }
        ll r2 = -1;
        while(cnt){
            if(itr == st.end()){
                r += cnt;
                break;
            }
            if(itr->first - r > cnt){
                r += cnt;
                break;
            }
            if(itr->first - r == cnt){
                r = itr->second;
                r2 = itr->first;
                st.erase(itr);
                break;
            }
            if(itr->first - r < cnt){
                cnt -= itr->first - r;
                r = itr->second;
                auto itr2 = itr;
                itr++;
                st.erase(itr2);
            }
        }

        // debug(s);debug(r);debug(r2);
        st.insert(Pll(s, r));
        
        if(r2 == -1)ans.emplace_back(r - 1);
        else ans.emplace_back(r2 - 1);
    }

    print(ans);
}