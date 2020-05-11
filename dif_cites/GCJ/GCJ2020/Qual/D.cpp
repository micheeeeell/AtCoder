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
const int n_max = 110;

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


int query(int x){
    cout << x + 1 << endl;
    int res; cin >> res;
    return res;
}
void Case(int x){
    cout << "Case #" << x + 1 << ": ";
}

void ANS(vector<ll> &ans, int status){
    if(status == 0)print(ans);
    if(status == 1){
        for(auto i : ans){
            cout << (i ^ 1);
        }
        cout << endl;
    }
    if(status == 2){
        reverse(all(ans));
        print(ans);
    }
    if(status == 3){
        reverse(all(ans));
        for(auto i : ans){
            cout << (i ^ 1);
        }
        cout << endl;
    }
}
int main(){
    ll t,b; cin >> t >> b;
    rep(k, t){
        vector<ll> ans(b, -1);
        ll cnt = 0;
        ll query_cnt = 0;
        Pll p = {-1, -1};
        ll status = 0;
        while (cnt < b)
        {
            if(query_cnt / 10 == 0){
                rep(i,5){
                    ans[i] = query(i);
                    ans[b - i - 1] = query(b - i - 1);
                    if(ans[i] == ans[b - i - 1]){
                        if(p.first == -1)p.first = i;
                    }
                    if(p.second == -1 && ans[i] != ans[b- i - 1])p.second = i;
                    cnt += 2;
                    query_cnt += 2;
                }
                // debug(ans);
                continue;
            }

            if(p.first == -1){
                Pll pt = {query(b - p.second - 1), query(p.second)};
                if(ans[p.second] == pt.second){
                    status = 0;
                    rep(i,4){
                        if(ans[(cnt/2) + i] == -1)ans[(cnt / 2) + i] = query((cnt / 2) + i);
                        if(ans[b-1-(cnt/2)-i] == -1)ans[b - 1 - (cnt / 2) - i] = query(b - 1 - (cnt / 2) - i);
                        if(p.first == -1 && ans[(cnt/2) + i] == ans[b-1 - (cnt/2) - i])p.first = (cnt/2) + i;
                    }
                    cnt += 8;
                    query_cnt + 10;
                }
                else{
                    status = 1;
                    rep(i,4){
                        if(ans[(cnt/2) + i] == -1)ans[(cnt / 2) + i] = query((cnt / 2) + i) ^ 1;
                        if(ans[b-1-(cnt/2)-i] == -1)ans[b - 1 - (cnt / 2) - i] = query(b - 1 - (cnt / 2) - i) ^ 1;
                        if(p.first == -1 && ans[(cnt/2) + i] == ans[b-1 - (cnt/2) - i])p.first = (cnt/2) + i;
                    }
                    cnt += 8;
                    query_cnt + 10;
                }
            }
            else if(p.second == -1){
                Pll pt = {query(p.second), query(b - p.second - 1)};
                if(ans[p.first] == pt.first){
                    status = 0;
                    rep(i,4){
                        if(ans[(cnt/2) + i] == -1)ans[(cnt / 2) + i] = query((cnt / 2) + i);
                        if(ans[b-1-(cnt/2)-i] == -1)ans[b - 1 - (cnt / 2) - i] = query(b - 1 - (cnt / 2) - i);
                        if(p.second == -1 && ans[(cnt/2) + i] != ans[b-1 - (cnt/2) - i])p.second = (cnt/2) + i;
                    }
                    cnt += 8;
                    query_cnt + 10;
                }
                else{
                    status = 1;
                    rep(i,4){
                        if(ans[(cnt/2) + i] == -1)ans[(cnt / 2) + i] = query((cnt / 2) + i) ^ 1;
                        if(ans[b-1-(cnt/2)-i] == -1)ans[b - 1 - (cnt / 2) - i] = query(b - 1 - (cnt / 2) - i) ^ 1;
                        if(p.second == -1 && ans[(cnt/2) + i] != ans[b-1 - (cnt/2) - i])p.second = (cnt/2) + i;
                    }
                    cnt += 8;
                    query_cnt + 10;
                }

            }
            else{
                Pll pt = {query(p.first), query(p.second)};
                if(pt.first == ans[p.first] && pt.second == ans[p.second]){
                    status = 0;
                    rep(i,4){
                        if(ans[(cnt/2) + i] == -1)ans[(cnt / 2) + i] = query((cnt / 2) + i);
                        if(ans[b-1-(cnt/2)-i] == -1)ans[b - 1 - (cnt / 2) - i] = query(b - 1 - (cnt / 2) - i);
                    }
                    cnt += 8;
                    query_cnt += 10;
                }
                if(pt.first != ans[p.first] && pt.second != ans[p.second]){
                    status = 1;
                    rep(i,4){
                        if(ans[(cnt/2) + i] == -1)ans[(cnt / 2) + i] = query((cnt / 2) + i) ^ 1;
                        if(ans[b-1-(cnt/2)-i] == -1)ans[b - 1 - (cnt / 2) - i] = query(b - 1 - (cnt / 2) - i) ^ 1;                        
                    }
                    cnt += 8;
                    query_cnt += 10;
                }
                if(pt.first == ans[p.first] && pt.second != ans[p.second]){
                    status = 2;
                    rep(i,4){
                        if(ans[(cnt/2) + i] == -1)ans[(cnt / 2) + i] = query(b - 1 - (cnt / 2) - i);
                        if(ans[b-1-(cnt/2)-i] == -1)ans[b - 1 - (cnt / 2) - i] = query((cnt / 2) + i);                        
                    }
                    cnt += 8;
                    query_cnt += 10;
                    status = 2;
                    rep(i,4){
                        if(ans[(cnt/2) + i] == -1)ans[(cnt / 2) + i] = query(b - 1 - (cnt / 2) - i);
                        if(ans[b-1-(cnt/2)-i] == -1)ans[b - 1 - (cnt / 2) - i] = query((cnt / 2) + i);                        
                    }
                    cnt += 8;
                    query_cnt += 10;
                }
                if(pt.first != ans[p.first] && pt.second == ans[p.second]){
                    status = 3;
                    rep(i,4){
                        if(ans[(cnt/2) + i] == -1)ans[(cnt / 2) + i] = query(b - 1 - (cnt / 2) - i) ^ 1;
                        if(ans[b-1-(cnt/2)-i] == -1)ans[b - 1 - (cnt / 2) - i] = query((cnt / 2) + i) ^ 1;                        
                    }
                    cnt += 8;
                    query_cnt += 10;
                }
            }
            // debug(ans);
        }
        // debug(status);
        // Case(k);
        ANS(ans, status);
        char result; cin >> result;
        // cout << std::flush;
    }
    return 0;
}