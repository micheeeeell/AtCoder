#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define pb push_back
#define eb emplace_back
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
const ll MOD = 1e9+7;
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


int main(){
    ll n,k; cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> ind(2*1e5+20,-1), next(n);
    rep(i,2){
        for(int j = n-1; 0 <= j; j--){
            if(ind[a[j]] != -1) next[j] = ind[a[j]];
            ind[a[j]] = j;
        }
    }
    vector<ll> bs(n,-1);
    ll pos = 0, cnt = 0, pre_cnt = 0;
    while(bs[pos] == -1 ) {
        bs[pos] = cnt;
        if(next[pos] > pos)cnt += next[pos] + 1 - pos ;
        else cnt += next[pos] + 1 + n - pos;
        if(n * k <= cnt)break;
        pos = next[pos] + 1;
        if(pos == n)pos = 0;
    }

    // print(next);
    // print(bs);
    // debug(cnt);debug(pos);
    vector<ll> ans;
    if(cnt < n*k){
        ll t = n*k - 1 - bs[pos];
        t %= (cnt - bs[pos]);
        // t += bs[pos];
        cnt = n*k-1 - t;
        while(true){
            bs[pos] = cnt;
            if(next[pos] > pos)cnt += next[pos] + 1 - pos ;
            else cnt += next[pos] + 1 + n - pos;
            if(n * k <= cnt)break;
            pos = next[pos] + 1;
            if(pos == n)pos = 0;
        }
        // cnt = t;
        // debug(cnt);
    }

    cnt = bs[pos];
    // debug(cnt);debug(pos);
    // pos++;
    // if(pos == n)pos = 0;
    bitset<200010> b(0);
    for(ll i = cnt; i < n*k; i++){
        if(b[a[pos]] == 0){
            ans.emplace_back(a[pos]);
            b[a[pos]] = 1;
        }
        else{
            while(b[a[pos]] == 1){
                ll t = ans.back();ans.pop_back();
                b[t] = 0;
            }
        }
        pos++;
        if(pos == n)pos = 0;
    }

    for(auto i : ans)cout << i << " ";
    cout << endl;

}