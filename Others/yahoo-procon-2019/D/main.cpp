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
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> dp(5);
    rep(i, n) {
        dp[0] += a[i]; // 0

        if (a[i] == 0) dp[1] += 2; // even > 0
        else dp[1] += a[i] % 2;

        dp[2] += (a[i] + 1) % 2; // odd > 0

        if (a[i] == 0) dp[3] += 2; // even > 0
        else dp[3] += a[i] % 2;

        dp[4] += a[i]; // 0

        rep(k, 4) chmin(dp[k+1], dp[k]);
    }
    cout << dp[4] << endl;
}
