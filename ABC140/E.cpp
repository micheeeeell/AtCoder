#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(int i = 0; i < x; i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
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
    for(int i = 0;i < sz-1;i++){
        cout << arr[i] << " ";
    }
    cout << arr[sz-1] << endl;
}


int main(){
    ll n; cin >> n;
    vector<ll> p(n);
    vector<ll> p_num(n);
    rep(i,n){
        cin >> p[i];
        p_num[p[i]-1] = i+1;//one-based
    }
    multiset<ll> st;
    st.insert(0);st.insert(0);
    st.insert(n+1);st.insert(n+1);
    vector<ll> c(n);
    for(ll i = n-1;0 <= i;i--){
        st.insert(p_num[i]);
        // auto st_itr = st.begin();
        // rep(i,st.size()){
        //     cout << *st_itr << " ";
        //     st_itr++;
        // }
        // cout << endl;
        auto itr = st.lower_bound(p_num[i]);
        itr--;itr--;
        ll num[5];
        rep(i,5){
            num[i] = *itr;
            itr++;
        }
        // print(num);
        c[i] = (num[1] - num[0]) * (num[3] - num[2]) + (num[2] - num[1]) * (num[4] - num[3]);
    }

    ll ans = 0;
    rep(i,n){
        ans += (i+1) * c[i];
    }
    // print(p_num);
    // print(c);

    cout << ans << endl;
    return 0;
}