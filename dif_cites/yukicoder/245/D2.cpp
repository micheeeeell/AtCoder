// #define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
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
const int n_max = 1e5+10;
#define int ll

template<typename Monoid>
struct SlidingWindowAggregation {
    using F = function< Monoid(Monoid, Monoid) >;

    stack< Monoid > front,back;
    stack< Monoid > sum_front;
    Monoid sum_back;
    const F f;
    const Monoid M1;
    SlidingWindowAggregation (const F f, const Monoid &M1) : f(f), M1(M1) {
        sum_front.push(M1);
        sum_back = M1;
    }

    void push(Monoid x) {
        back.push(x);
        sum_back = f(sum_back, x);
    }

    void pop() {
        if(front.empty()) {
            while(! back.empty()) {
                front.push(back.top());
                sum_front.push(f(front.top(), sum_front.top()));
                back.pop();
            }
            sum_back = M1;
        }
        assert(! front.empty());
        front.pop();
        sum_front.pop();
    }

    Monoid accumulate() const {
        if(front.size() + back.size() == 0)return 0;
        return f(sum_front.top(), sum_back);
    }
    
    bool empty() const {
        return front.empty() && back.empty();
    }

    size_t size() const {
        return front.size() + back.size();
    }
};

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    

    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    auto f = [](ll a, ll b){return gcd(a, b);};
    SlidingWindowAggregation<ll> swag(f, 0);
    ll left = 0, right = 0;
    ll ans = 0;
    for(;left < n; left++){
        while(right < n && gcd(swag.accumulate(), a[right]) > 1){
            swag.push(a[right++]);
        }

        ans += n - right;

        if(right == left) ++right;
        else swag.pop();
    }

    cout << ans << endl;
}