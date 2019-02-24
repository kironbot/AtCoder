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
    ll a, b, q;
    cin >> a >> b >> q;
    vector<ll> s(a), t(b);
    rep(i, a) cin >> s[i];
    rep(i, b) cin >> t[i];

    const ll INF = 1LL<<60;
    s.emplace(s.begin(), -INF);
    s.emplace_back(INF);
    t.emplace(t.begin(), -INF);
    t.emplace_back(INF);

    rep(i, q) {
        ll ans = 1LL<<60;
        ll x;
        cin >> x;
        ll ia = upper_bound(s.begin(), s.end(), x) - s.begin();
        ll ib = upper_bound(t.begin(), t.end(), x) - t.begin();

        rep(j, 2) {
            rep(k, 2) {
                chmin(ans, abs(x-s[ia-j]) + abs(s[ia-j] - t[ib-k]));
                chmin(ans, abs(x-t[ib-k]) + abs(t[ib-k] - s[ia-j]));
            }
        }
        cout << ans << endl;
    }
}
