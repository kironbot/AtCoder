#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <cmath>
#include <map>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    ll n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<ll> color(n), cnt(n);
    rep(i, m) {
        ll l, r;
        cin >> l >> r;
        l--;
        r--;
        for (ll i = l; i <= r; i++) color[i] = 1;
    }
    ll ans = 0;
    rep(i, n) {
        if (color[i] == 1) ans += a;
        else ans += b;
    }
    cout << ans << endl;
}
