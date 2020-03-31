#include <cassert>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <numeric>
#include <algorithm>
using namespace std;
using lint = long long;
constexpr int MOD = 1000000007, INF = 1010101010;
constexpr lint LINF = 1LL << 60;
template <class T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
	for (const auto &e : vec) os << e << (&e == &vec.back() ? "\n" : " ");
	return os;
}
#ifdef _DEBUG
template <class T>
void dump(const char* str, T &&h) { cerr << str << " = " << h << "\n"; };
template <class Head, class... Tail>
void dump(const char* str, Head &&h, Tail &&... t) {
	while (*str != ',') cerr << *str++; cerr << " = " << h << "\n";
	dump(str + (*(str + 1) == ' ' ? 2 : 1), t...);
}
#define DMP(...) dump(#__VA_ARGS__, __VA_ARGS__)
#else
#define DMP(...) ((void)0)
#endif

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



int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<vector<int>> edges(N);
	vector<int> cnt(N), ecnt(N);
	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		edges[u].emplace_back(v);
		edges[v].emplace_back(u);
		cnt[u]++, cnt[v]++;
		ecnt[u]++, ecnt[v]++;
	}
	vector<int> a(N);
	for (int i = 0; i < N; i++) cin >> a[i];
	for (int i = 0; i < N; i++) {
		int b;
		cin >> b;
		a[i] -= b;
	}
	queue<int> root;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (cnt[i] == 1) {
			root.emplace(i);
		}
	}
    // print(a);
	DMP(cnt);
	vector<int> cost(N, 1);
	while (!root.empty()) {
		int now = root.front();
		root.pop();
		cnt[now]--;
		DMP(now);
		int next = -1;
		for (const auto &e : edges[now]) {
			if (cnt[e] != 0) {
				next = e;
			}
		}
		DMP(next);
		if (next == -1) break;
		DMP(a, cost);
		if (a[now] > 0) {
			ans += cost[now] * a[now];
			a[next] += a[now];
		}
		else {
			ans -= cost[next] * a[now];
			for (const auto &e : edges[next]) {
				if(cnt[e] > 0) a[e] -= a[now];
			}
			a[next] += a[now] * cnt[next];
		}
        a[now] = 0;
		cost[next] += cost[now];
        cnt[next]--;
        if (cnt[next] == 1) root.emplace(next);

        // print(now,next,ans);
        // print(a);
        // print(cnt);
        // print(cost);
        // print();
		DMP(ans);
	}
	DMP(a, cnt);
	cout << ans << "\n";
	return 0;
}
