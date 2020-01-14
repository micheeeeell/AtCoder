#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define pb push_back
#define eb emplace_back
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
const ll MOD = 1e9+7;
const int n_max = 1e5+10;

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

int main(){
    ll n; cin >> n;
    using Pld = pair<ld,ld>;
    vector<Pld> xy(n);
    rep(i,n){
        ld x,y; cin >> x >> y;
        xy[i] = {x,y};
    }
    ld ans = numeric_limits<ld> :: max();
    auto cent = [](Pld A, Pld B, Pld C) -> Pld{
        ld a = A.first, b = A.second;
        ld c = B.first, d = B.second;
        ld e = C.first, f = C.second;
        ld aa = a * a;
        ld bb = b * b;
        ld cc = c * c;
        ld dd = d * d;
        ld ee = e * e;
        ld ff = f * f;

        ld py = ((e - a) * (aa + bb - cc - dd) - (c - a) * (aa + bb - ee- ff)) / (2.0 * (e - a)*(b - d) - 2.0 * (c - a) * (b - f));
        ld px;
        if(c == a) px = (2 * (b - f) * py - aa - bb + ee + ff) / (2.0 * (e - a));
        else px = (2 * (b - d) * py - aa - bb + cc + dd) / (2.0 * (c - a));
        return {px, py};
    };

    auto area = [](Pld A, Pld B, Pld C){
        ld x1 = A.first, y1 = A.second;
        ld x2 = B.first, y2 = B.second;
        ld x3 = C.first, y3 = C.second;
        x1 -= x3;
        y1 -= y3;
        x2 -= x3;
        y2 -= y3;
        return abs(x1*y2 - x2*y1);
    };

    

    if(n == 2){
        ld x = (xy[0].first + xy[1].first) / 2.0;
        ld y = (xy[0].second + xy[1].second) / 2.0;
        x = abs(x - xy[0].first);
        y = abs(y - xy[0].second);
        ans = sqrt(x * x + y * y);
        // assert(0);
    }
    else{

        bool ok = false;
        rep(i,n)rep(j,n)rep(k,n){
            if(i >= j)continue;
            if(j >= k)continue;
            if(area(xy[i], xy[j], xy[k]) == 0)continue;
            Pld center = cent(xy[i], xy[j], xy[k]);
            ld xt = center.first - xy[i].first;
            ld yt = center.second - xy[i].second;
            ld dist = sqrt(xt * xt + yt * yt);
            ld temp = 0;
            rep(l,n){
                ld x = center.first - xy[l].first;
                ld y = center.second - xy[l].second;
                ld dis = sqrt(x * x + y * y);
                chmax(temp, dis);
            }
            ok |= (temp == dist);
            // debug(i);debug(j);debug(k);
            // debug(temp);
            chmin(ans, temp);
        }
        // assert(ok);

        rep(i,n)rep(j,n){
            if(i >= j)continue;
            ld xc = (xy[i].first + xy[j].first) / 2.0;
            ld yc = (xy[i].second + xy[j].second) / 2.0;
            ld temp = 0;
            rep(k,n){
                ld x = xc - xy[k].first;
                ld y = yc - xy[k].second;
                chmax(temp, sqrt(x*x + y*y));
            }
            chmin(ans,temp);
        }
    }
    
    cout << fixed << setprecision(20);
    cout << ans << endl;
}