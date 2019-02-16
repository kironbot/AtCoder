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
    ll n, m;
    cin >> n >> m;
    ll cost[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    vector<int> a(m);
    rep(i, m) cin >> a[i];

    string dp[11000];
    rep(i, 11000) dp[i] = "-";
    dp[0] = "";
    for (ll i = 0; i <= n; i++) {
        if (dp[i] == "-") continue;
        rep(j, m) {
            string b = dp[i] + (char)('0' + a[j]);
            if (dp[i+cost[a[j]]].size() < b.size() ) dp[i+cost[a[j]]] = b;
            else if (dp[i+cost[a[j]]].size() == b.size() ) {
                if (dp[i+cost[a[j]]] < b) dp[i+cost[a[j]]] = b;
            }
        }
    }
    cout << dp[n] << endl;
}