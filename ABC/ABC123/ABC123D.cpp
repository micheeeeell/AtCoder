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
const ll N = 1e9+7;
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


/*
int main(){
    int x,y; cin >> x >> y;
    int z,k; cin >> z >> k;
    priority_queue<ll> apq,bpq,cpq;
    vector<ll> a(x,LONG_MAX), b(y,LONG_MAX), c(z,LONG_MAX);
    rep(i,x){
        ll temp;cin >> temp;
        apq.push(temp);
    }
    rep(i,y){
        ll temp;cin >> temp;
        bpq.push(temp);
    }
    rep(i,z){
        ll temp;cin >> temp;
        cpq.push(temp);
    }
    ll a_max,b_max,c_max;
    a_max = apq.top();b_max = bpq.top();c_max = cpq.top();
    apq.pop();bpq.pop();cpq.pop();
    // print(a_max, b_max, c_max);
    assert(a_max < LONG_MAX);
    assert(b_max < LONG_MAX);
    assert(c_max < LONG_MAX);
    rep(i,x-1){
        ll temp = apq.top();apq.pop();
        a[i] = a_max - temp;
    }
    rep(i,y-1){
        ll temp = bpq.top();bpq.pop();
        b[i] = b_max - temp;
    }
    rep(i,z-1){
        ll temp = cpq.top();cpq.pop();
        c[i] = c_max - temp;
    }

    ll res = a_max + b_max + c_max;
    ll a_state = 0, b_state = 0, c_state = 0;
    rep(i,k){
        cout << res << "\n";
        ll temp_min = min(a[a_state], min(b[b_state], c[c_state]));
        if(a[a_state] == temp_min) a_state++;
        else if(b[b_state] == temp_min) b_state++;
        else c_state++;
        res -= temp_min;
    }
    return 0;
} 
*/

int main(){
    int x,y; cin >> x >> y;
    int z,k; cin >> z >> k;
    vector<ll> a(x), b(y), c(z);
    rep(i,x)cin >> a[i];
    rep(i,y) cin >> b[i];
    rep(i,z) cin >> c[i];
    sort(a.begin(), a.end(),greater<ll>());
    sort(b.begin(), b.end(),greater<ll>());
    sort(c.begin(), c.end(),greater<ll>());
    priority_queue<vector<ll> > pq;
    set<vector<ll> > st;
    int a_state = 0,b_state = 0, c_state = 0;
    ll res = a[a_state] + b[b_state] + c[c_state];
    vector<ll> start = {res, a_state, b_state, c_state};
    pq.push(start);
    st.insert(start);
    rep(i,k){
        vector<ll> temp = pq.top();pq.pop();
        cout << temp[0] << "\n";
        if(temp[1] < x-1){
            vector<ll> a_temp = {a[temp[1] + 1] + b[temp[2]] + c[temp[3]], temp[1] + 1, temp[2], temp[3]};
            if(st.insert(a_temp).second)pq.push(a_temp);
        }
        if(temp[2] < y-1){
            vector<ll> b_temp = {a[temp[1]] + b[temp[2] + 1] + c[temp[3]], temp[1], temp[2] + 1, temp[3]};
            if(st.insert(b_temp).second)pq.push(b_temp);
        }
        if(temp[3] < z-1){
            vector<ll> c_temp = {a[temp[1]] + b[temp[2]] + c[temp[3] + 1], temp[1], temp[2], temp[3] + 1};
            if(st.insert(c_temp).second)pq.push(c_temp);
        }
    }
    return 0;
}