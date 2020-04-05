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
    print(p.first, p.second);
}

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

int main(){
    ll n,k,c; cin >> n >> k >> c;
    string s;cin >> s;
    vector<ll> day(n+1);
    rrep(i,n){
        chmax(day[i], day[i+1]);
        chmax(day[i], day[min(n, i + c + 1)] + (s[i] == 'o'));
    }
    vector<ll> rem_day(n+1), num(n+1);
    reps(i,n){
        rem_day[i] = max(rem_day[i-1] - 1, 0LL);
        num[i] = num[i-1];
        if(s[i-1] == 'o' && rem_day[i-1] == 0){
            num[i] = num[i-1]+1;
            rem_day[i] = c;
        }
    }
    // print(day); 
    // print(num);
    // print(rem_day);
    vector<ll> ans;
    rep(i,n){
        if(s[i] != 'o')continue;
        if(rem_day[i] == 0){
            if(num[i] + day[i+1] < k)ans.emplace_back(i+1);
        }
    }

    print(ans);
}