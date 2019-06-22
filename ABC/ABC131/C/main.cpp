#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define rep(i, a, n) for (ll i = (a); i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll e = c * d / __gcd(c, d);
    ll cnta = a-1 - (a-1) / c - (a-1) / d + (a-1) / e;
    ll cntb = b - b / c - b / d + b / e;
    cout << cntb - cnta << endl;
}
