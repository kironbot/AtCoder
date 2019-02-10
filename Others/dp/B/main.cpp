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
    vector<ll> h(n);
    rep(i, n) cin >> h[i];
    vector<ll> dp(n);
    dp[0] = 0;
    for (ll i = 1; i < n; i++) {
        dp[i] = 1LL<<60;
        for (ll j = 1; j <= k; j++) {
            if (i-j >= 0) chmin(dp[i], dp[i-j] + abs(h[i] - h[i-j]));
        }
    }
    cout << dp[n-1] << endl;
}
