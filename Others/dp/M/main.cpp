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
    const int mod = 1e9 + 7;
    int n, k;
    cin >> n >> k;
    vector<int> dp(k + 2);
    dp[0] = 1;
    rep(i, n) {
        vector<int> add_dp(k + 2);
        int x;
        cin >> x;
        for (int j = k; j >= 0; j--) {
            (add_dp[min(j + x + 1, k + 1)] += mod - dp[j]) %= mod;
            (add_dp[j] += dp[j]) %= mod;
        }
        for (int j = 1; j <= k; j++) {
            (add_dp[j] += add_dp[j - 1]) %= mod;
        }
        dp.swap(add_dp);
    }
    cout << dp[k] << endl;
}
