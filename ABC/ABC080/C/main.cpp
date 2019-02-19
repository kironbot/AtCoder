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
    ll n;
    cin >> n;
    ll f[200][10], p[200][20];
    rep(i, n) rep (j, 10) cin >> f[i][j];
    rep(i, n) rep (j, 11) cin >> p[i][j];
    ll ans = -(1<<30);
    rep(i, 1<<10) {
        if (i == 0) continue;
        ll tmp = 0;
        rep(j, n) {
            ll cnt = 0;
            rep(k, 10) {
                if ((i>>k & 1) && f[j][k] == 1) cnt++;
            }
            tmp += p[j][cnt];
        }
        chmax(ans, tmp);
    }
    cout << ans << endl;
}