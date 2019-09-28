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
    for(int i = 0;i < sz-1;i++){cout << arr[i] << ' ';}
    cout << arr[sz-1] << endl;
}


int main(){
    ll n,k; cin >> n >> k;
    deque<ll> que;
    rep(i,n){
        ll tmp; cin >> tmp;
        que.push_back(tmp);
    }
    ll res = 0;
    rep(i,min(n+1,k+1)){
        rep(j,i+1){
            deque<ll> temp_que = que;
            set<ll> st;
            ll temp_val = 0;
            rep(jj,j){
                ll temp = temp_que.front();temp_que.pop_front();
                temp_val += temp;
                st.insert(temp);
            }
            rep(l,i-j){
                ll temp = temp_que.back();temp_que.pop_back();
                temp_val += temp;
                st.insert(temp);
            }
            auto itr = st.begin();
            ll len = st.size();
            rep(m,min(len, k-i)){
                if(itr == st.end())break;
                if(*itr < 0)temp_val -= *itr;
                itr++;
            }
            res = max(res, temp_val);
            st.clear();temp_que.clear();
            // print(i,j,temp_val);
        }
        
    }

    cout << res << endl;
    return 0;
}