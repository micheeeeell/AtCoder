#include<bits/stdc++.h>
typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
using namespace std;

int main() {

    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<pair<int, int>> coor(N);
    for (int i = 0; i < N; i++) cin >> coor[i].first >> coor[i].second;

    map<pair<int, int>, int> memo;
    for (const auto &e1 : coor) {
        for (const auto &e2 : coor) {
            memo[{e1.first - e2.first, e1.second - e2.second}]++;
        }
    }

    int ans = 0;
    for (const auto &e : memo) {
        if (e.first.first != 0 || e.first.second != 0) {
            ans = max(ans, e.second);
        }
    }

    ans = N - ans;
    cout << ans << "\n";

    return 0;
}