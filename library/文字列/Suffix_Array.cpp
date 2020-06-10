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

// Suffix Array ( Manber&Myers: O(n (logn)^2) )
// Suffix: 接尾辞
// SA: 文字列Sの接尾辞を辞書順に並べたもの
// LCP: SAのi番目の要素sa[i]について、sa[i]とsa[i+1]の接頭辞がどれだけ共通しているか
// LCPを用いることで任意の接尾辞同士の共通する接頭辞長を調べられる
// rank_sa: SAの逆引き配列  SA[i] = t -> rank_sa[t] = i
struct SuffixArray {
    string str;
    vector<int> sa;         // sa[i] : the starting index of the i-th smallest suffix (i = 0, 1, ..., n)
    vector<int> lcp;        // lcp[i]: the lcp of sa[i] and sa[i+1] (i = 0, 1, ..., n-1)
    inline int& operator [] (int i) {return sa[i];}
    
    SuffixArray(const string& str_) : str(str_) { buildSA(); calcLCP(); }
    void init(const string& str_) { str = str_; buildSA(); calcLCP(); }
    
    // build SA
    vector<int> rank_sa, tmp_rank_sa;
    struct CompareSA {
        int n, k;
        const vector<int> &rank;
        CompareSA(int n, int k, const vector<int> &rank_sa) : n(n), k(k), rank(rank_sa) {}
        bool operator()(int i, int j) {
            if (rank[i] != rank[j]) return (rank[i] < rank[j]);
            else {
                int rank_ik = (i + k <= n ? rank[i + k] : -1);
                int rank_jk = (j + k <= n ? rank[j + k] : -1);
                return (rank_ik < rank_jk);
            }
        }
    };
    void buildSA() {
        int n = (int)str.size();
        sa.resize(n+1), lcp.resize(n+1), rank_sa.resize(n+1), tmp_rank_sa.resize(n+1);
        for (int i = 0; i < n; ++i) sa[i] = i, rank_sa[i] = (int)str[i];
        sa[n] = n, rank_sa[n] = -1;
        for (int k = 1; k <= n; k *= 2) {
            CompareSA csa(n, k, rank_sa);
            sort(sa.begin(), sa.end(), csa);
            tmp_rank_sa[sa[0]] = 0;
            for (int i = 1; i <= n; ++i) {
                tmp_rank_sa[sa[i]] = tmp_rank_sa[sa[i - 1]];
                if (csa(sa[i - 1], sa[i])) ++tmp_rank_sa[sa[i]];
            }
            for (int i = 0; i <= n; ++i) rank_sa[i] = tmp_rank_sa[i];
        }
    }
    vector<int> rsa;
    // SparseTable<int> st;
    void calcLCP() {
        int n = (int)str.size();
        rsa.resize(n+1);
        for (int i = 0; i <= n; ++i) rsa[sa[i]] = i;
        lcp.resize(n+1);
        lcp[0] = 0;
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            int pi = sa[rsa[i] - 1];
            if (cur > 0) --cur;
            for (; pi + cur < n && i + cur < n; ++cur) {
                if (str[pi + cur] != str[i + cur]) break;
            }
            lcp[rsa[i] - 1] = cur;
        }
        // st.init(lcp);
    }

    // sparce table を組み合わせることによって任意のi,jについて、lcp(i,j) := i,jの共通接頭辞長が計算できる
    // セグメント木でも可能（RMQ）
    // calc lcp
    // int getLCP(int a, int b) {          // lcp of str.sutstr(a) and str.substr(b)
    //     return st.get(min(rsa[a], rsa[b]), max(rsa[a], rsa[b]));
    // }

};

int main(){
    string s = "abracadabra";

    // Suffix Array 構築
    SuffixArray SA(s);

    cout << "Suffix Array" << endl;
    cout << SA.sa.size() << endl << endl;
    rep(i,SA.sa.size()){
        cout << SA[i] << "\t";
        cout << s.substr(SA[i]) << endl;
    }
    cout << endl;

    cout << "LCP array" << endl;
    // vector<int> lcp = SA.get_LCP_arr();
    cout << SA.lcp.size() << endl;
    rep(i,SA.lcp.size()){
        cout << SA.lcp[i] << " ";
    }
    cout << endl;

    cout << "rank" << endl;
    cout << SA.rank_sa.size() << endl;
    for(auto &i : SA.rank_sa) cout << i << " ";
    cout << endl;
}