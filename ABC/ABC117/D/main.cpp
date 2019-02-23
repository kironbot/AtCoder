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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll dp[100][2];
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    rep(d, 50) {
        ll mask = 1LL<<(50-d-1);
        ll num = 0;
        rep(i, n) if (a[i] & mask) num++;

        ll cost0 = mask * num;
        ll cost1 = mask * (n - num);

        if (dp[d][1] != -1) chmax(dp[d+1][1], dp[d][1] + max(cost0, cost1));

        if (dp[d][0] != -1) if (k & mask) chmax(dp[d+1][1], dp[d][0] + cost0);

        if (dp[d][0] != -1) {
            if (k & mask) chmax(dp[d+1][0], dp[d][0] + cost1);
            else chmax(dp[d+1][0], dp[d][0] + cost0);
        }
    }
    ll ans = 0;
    chmax(ans, dp[50][0]);
    chmax(ans, dp[50][1]);
    cout << ans << endl;
}
