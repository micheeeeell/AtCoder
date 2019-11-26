#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(int i = 0; i < (int)(x); i++)
#define pb push_back
#define mp make_pair
#define debug(x) cerr << #x << ": " << (x) << "\n";
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
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

template<typename T>
void print(T &arr){
    ll sz = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0;i < sz-1;i++){cout << arr[i] << ' ';}
    cout << arr[sz-1] << endl;
}


ll get_sum(vvl &sum, ll xs, ll ys, ll xe, ll ye){
    ll res;
    res = sum[xe][ye] - sum[xe][ys] - sum[xs][ye] + sum[xs][ys];
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll n,k; cin >> n >> k;
    vector<ll> x(n),y(n);
    map<ll,ll> x_mp,y_mp,x_mp_rev,y_mp_rev;
    set<ll> x_st,y_st;
    rep(i,n){
        cin >> x[i] >> y[i];
        x_st.insert(x[i]);
        y_st.insert(y[i]);
    }
    ll cnt = 0;
    for(auto itr = x_st.begin();itr != x_st.end();++itr){
        x_mp[cnt] = *itr;
        x_mp_rev[*itr] = cnt++;
    }
    // cout << x_mp[1] << endl;
    cnt = 0;
    for(auto itr = y_st.begin();itr != y_st.end();++itr){
        y_mp[cnt] = *itr;
        y_mp_rev[*itr] = cnt++;
    }
    ll x_n = x_st.size(), y_n = y_st.size();

    vvl a(x_n,vector<ll>(y_n,0));
    vvl sum(x_n+1,vector<ll>(y_n+1,0));
    rep(i,n){
        ll xt = x_mp_rev[x[i]], yt = y_mp_rev[y[i]];
        a[xt][yt]++;
    }
    rep(i,x_n)rep(j,y_n){
        sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j] + a[i][j];
    }

    ll res = LLONG_MAX;
    rep(i,x_n+1)rep(ii,x_n+1){
        rep(j,y_n+1)rep(jj,y_n+1){
            if(ii <= i)continue;
            if(jj <= j)continue;
            ll temp = get_sum(sum,i,j,ii,jj);
            if(k <= temp){
                // ma = temp;
                debug(temp);
                res = min(res,(x_mp[ii-1]-x_mp[i]) * (y_mp[jj-1]-y_mp[j]));
            }
        }
    }

    // print(sum);

    cout << res << endl;
    
}