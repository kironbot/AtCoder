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
    ll w, h, x, y;
    cin >> w >> h >> x >> y;

    ll cnt = 0;
    if (2*x ==w && 2*y == h) cnt = 1;

    cout.precision(20);
    cout << (double) w * h / 2.0 << " " << cnt << endl;
}
