#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
// #include <boost/algorithm/searching/boyer_moore.hpp>
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

int find_substring(string str, string pattern) {

	// Step 0. Should not be empty string
	if( str.size() == 0 || pattern.size() == 0)
		return -1;

	// Step 1. Compute failure function
	int failure[pattern.size()];
	std::fill( failure, failure+pattern.size(), -1);

	for(int r=1, l=-1; r<pattern.size(); r++) {

		while( l != -1 && pattern[l+1] != pattern[r])
			l = failure[l];

		// assert( l == -1 || pattern[l+1] == pattern[r]);
		if( pattern[l+1] == pattern[r])
			failure[r] = ++l;
	}

	// Step 2. Search pattern
	int tail = -1;
	for(int i=0; i<str.size(); i++) {

		while( tail != -1 && str[i] != pattern[tail+1])
			tail = failure[tail];

		if( str[i] == pattern[tail+1])
			tail++;

		if( tail == pattern.size()-1)
			return i - tail;
	}

	return -1;
}

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

vector<int> z(string s){
    int len = s.size();
    vector<int> res(len);
    res[0] = len;
    int i = 1, j = 0;
    while(i < len){
        while(i+j < len && s[j] == s[i+j]) ++j;
        res[i] = j;
        if(j == 0){ ++i; continue;}
        int k = 1;
        while(i+k < len && k+res[k] < j){
            res[i+k] = res[k], ++k;
        }
        i += k; j -= k;
    }
    rep(i,len){
        res[i] = min(res[i], i);
    }
    return res;
}

int main(){
    // int n; cin >> n;
    // string s;cin >> s;
    int n = 5000;
    string s;
    rep(i,n){
        s += 'a';
    }

    clock_t start = clock();
    // vector<int> num[26];
    // rep(i,n){
    //     int temp = s[i]-'a';
    //     num[temp].push_back(i);
    // }

    // int res = 0;
    // rep(i,n){
    //     int temp = s[i]-'a';
    //     rep(j,num[temp].size()){
    //         if(num[temp][j] <= i)continue;
    //         int k = 0;
    //         while(s[i+k] == s[num[temp][j]+k] && k < num[temp][j]-i){
    //             k++;
    //         }
            
    //         res = max(res, k);
    //     }
    // }
    // cout << res << endl;


    // ll res = 0;
    // rep(i,n-1){
    //     rep(j,(n-i)/2+1){
    //         if(!j)continue;
    //         string judge = s.substr(i,j);
    //         ll len = judge.size();
    //         string rest = s.substr(i+j);
    //         // cout << judge << " " << rest << endl;
    //         // print(i,j,judge,rest,find_substring(rest, judge));
    //         if(find_substring(rest, judge) == -1)break;
    //         res = max(res,len);
    //     }
    // }

    // cout << res << endl;



    // unordered_map<string,int> mp;

    // ll res = 0;
    // rep(i,n){
    //     string judge;
    //     rep(j,n-i){
    //         // string judge = s.substr(i,j-i+1);
    //         judge += s[i+j];
    //         ll len = judge.size();
    //         // string rest = s.substr(i+j);
    //         // print(i,j,judge,mp[judge]);
    //         if(mp[judge] == 0)mp[judge] = i+len;
    //         else if(mp[judge] < i+1)res = max(res,len);
    //     }
    // }
    // cout << res << endl;

    ll ans = 0;
    rep(i,n){
        vector<int> vec = z(s.substr(i));
        // auto itr = vec.begin();itr++;
        ll temp = *max_element(vec.begin(), vec.end());
        ans = max(ans,temp);
    }
    cout << ans << endl;
    clock_t end = clock();

    const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    printf("time %lf[ms]\n", time);
    return 0;
}